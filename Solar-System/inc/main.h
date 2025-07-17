/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Main declarations
*/
#pragma once

#include "utils.h"
#include "json.hpp"
// C++ Library Includes
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
// Ogre Includes
#include <OgreCamera.h>
#include <OgreConfigFile.h>
#include <OgreException.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreRenderWindow.h>
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreTimer.h>
#include <OgreVector.h>
#include <OgreViewport.h>
// OgreBites Includes
#include <OgreInput.h>
#include <OgreApplicationContext.h>
#include <OgreCameraMan.h>
#include <OgreTrays.h>
#include <OgreWindowEventUtilities.h>
// RTShaderSystem Includes
#include <OgreRTShaderSystem.h>

struct PlanetInfo {
	std::string name, sceneName;
	int numMoons;
	//planet size
	float scale;
	//orbit info
	float orbitDist, orbitSpeed, orbitTilt;
	//the speed this planet rotates
	float rotateSpeed;
	int index;
};

using json = nlohmann::json;
