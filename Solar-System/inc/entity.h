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
		~Entity();

		Engine* engine;

		void Tick(float dt);

		Ogre::Vector3 GetPosition() const { return position; }
		bool GetSelected() const { return isSelected; }
		Ogre::Degree GetAngle() const { return orbitAngle; }
		PlanetInfo* GetPlanet() const { return info; }

		void SetPosition(Ogre::Vector3 newPos) { position = newPos; }
		void SetSelected(bool select) {	isSelected = select; }
		void IncrementAngle(float value);

	private:
		//ogre object info
		//object ID number
		unsigned short int identity;
		Ogre::SceneNode* sceneNode = nullptr;
		//dynamic info
		//planet position
		Ogre::Vector3 position = Ogre::Vector3::ZERO;
		bool isSelected = false;
		Ogre::Degree orbitAngle;
		//planet info struct
		PlanetInfo* info;
};
