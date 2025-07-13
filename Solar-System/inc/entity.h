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

		void Tick(float);

		Ogre::Vector3 GetPosition() const { return position; }
		bool GetSelected() const { return isSelected; }
		float GetAngle() const { return orbitAngle; }
		PlanetInfo* GetPlanet() const { return info; }

		void SetPosition(Ogre::Vector3 newPos) { position = newPos; }
		void SetSelected(bool select) {	isSelected = select; }
		void IncrementAngle(float value) { orbitAngle += value * info->orbitSpeed; }

	private:
		//ogre object info
		unsigned short int identity;
		Ogre::SceneNode* sceneNode = nullptr;
		//dynamic info
		Ogre::Vector3 position = Ogre::Vector3::ZERO;
		bool isSelected = false;
		float heading = 0.0f, orbitAngle = 0.0f;
		//planet info
		PlanetInfo* info;
};
