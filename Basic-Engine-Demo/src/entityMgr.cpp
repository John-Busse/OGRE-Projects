/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity manager child class declaration
 */

#include "entityMgr.h"

EntityMgr::EntityMgr(Engine* engine) : Mgr(engine) {
	this->engine = engine;
}

EntityMgr::~EntityMgr() {
	// Cleanup entities
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();
}


void EntityMgr::Init(){

}

void EntityMgr::LoadLevel(){

}

void EntityMgr::Stop(){

}

void EntityMgr::Tick(float dt){
	for(int i = 0; i < count; i++)
		entities[i]->Tick(dt);
}

void EntityMgr::CreateEntityOfTypeAtPosition(EntityTypes type, Ogre::Vector3 pos) {
	Entity* entPtr;
	switch(type){
	case Ent_CG47:
		entPtr = new CG47(this->engine, "cg47.mesh", pos, count);
		break;
	case Ent_Cig:
		entPtr = new Cigarette(this->engine, "cigarette-V2.mesh", pos, count);
		break;
	case Ent_Carrier:
		entPtr = new Carrier(this->engine, "cvn75.mesh", pos, count);
		break;
	case Ent_Destroyer:
		entPtr = new Destroyer(this->engine, "ddg51-v2.mesh", pos, count);
		break;
	case Ent_Tug:
		entPtr = new Tug(this->engine, "tug.mesh", pos, count);
		break;
	case Ent_PolyPlane:
		entPtr = new PolyPlane(this->engine, "PolyPlane.mesh", pos, count);
		break;
	default:
		throw std::runtime_error("Tried to create invalid entity type");
		break;
	}
	count++;
	entities.push_back(entPtr);
}

void EntityMgr::SelectNextEntity() {
	int nEnts = entities.size();
	if (nEnts <= 0)
		throw std::runtime_error("Create a game entity before selecting one.");

	if (selectedEntityIndex >= 0)
		selectedEntity->SetSelected(false);	// current selection unselected
	selectedEntityIndex = (selectedEntityIndex + 1) % nEnts;
	selectedEntity = entities[selectedEntityIndex];
	selectedEntity->SetSelected(true);	// new selection selected
}
