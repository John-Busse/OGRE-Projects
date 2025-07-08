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
		Entity(Engine*, int, PlanetInfo*, Ogre::Vector3 pos);
		~Entity() {}

		Engine* engine;

		void Tick(float);

		//getters and setters
		//identity
		//sceneNode
		//position
		Ogre::Vector3 GetPosition() { return position; }
		void SetPosition(Ogre::Vector3 newPos) { position = newPos; }
		//isSelected
		bool GetSelected() { return isSelected; }
		void SetSelected(bool select) {
			isSelected = select;
		}
		//heading
		//orbitAngle
		float GetAngle() {
			return orbitAngle;
		}
		void IncrementAngle(float value) {
			orbitAngle += value * info->orbitSpeed;
		}
		//info
		PlanetInfo* GetPlanet() {
			return info;
		}


	protected:
		//ogre object info
		unsigned short int identity;
		Ogre::SceneNode* sceneNode = nullptr;
		//Ogre::Entity* ogreEntity = nullptr;
		//dynamic info
		Ogre::Vector3 position = Ogre::Vector3::ZERO;
		bool isSelected = false;
		float heading = 0.0f, orbitAngle = 0.0f;
		//planet info
		PlanetInfo* info;
};
