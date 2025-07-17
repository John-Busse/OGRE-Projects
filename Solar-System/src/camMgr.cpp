/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Camera Manager class definition
*/
#include "camMgr.h"
#include "engine.h"
#include "entity.h"

CamMgr::CamMgr(Engine *engine)
	: Mgr(engine),
	cameraNode(nullptr),
	radius(5.0f),
	camPos(Ogre::Vector3(0.0f, 0.0f, -50.0f)),
	focusPos(Ogre::Vector3(0.0f, 0.0f, 0.0f)) {
	this->engine = engine;
	updateCam = true;
	ResetAngle();
}

CamMgr::~CamMgr() {
}

void CamMgr::Load() {
	//initialize camera
	Ogre::Camera* camera = engine->gfxMgr->getSceneMgr()->createCamera("MainCamera");
	camera->setNearClipDistance(1);
	camera->setFarClipDistance(5000);

	//set up camera node
	cameraNode = engine->gfxMgr->getSceneMgr()->getRootSceneNode()->createChildSceneNode("CameraNode");
	cameraNode->setPosition(camPos);
	cameraNode->lookAt(focusPos, Ogre::Node::TS_WORLD);
	cameraNode->attachObject(camera);

	//add viewport
	Ogre::Viewport* vp = engine->gfxMgr->getRenderWindow()->addViewport(camera);
	vp->setBackgroundColour(Ogre::ColourValue(0.1f, 0.1f, 0.1f));
	camera->setAspectRatio(
		Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}

void CamMgr::Tick(float dt) {
	Entity* selected = engine->entityMgr->GetSelected();
	//update camera position
	SetPos(selected->GetPosition());
	if (updateCam) {
		SetRadius(selected->GetPlanet()->scale);
		ResetAngle();
		updateCam = false;
	}

	//set camera position
	cameraNode->setPosition(camPos);
	//OGRE doesn't allow direct model matrix manipulation
	//
	cameraNode->resetOrientation();
	cameraNode->lookAt(Ogre::Vector3(focusPos.x, camPos.y, focusPos.z), Ogre::Node::TS_WORLD);
	cameraNode->lookAt(focusPos, Ogre::Node::TS_WORLD);
}

void CamMgr::ResetAngle() {
	//if we're at the origin (looking at the sun)
	if (focusPos == Ogre::Vector3::ZERO) {
		theta = 180.0f;
		phi = 90.0f;
	} else {	//otherwise, face the sunlit side of the planet
		Ogre::Vector3 view = Ogre::Vector3(-focusPos.normalisedCopy());
		theta = atan2(view.z, view.x) * (180.0f / M_PI);
		phi = acos(view.y / 1.0f) * (180.0f / M_PI) - 30.0f;
	}
}

void CamMgr::SetRadius(float planetScale) {
	radius = 10.0f * planetScale;
}

void CamMgr::SetPos(Ogre::Vector3 planetPos) {
	camPos = Ogre::Vector3(	planetPos.x + radius * sin(phi.valueRadians()) * cos(theta.valueRadians()),
							planetPos.y + radius * cos(phi.valueRadians()),
							planetPos.z + radius * sin(phi.valueRadians()) * sin(theta.valueRadians()));
	focusPos = planetPos;
}

void CamMgr::MoveX(bool right, float delta){
	float direction = 50.0f * delta * (right ? 1.0f : -1.0f);
	theta += Ogre::Degree(direction);

	theta = FixAngle(theta.valueDegrees());
}

void CamMgr::MoveY(bool up, float delta) {
	float direction = 10.0f * delta * (up ? 1.0f : -1.0f);
	phi += Ogre::Degree(direction);

	phi = Clamp <float> (1.0f, 180.0f, phi.valueDegrees());
}

void CamMgr::MoveZ(bool in, float scale, float delta) {
	float direction = 2.0f * delta * (in ? 1.0f : -1.0f) * scale;
	radius += direction;

	radius = Clamp <float> (2.0f * scale, 50.0f * scale, radius);
}
