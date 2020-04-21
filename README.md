# XVVVVX
Xbox Original port of VVVVVV  

## Todo
- Optimize the rendering. Maybe convert SDL2 over to DirectX so it will be hardware accelerated.  
- Convert SDL Mixer to DirectSound as its easier and native to the Xbox.
- Completely redo SoundSystem and Music (including BinaryBlob) to not require dependencies and use native Xbox libraries.
- Comment and Code cleanup (a LOT of audio related functions are commeted and need to be looked at)
- Maybe get the editor working. Right now its just Play Edition.
- Load the base game maps in a way that the Visual Studio 2003 compiler wants
  - (Visual Studio 2003 compiler is limited to 63 conditional statements at a time)


## Port Info
- Based on the Homebrew Switch Port which is a fork of the original  
- Links: [Original Source](https://github.com/TerryCavanagh/VVVVVV) -🍴> [Homebrew Switch Port](https://github.com/NicholeMattera/NX-VVVVVV)  

## Original Source Info
- [Original Readme](https://github.com/TerryCavanagh/VVVVVV/blob/master/README.md)
- [Licensing Info](https://github.com/TerryCavanagh/VVVVVV/blob/master/LICENSE.md)

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
