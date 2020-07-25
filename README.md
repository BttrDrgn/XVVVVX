# XVVVVX
Xbox Original port of VVVVVV  

## Cloning this repo
- This repo contains git submodules, meaning that it needs to clone certain other git repo's. 
  - To clone this repo succesfully, please use the **--recursive** flag: `git clone --recursive https://github.com/BttrDrgn/XVVVVX`
  
## Adding submodules to this repo
To make it easier for others to download and use this repo, you may add submodules like such:
- `git submodule add -b [branch] [repo_url] deps/[repo_name]`
  - The submodule add command for libSDL2x was `git submodule add -b master --name libSDL2x https://github.com/marty28/libSDL2x deps/libSDL2x`.
  The root of the git repo will be cloned into the path that you provided!
- When you already cloned this repo, and want download the submodules. You can use
  - `git submodule update --init --recursive` to so do. (or `git submodule update --init --recursive -j 8` if you've got super fast internet)
- When you want to pull the changes for the root repo and for all the submodules, use:
  - `git pull --recurse-submodules`
- When you only want to pull the changes of the submodules:
  - `git submodule update --remote`
- Using submodules allows one to more easily patch the submodule whilest preserving the original:
  - To get a .patch file after editing the sources of your submodule, commit the changes you made using `git commit -a -m "message"`
    - Then use `git format-patch -s -n -1 HEAD --stdout >> ..\..\..\patches\[REPO_NAME].patch` to append your changes to the patch file. Make sure that you actually use >>, otherwhise the file gets overwritten!
  - To apply a single patch, go to the root directory of the submodule and run `git apply ..\..\..\patches\[REPO_NAME].patch`
  - To apply all patches, execute `git submodule foreach 'echo Applying patch $toplevel/patches/$name.patch && dos2unix $toplevel/patches/$name.patch && git apply $toplevel/patches/$name.patch'`
  

## Todo
- Optimize the rendering. Maybe convert SDL2 over to DirectX so it will be hardware accelerated.  
- Completely redo Music and BinaryBlob to not require dependencies and use native Xbox libraries.
- Comment and Code cleanup (a LOT of audio related functions are commeted and need to be looked at)
- Maybe get the editor working. Right now its just Play Edition.
- Load the base game maps in a way that the Visual Studio 2003 compiler wants
  - (Visual Studio 2003 compiler is limited to 63 conditional statements at a time)
- The script loader causes issues. Also needs same treatment as loading base game maps.

## Port Info
- Based on the Homebrew Switch Port which is a fork of the original  
- Links: [Original Source](https://github.com/TerryCavanagh/VVVVVV) -🍴> [Homebrew Switch Port](https://github.com/NicholeMattera/NX-VVVVVV)  

## Original Source Info
- [Original Readme](https://github.com/TerryCavanagh/VVVVVV/blob/master/README.md)
- [Licensing Info](https://github.com/TerryCavanagh/VVVVVV/blob/master/LICENSE.md)

# Playing the Game
## Startup
- Download the latest binaries from the [releases](https://github.com/BttrDrgn/XVVVVX/releases/latest) section on the github.
- Your first launch WILL crash, go back to the game files and read the README.txt
- After reading the README, you will notice you have to extract your game files into your games directory
  - Free game files can be downloaded here https://thelettervsixtim.es/makeandplay/data.zip
  
## Getting Levels
- For levels, you will need to extract the levels folder into "D:\\user\\levels" or download them online
  - User levels can be downloaded here https://distractionware.com/forum/index.php?board=7.0 or elsewhere

## Getting Music
- For music, you will need to a find proper WAV format soundtrack or dump the original OGG one and convert it
  - Only WAV will play for now as the native Xbox library does not support OGG


# Building and Setup Info
## Notes
- Visual Studio .NET 2003 is required!
- The Visual Studio project paths are currently set to my directories and will need to be changed before compiling.

## Dependencies
- [libSDL2x](https://github.com/marty28/libSDL2x) (port by marty28 aka BDC)
- Included but needed to be built and linked to the project:
  - Physfs (on its way to being deprecated from the project)
  - Lodepng
  - Tinyxml
  
## Building
Load the project and just build it. Simple!  
(make sure you have paths and dependencies correct and at the ready)
