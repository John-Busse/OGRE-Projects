/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class declaration
 */
#include "entityMgr.h"
#include "engine.h"
#include "entity.h"

EntityMgr::EntityMgr(Engine* engine) : Mgr(engine) {
	this->engine = engine;
}

EntityMgr::~EntityMgr() {
	for (Entity* entity : entities) {
		delete entity;
		entity = nullptr;
	}
	entities.clear();
}

void EntityMgr::Load() {

}

void EntityMgr::Tick(float dt) {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->Tick(dt);
	}
}

void EntityMgr::CreateEntity(Ogre::Vector3 pos, PlanetInfo *planetInfo) {
	Entity* entPtr;
	entPtr = new Entity(this->engine, count, planetInfo, pos);
	count++;
	entities.push_back(entPtr);
}

Entity* EntityMgr::GetEntityByIndex(int index) {
	return entities[index];
}

//Update the selected entity
//@returns true if this is a new planet, false if it's a repeated input
bool EntityMgr::SetSelected(int index){
			bool newIndex = (index != selectedIndex);
			if (index > entities.size() || index < 0) {
				throw std::runtime_error("EntityMgr::SetSelected() Error: index out of range\n");
			}

			selectedIndex = index;
			for (Entity* entity : entities) {
				if (entity->GetPlanet()->index == index) {
					selectedEntity = entity;
					break;
				}
			}
			return newIndex;
		}
