# Agile Lens Utility Nodes Plugin

## NOTE: "main" is the 5.x branch, "4_27" is for 4.x.

## Setup:

### Manual install

1. Download the repo source code folder (click the green "Code" button above -> "Download Zip")
2. Extract the folder to your projects /Plugins directory (make if it does not exist)
3. Rename the folder to remove the appended branch name, the folders full name should be "AgileLensUtilityNodes"
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


## Things to Try

1. **Install as a git submodule:** From your project's `Plugins/` folder, run `git submodule add https://github.com/AgileLens/AgileLensUtilityNodes.git` — rebuild and the nodes appear immediately. No UE Marketplace required.
2. **Find the nodes in Blueprint:** Open any Blueprint graph → right-click → search **Agile Lens** — all custom utility nodes appear under the `Agile Lens` category, ready to drop into any graph.
3. **Choose the right branch for your engine version:** `main` targets UE 5.x; `4_27` targets UE 4.27. Switch inside the submodule folder: `git checkout 4_27`.
4. **Update to the latest nodes:** From your project root, run `git submodule update --remote --merge` — pulls any new nodes Agile Lens adds without requiring a reinstall or re-clone.
5. **Explore the source:** Browse the `Source/` folder — each `.h` file in the public includes maps to a category of Blueprint function libraries. The file names correspond to the Blueprint node category names.

