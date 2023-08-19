# Agile Lens Utility Nodes Plugin

## NOTE: "main" is the 5.X branch, "4_27" is for 4.X.

## Setup:

### Manual install
![image](https://github.com/AgileLens/AgileLensUtilityNodes/assets/72276215/289903be-b362-40d4-90f6-fe0c327d1406)
1. Download the repo source code folder (see above)
2. Extract the folder to your projects /Plugins directory
3. Rename the folder and remove "-main", the folders full name should be "AgileLensUtilityNodes"
4. Launch project

### Add as a submodule to existing project:
1. Navigate to proejct /Plugins folder
2. Add the submodule: ```git submodule add https://github.com/AgileLens/AgileLensUtilityNodes.git```
3. Navigate back to root project directory: ```cd ..```
4. Commit: ```git commit -am "added Agile Lens Utility Nodes submodule"```
5. Push: ```git push```
6. Run : ```git submodule update --remote --merge```

### Update submodule:
1. Navigate to projects folder
2. Run update command: ```git submodule update --remote --merge```

___

## Nodes

#### Set Quality Settings -
  Sets the various console variables listed as the input fields based on the values the user inputs.  Hover over input pins for value ranges.
  
![image](https://github.com/AgileLens/AgileLensUtilityNodes/assets/72276215/3561ebe3-ec63-4bb9-af8e-28cbd804fea1)

---
### Debug Subsystem and Debug Print String
#### Debug Subsystem - 
  A simple subsystem that runs and contains a bool "bDebuggingIsEnabled".
#### Debug Print String -
  Identical to the normal Print String node, but looks to the Debug Subsystem to see if it should fire.
  
![image](https://github.com/AgileLens/AgileLensUtilityNodes/assets/72276215/0e36c39a-b67e-4b00-a957-e63ae24a705c)

___

## RefreshSourceCode.bat
Batch file that will delete the Binaries/Intermediate/Saved folders, regenerate the project solution, and then build the project.
1. Place the .bat file in the root of your project folder (where the .uproject is located)
2. Run .bat file
