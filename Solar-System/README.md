# OGRE Solar System
## Rendering a solar system in OGRE

## Project plans
#### Entity Manager
- Entity Manager class
- Entity class representing each object
	- Tracks scale, name, rotation speed, orbit speed, and number of satellites
- ~~.mesh files for all planets, rings, and moons~~ COMPLETE 6/25/25
#### JSON file
- Use a JSON file with basic planet information for the sun, planets, and pluto
- Add rings for Jupiter, Saturn, Uranus, and Neptune
- Add major moons of Earth, Mars, Jupiter, Saturn, Uranus, Neptune, and Pluto
- Keep consistent scale
#### Lighting/Shading
- Point light under sun (or replace sun mesh?)
#### Background
- custom space skybox
#### Controls
- ~~Input Manager class~~ COMPLETE 7/5/25
- Zoom in and out (W/S)
- Rotate horizontally (A/D)
- Rotate vertically (R/F)
- Planet selection (0-9)
- Reset view angle (Space)
- Adjust simulation speed (left/right arrows)
#### UI
- UI Manager class
- Introduction text box with 'exit application' controls
- Controls text box showing camera controls
- Entity info panel showing current selected planet with entity class information
#### Camera/Window
- Camera Manager class

## The project is not yet in a buildable state
<!-- ### Dependencies
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
``` -->