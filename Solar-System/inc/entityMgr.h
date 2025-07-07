/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class definition
 */
#pragma once

#include "main.h"
#include "mgr.h"

//forward declarations
class Engine;
class Entity;

class EntityMgr : public Mgr {
	public:
		EntityMgr(Engine* Engine);
		~EntityMgr();

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		void CreateEntity(std::string, Ogre::Vector3, PlanetInfo);
		void SelectNextEntity();

		Entity* GetSelected() const { return selectedEntity; }
		void SetSelected(int index) {
			if (index > entities.size()) {
				throw std::runtime_error("EntityMgr::SetSelected() Error: index out of range\n");
			}
			selectedIndex = index;
			selectedEntity = entities[index];
		}
	private:
		int count = 0;
		Engine* engine;
		std::vector<Entity*> entities;
		Entity* selectedEntity = nullptr;
		int selectedIndex = -1;
};
