/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Input Manager child class declaration
 */

#include "inputMgr.h"

InputMgr::InputMgr(Engine* engine) : Mgr(engine) {
	this->engine = engine;
}

InputMgr::~InputMgr() {
}

void InputMgr::Init() {
	this->engine->gfxMgr->addInputListener(this); // Register this class as an input listener for the graphics manager
}

void InputMgr::LoadLevel() {
}

void InputMgr::Tick(float dt) {
	ProcessInput(dt);
}

void InputMgr::Stop() {

}

// Handle input press events
bool InputMgr::keyPressed(const OgreBites::KeyboardEvent& evt) {
	switch (evt.keysym.sym) {
		case 9: // Tab: select next entity
			engine->entityMgr->SelectNextEntity();
			break;
		case OgreBites::SDLK_ESCAPE:
		case 'q':		// Escape or Q: quit the application
			engine->SetRunning(false);
			break;
		case OgreBites::SDLK_SPACE:	//Space: stop the selected entity
			engine->entityMgr->GetSelectedEntity()->SetDesiredSpeed(0);
			engine->entityMgr->GetSelectedEntity()->SetDesiredHeading(engine->entityMgr->GetSelectedEntity()->GetHeading());
			break;
		default:
			keyStates[evt.keysym.sym] = true; // Track key state for continuous input handling
	}
	return true;
}

bool InputMgr::keyReleased(const OgreBites::KeyboardEvent& evt) {
	keyStates[evt.keysym.sym] = false; // Track key state for continuous input handling
	return true;
}

// OgreInput.h doesn't have a keyReleased method, so we use this to track key states
bool InputMgr::isKeyDown(int key) {
	// Check if the key is currently pressed
	if (keyStates.contains(key)) {
		return keyStates.at(key);
	} else {
		keyStates[key]= false; // Initialize key state if not present
	}
	return false;
}

void InputMgr::UpdateCamera(float dt) {
	// Move camera by size of vector
	engine->gfxMgr->GetCameraNode()->translate(cameraMoveVec * dt, Ogre::Node::TS_LOCAL);
	cameraMoveVec = Ogre::Vector3::ZERO; // Reset camera move vector after applying
}

void InputMgr::ProcessInput(float dt) {
	// update desired speed and heading
	if (isKeyDown(OgreBites::SDLK_UP) || isKeyDown(OgreBites::SDLK_KP_8)) // Up or Numpad8: Increase desired speed
		engine->entityMgr->GetSelectedEntity()->IncrementDesiredSpeed(desiredVelocityStep * dt);
	if (isKeyDown(OgreBites::SDLK_DOWN) || isKeyDown(OgreBites::SDLK_KP_2)) // Down or Numpad2: decrease desired speed
		engine->entityMgr->GetSelectedEntity()->IncrementDesiredSpeed(-desiredVelocityStep * dt);
	if (isKeyDown(OgreBites::SDLK_LEFT) || isKeyDown(OgreBites::SDLK_KP_4)) // Left or Numpad4: decrease desired heading
		engine->entityMgr->GetSelectedEntity()->IncrementDesiredHeading(-desiredAnglesStep * dt);
	if (isKeyDown(OgreBites::SDLK_RIGHT) || isKeyDown(OgreBites::SDLK_KP_6)) // Right or Numpad6: increase desired heading
		engine->entityMgr->GetSelectedEntity()->IncrementDesiredHeading(desiredAnglesStep * dt);

	// update camera movement
	if (isKeyDown('w')) {	// W: Move camera forward, Shift + W: pitch camera up
		if (isKeyDown(OgreBites::SDLK_LSHIFT))
			engine->gfxMgr->GetCameraNode()->pitch(Ogre::Degree(-15 * dt)); // Pitch camera up
		else
			cameraMoveVec.z -= cameraStep * dt; // Move camera forward
	}
	if (isKeyDown('s')) {	// S: Move camera backward, Shift + S: pitch camera down
		if (isKeyDown(OgreBites::SDLK_LSHIFT))
			engine->gfxMgr->GetCameraNode()->pitch(Ogre::Degree(15 * dt)); // Pitch camera down
		else
			cameraMoveVec.z += cameraStep * dt; // Move camera backward
	}
	if (isKeyDown('r'))	// R: Move camera up
		cameraMoveVec.y += cameraStep * dt;
	if (isKeyDown('f'))	// F: Move camera down
		cameraMoveVec.y -= cameraStep * dt;
	if (isKeyDown('a')) {	// A: Move camera left, Shift + A: yaw camera left
		if (isKeyDown(OgreBites::SDLK_LSHIFT))
			engine->gfxMgr->GetCameraNode()->yaw(Ogre::Degree(15 * dt), Ogre::Node::TS_WORLD); // Yaw camera left
		else
			cameraMoveVec.x -= cameraStep * dt; // Move camera left
	}
	if (isKeyDown('d')) {	// D: Move camera right, Shift + D: yaw camera right
		if (isKeyDown(OgreBites::SDLK_LSHIFT))
			engine->gfxMgr->GetCameraNode()->yaw(Ogre::Degree(-15 * dt), Ogre::Node::TS_WORLD); // Yaw camera right
		else
			cameraMoveVec.x += cameraStep * dt; // Move camera right
	}

		UpdateCamera(dt);
}
