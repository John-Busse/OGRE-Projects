/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class declaration
 */

#include "entity.h"

Entity::Entity(Engine* newEngine, std::string meshname, Ogre::Vector3 pos, int ident) {
	this->engine = newEngine;

	meshfilename = meshname;
	position = pos;
	velocity = Ogre::Vector3(0, 0, 0);
	identity = ident;
	isSelected = false;

	name = meshfilename + std::to_string(identity);

	ogreEntity = engine->gfxMgr->GetSceneMgr()->createEntity(meshfilename);
	sceneNode = engine->gfxMgr->GetSceneMgr()->getRootSceneNode()->createChildSceneNode(pos);
	sceneNode->attachObject(ogreEntity);

	Physics2D* phx = new Physics2D(this);
	aspects.push_back((Aspect *) phx);
	Renderable* renderable = new Renderable(this);
	aspects.push_back((Aspect *) renderable);
}

void Entity::Tick(float dt) {
	for (Aspect* a : aspects)
		a->Tick(dt);
}

Destroyer::Destroyer(Engine* newEngine, std::string meshfname, Ogre::Vector3 pos, int ident): Entity(newEngine, meshfname, pos, ident){
	maxSpeed = 16.0f;//meters per second...
	acceleration = 5.0f; // fast
	turnRate = 5.0f;
}

Carrier::Carrier(Engine* newEngine, std::string meshfname, Ogre::Vector3 pos, int ident): Entity(newEngine, meshfname, pos, ident){
	maxSpeed = 20.0f;//meters per second...
	acceleration = 1.0f; // slow
	
}

Cigarette::Cigarette(Engine* newEngine, std::string meshfname, Ogre::Vector3 pos, int ident): Entity(newEngine, meshfname, pos, ident){
	maxSpeed = 30.0f;//meters per second...
	acceleration = 10.0f; // slow
	turnRate = 10.0f;
	sceneNode->setScale(Ogre::Vector3(2,2,2));
}

CG47::CG47(Engine* newEngine, std::string meshfname, Ogre::Vector3 pos, int ident): Entity(newEngine, meshfname, pos, ident){
	maxSpeed = 15.0f;//meters per second...
	acceleration = 5.0f; // slow
	turnRate = 7.0f;
}

Tug::Tug(Engine* newEngine, std::string meshfname, Ogre::Vector3 pos, int ident): Entity(newEngine, meshfname, pos, ident){
	maxSpeed = 50.0f;//meters per second...
	acceleration = 20.0f; // slow
	turnRate = 20.0f;
	sceneNode->setScale(Ogre::Vector3(1.5,1.5,1.5));
}

PolyPlane::PolyPlane(Engine* newEngine, std::string meshfname, Ogre::Vector3 pos, int ident): Entity(newEngine, meshfname, pos, ident){
	maxSpeed = 50.0f;//meters per second...
	acceleration = 20.0f; // slow
	turnRate = 20.0f;
	sceneNode->setScale(Ogre::Vector3(1.5,1.5,1.5));
}
