/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Camera Manager class definition
*/
#include "camMgr.h"
#include "engine.h"
#include "entity.h"

CamMgr::CamMgr(Engine *engine)
	: Mgr(engine) {
	this->engine = engine;
	cameraNode = nullptr;
	radius = 5.0f;
	theta = 270.0f;
	phi = 90.0f;
	camPos = Ogre::Vector3(0.0f, 0.0f, -50.0f);
	focusPos = Ogre::Vector3(0.0f, 0.0f, 0.0f);
	updateCam = true;
}

CamMgr::~CamMgr() {

}

void CamMgr::Init() {
	//initialize camera
	Ogre::Camera* camera = engine->gfxMgr->getSceneMgr()->createCamera("MainCamera");
	camera->setNearClipDistance(5);
	camera->setFarClipDistance(5000);

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

void CamMgr::Load() {
	//load initial scene data here, if any
}

void CamMgr::Tick(float dt) {
	//TODO: get current selected entity
	//focus pos = entity position
	//SetPos()
	/*
	if (thisPlanet->GetSelected()){
		engine->camMgr->SetPos(posStack.top());
		if (engine->camMgr->GetUpdateCam()) {
			engine->camMgr->SetRadius(thisPlanet->GetPlanet()->scale);
			engine->camMgr->ResetAngle(posStack.top());
			engine->camMgr->SetUpdateCam(false);
		}
	}
	*/
	Entity* selected = engine->entityMgr->GetSelected();
	SetPos(selected->GetPosition());
	if (updateCam) {
		SetRadius(selected->GetPlanet()->scale);
		ResetAngle();
		updateCam = false;
		cameraNode->resetOrientation();
	}

	cameraNode->setPosition(camPos);
	cameraNode->lookAt(focusPos,Ogre::Node::TS_WORLD);
}

void CamMgr::Stop() {

}

void CamMgr::ResetAngle() {
	//if we're at the origin (looking at the sun)
	if (focusPos == Ogre::Vector3::ZERO) {
		theta = 270.0f;
		phi = 90.0f;
	} else {	//otherwise, face the sunlit side of the planet
		Ogre::Vector3 view = Ogre::Vector3(-focusPos.normalisedCopy());
		theta = atan2(view.z, view.x) * (180.0f / M_PI);
		phi = (acos(view.y / 1.0f) * (180.0f / M_PI)) - 30.0f;
	}
}

void CamMgr::SetRadius(float planetScale) {
	radius = 10.0f * planetScale;
}

//set focus position, update view
void CamMgr::SetPos(Ogre::Vector3 pos) {
	camPos = Ogre::Vector3(	pos.x + radius * sin(phi.valueRadians()) * cos(theta.valueRadians()),
							pos.y + radius * cos(phi.valueRadians()),
							pos.z + radius * sin(phi.valueRadians()) * sin(theta.valueRadians()));
	focusPos = pos;
}

//rotate camera left or right (x-axis) with A and D keys
void CamMgr::MoveX(bool right, float delta){
	float direction = 50.0f * delta * (right ? 1.0f : -1.0f);
	theta += Ogre::Degree(direction);

	theta = FixAngle(theta.valueDegrees());
}

//rotate camera up or down (y-axis) with R and F keys
void CamMgr::MoveY(bool up, float delta) {
	float direction = 10.0f * delta * (up ? 1.0f : -1.0f);
	phi += Ogre::Degree(direction);

	phi = Clamp <float> (1.0f, 180.0f, phi.valueDegrees());
}

//zoom camera in or out (z-axis) with W and S keys
void CamMgr::MoveZ(bool in, float scale, float delta) {
	float direction = 2.0f * delta * (in ? 1.0f : -1.0f) * scale;
	radius += direction;

	radius = Clamp <float> (2.0f * scale, 20.0f * scale, radius);
}
