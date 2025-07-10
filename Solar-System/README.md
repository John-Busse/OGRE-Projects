# OGRE Solar System
## Rendering a solar system in OGRE

## Project plans
#### Entity Manager
- ~~Entity Manager class~~ COMPLETE 7/8/25
- ~~Entity class representing each object tracking scale, name, rotation speed, orbit speed, and number of satellites~~  COMPLETE 7/9/25
- ~~.mesh files for all planets, rings, and moons~~ COMPLETE 6/25/25
#### JSON file
- ~~Use a JSON file with basic planet information for the sun, planets, and pluto~~  COMPLETE 7/9/25
- Render all objects
- Add rings for Jupiter, Saturn, Uranus, and Neptune
- Add major moons of Earth, Mars, Jupiter, Saturn, Uranus, Neptune, and Pluto
- Keep consistent scale
#### Lighting/Shading
- Point light under sun (or replacing sun mesh?)
#### Background
- ~~load in a space skybox~~ COMPLETE 7/9/25
- custom space skybox
#### Controls
- ~~Input Manager class~~ COMPLETE 7/5/25
- ~~Zoom in and out~~ (W/S) COMPLETE 7/9/25
- ~~Rotate horizontally~~ (A/D) COMPLETE 7/9/25
- ~~Rotate vertically~~ (R/F) COMPLETE 7/9/25
- ~~Planet selection~~ (0-9) COMPLETE 7/9/25
- ~~Reset view angle~~ (Space) COMPLETE 7/9/25
- ~~Adjust simulation speed~~ (left/right arrows) COMPLETE 7/9/25
#### UI
- ~~UI Manager class~~ COMPLETE 7/9/25
- ~~Introduction text box with 'exit application' controls~~  COMPLETE 7/9/25
- ~~Controls text box showing camera controls~~ COMPLETE 7/9/25
- ~~Entity info panel showing current selected planet with entity class information~~ COMPLETE 7/9/25
#### Camera/Window
- ~~Camera Manager class~~  COMPLETE 7/8/25

## The project is buildable, but not fully functional
### Dependencies
##	Dependencies, Building, and Running
This project was developed in a Linux environment and compiled in CMake. It is compiled in C++ 20 and requires OGRE, along with the OgreBites and RT Shader System components.

### Ogre
I recommend following this [guide to building OGRE](https://ogrecave.github.io/ogre/api/latest/building-ogre.html), and installing all recommended dependencies.

### Cmake
CMake can be downloaded at [cmake.org](cmake.org)

## Building the projects through CMake
- Linux Terminal:
```
~Navigate to this folder
mkdir build
cd build
cmake ..
make
./Solar
```