/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class definition
 */

#pragma once

#include "main.h"
#include "engine.h"
#include "mgr.h"
#include "entity.h"

class Entity; // Forward declaration of the Engine class

class EntityMgr : public Mgr {
	public:
		EntityMgr(Engine* engine);
		~EntityMgr();

		void Init();
		void LoadLevel();
		void Tick(float dt);
		void Stop();

		void CreateEntityOfTypeAtPosition(EntityTypes type, Ogre::Vector3 pos);
		void SelectNextEntity();

		Entity* GetSelectedEntity() const {
			return selectedEntity;
		}
	private:
		int count = 0;
		Engine *engine;
		std::vector<Entity*> entities;
		Entity* selectedEntity = nullptr;
		int selectedEntityIndex = -1;
};
