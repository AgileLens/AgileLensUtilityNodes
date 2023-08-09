@echo off


echo ----Starting source code cleanup and regenerate...
echo ----Looking for Unreal Version Selector and Build.bat registry key and path...
echo. 
FOR /F "tokens=2* skip=2" %%a in ('reg query "HKEY_CLASSES_ROOT\Unreal.ProjectFile\shell\rungenproj"') do set "UVS=%%b"
FOR /F "tokens=2* skip=2" %%a in ('reg query "HKEY_LOCAL_MACHINE\SOFTWARE\EpicGames\Unreal Engine\5.2"') do set "ENGINEPATH=%%b"

set "UPROJECTPATTERN=*.uproject"
set "UPROJECTFILE="

echo ----Looking for .uproject file...
for /f "delims=" %%i in ('dir /b /a-d "%UPROJECTPATTERN%" 2^>nul') do (
    set "UPROJECTFILE=%%i"
    goto :Found
)

:Found
if defined UPROJECTFILE (
    echo File "%UPROJECTPATTERN%" found: %UPROJECTFILE%
) else (
    echo File "%UPROJECTPATTERN%" not found.
)

echo ----Removing Binaries/Intermediat/Saved
rmdir /s /q %cd%\Binaries
rmdir /s /q %cd%\Intermediate
rmdir /s /q %cd%\Saved
echo.

echo ----Executing: %UVS% -projectfiles "%cd%\%UPROJECTFILE%
echo ----Please wait while solution generates...
start /W "" %UVS% -projectfiles "%cd%\%UPROJECTFILE%"
if ERRORLEVEL 1 (
	echo. & echo "---Solution generation failed!"
) else (
	echo. & echo ---Solution generated, moving on to build... & goto build 
)

:build
echo.
echo ----Please wait, starting build...

echo.
set COMMAND= dotnet "%ENGINEPATH%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll" %UPROJECTFILE:~0,-9%Editor Win64 Development -Project="%cd%\%UPROJECTFILE%" -WaitMutex -FromMsBuild
echo ----Executing: %COMMAND%
echo.
cmd /wait /k %COMMAND%

if ERRORLEVEL 1 (
	echo. & echo ----Build failed! & pause & exit
) else (
	echo ----Build successful, Done! & goto end
)

:end
echo.
echo Press "Y" to launch the project, or "N" close the window
choice /c yn /n
if %errorlevel%==1 goto launch
if %errorlevel%==2 exit

:launch
start %cd%\%UPROJECTFILE%
