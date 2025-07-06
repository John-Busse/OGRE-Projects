/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Camera Manager class definition
*/
#include "camMgr.h"
#include "engine.h"

CamMgr::CamMgr(Engine *engine)
	: Mgr(engine) {
	this->engine = engine;
	cameraNode = nullptr;
	radius = 5.0f;
	theta = 270.0f;
	phi = 90.0f;
	camPos = Ogre::Vector3(0.0f, 0.0f, -50.0f);
	focusPos = Ogre::Vector3(0.0f, 0.0f, 0.0f);
}

CamMgr::~CamMgr() {

}

void CamMgr::Init() {
	//initialize camera
	Ogre::Camera* camera = engine->gfxMgr->getSceneMgr()->createCamera("MainCamera");
	camera->setNearClipDistance(5);

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
}

void CamMgr::Stop() {

}

void CamMgr::ResetAngle() {
	//if we're at the origin (looking at the sun)
	if (focusPos == Ogre::Vector3::ZERO) {
		theta = 270.0f;
		phi = 90.0f;
	} else {	//otherwise, face the sunlit side of the planet
		Ogre::Vector3 view = Ogre::Vector3(-focusPos.normalise());

		theta = atan2(view.z, view.x) * (180.0f / M_PI);
		phi = (acos(view.y / 1.0f) * (180.0f / M_PI)) - 30.0f;
	}
}

void CamMgr::SetRadius(float planetScale) {
	radius = 5.0f * planetScale;
}

//set focus position, update view
void CamMgr::SetPos(Ogre::Vector3 pos) {
	//float x = pos.x + radius * sin(phi.valueRadians()) * cos(theta.valueRadians());
	//float y = pos.y + radius * cos(phi.valueRadians());
	//float z = pos.z + radius * sin(phi.valueRadians()) * sin(theta.valueRadians());
	//camPos = Ogre::Vector3(x, y , z);
	//camPos = Ogre::Vector3(pos.x + radius * sin(phi.valueRadians()) * cos(theta.valueRadians()), 0, 0);
	camPos = Ogre::Vector3(	pos.x + radius * sin(phi.valueRadians()) * cos(theta.valueRadians()),
							pos.y + radius * cos(phi.valueRadians()),
							pos.z + radius * sin(phi.valueRadians()) * sin(theta.valueRadians()));
	focusPos = pos;
}

//rotate camera left or right (x-axis) with A and D keys
void CamMgr::MoveX(bool right){
	float direction = 1.0f * (right ? 1.0f : -1.0f);
	theta += direction;

	theta = Clamp(0.0f, 360.0f, theta.mDeg);
}

//rotate camera up or down (y-axis) with R and F keys
void CamMgr::MoveY(bool up) {
	float direction = 0.5f * (up ? 1.0f : -1.0f);
	phi += direction;

	phi = Clamp(1.0f, 180.0f, phi.mDeg);
}

//zoom camera in or out (z-axis) with W and S keys
void CamMgr::MoveZ(bool in, float scale) {
	float direction = 0.1f * (in ? 1.0f : -1.0f) * scale;
	radius += direction;

	radius = FixAngle(radius.mDeg);
}
