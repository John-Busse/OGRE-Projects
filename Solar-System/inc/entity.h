/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class definition
 */
#pragma once

#include "main.h"

class Engine;

class Entity {
	public:
		Entity(Engine*, int, PlanetInfo*);	//Ogre::Vector3 pos
		~Entity() {}

		Engine* engine;

		void Tick(float);
		void SetSelected(bool select) {
			isSelected = select;
		}
		PlanetInfo* GetPlanet() {
			return info;
		}

	protected:
		//ogre object info
		unsigned short int identity;
		Ogre::SceneNode* sceneNode = nullptr;
		Ogre::Entity* ogreEntity = nullptr;
		//dynamic info
		Ogre::Vector3 position = Ogre::Vector3::ZERO;
		bool isSelected = false;
		float heading = 0.0f;
		//planet info
		PlanetInfo* info;
};
