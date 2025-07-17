/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Entity class declaration
 */

#include "entity.h"
#include "engine.h"

Entity::Entity(Engine* engine, int id, PlanetInfo* pInfo, Ogre::Vector3 pos) :
	identity(id),
	info(pInfo),
	position(pos),
	orbitAngle(0.0f)
{	//Ogre::Vector3 pos
	// fill the data
	this->engine = engine;

	//instantiate and load the scene node
	sceneNode = engine->gfxMgr->getSceneMgr()->getRootSceneNode()->createChildSceneNode(position);
	Ogre::ResourceGroupManager::getSingleton().setWorldResourceGroupName(info->name);
	sceneNode->loadChildren(info->sceneName);
	sceneNode->setScale(Ogre::Vector3(info->scale));
	sceneNode->roll(Ogre::Degree(info->orbitTilt), Ogre::Node::TS_LOCAL);
	//sceneNode->setOrientation(Ogre::Quaternion())

	// Sun shouldn't cast shadows
	if (!id) {
		Ogre::SceneNode* childNode = static_cast<Ogre::SceneNode*>(sceneNode->getChild(0));
		childNode->getAttachedObject(0)->setCastShadows(false);
	}
}

Entity::~Entity() {
	delete info;
	info = nullptr;
}

void Entity::Tick(float dt) {
	float delta = info->rotateSpeed * dt * engine->GetSpeed() * 100.0f;

	//move the planet
	sceneNode->setPosition(position);

	if (delta != 0.0f) {
		//rotate the planet (if sim speed isn't 0)
		sceneNode->yaw(Ogre::Degree(-delta));
	}
}

void Entity::IncrementAngle(float value) {	
	orbitAngle += Ogre::Radian(value * info->orbitSpeed);
	orbitAngle = FixAngle(orbitAngle.valueDegrees());
}