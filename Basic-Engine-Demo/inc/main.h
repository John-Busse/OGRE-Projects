/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Main header declarations
 */
#pragma once

#include "utils.h"
// C++ Library Includes
#include <iostream>
#include <map>
#include <sstream>
#include <string>
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
#include <OgreWindowEventUtilities.h>
// RTShaderSystem Includes
#include <OgreRTShaderSystem.h>

enum EntityTypes {
	Ent_Destroyer,
	Ent_Carrier,
	Ent_Cig,
	Ent_CG47,
	Ent_Tug,
	Ent_PolyPlane,
};
