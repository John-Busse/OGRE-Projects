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
	//std::cout << "key pressed " << evt.keysym.sym << " char = " << char(evt.keysym.sym) << "\n";
	switch (evt.keysym.sym) {
		case 9: // Tab: select next entity
			engine->entityMgr->SelectNextEntity();
			break;
		case OgreBites::SDLK_ESCAPE:
		case 'q':
			engine->SetRunning(false);
			break;
		case OgreBites::SDLK_SPACE:	//Space: stop the selected entity
			engine->entityMgr->GetSelectedEntity()->SetDesiredSpeed(0);
			engine->entityMgr->GetSelectedEntity()->SetDesiredHeading(engine->entityMgr->GetSelectedEntity()->GetHeading());
			break;
		//entity control keys
		case OgreBites::SDLK_UP:
		case OgreBites::SDLK_KP_8: // W or Numpad8: increase desired speed
			desiredSpeedStep = 1;
			break;
		case OgreBites::SDLK_DOWN:
		case OgreBites::SDLK_KP_2: // S or Numpad2: decrease desired speed
			desiredSpeedStep = -1;
			break;
		case OgreBites::SDLK_LEFT:
		case OgreBites::SDLK_KP_4: // A or Numpad4: decrease desired heading
			desiredHeadingStep = -1;
			break;
		case OgreBites::SDLK_RIGHT:
		case OgreBites::SDLK_KP_6: // D or Numpad6: increase desired heading
			desiredHeadingStep = 1;
			break;
		// camera control keys
		case OgreBites::SDLK_LSHIFT: // Shift: toggle camera pitch vs move
			inputShift = true;
			break;
		case 'w': // W: Move camera forward, Shift + W: pitch camera up
			if (inputShift)
				cameraPitchStep = 1; // Pitch camera up
			else
				cameraMoveStep.z = -1;
			break;
		case 's': // S: Move camera backward, Shift + S: pitch camera down
			if (inputShift)
				cameraPitchStep = -1; // Pitch camera down
			else
				cameraMoveStep.z = 1;
			break;
		case 'a': // A: Move camera left, Shift + A: yaw camera left
			if (inputShift)
				cameraYawStep = 1; // Yaw camera left
			else
				cameraMoveStep.x = -1;
			break;
		case 'd': // D: Move camera right, Shift + D: yaw camera right
			if (inputShift)
				cameraYawStep = -1; // Yaw camera right
			else
				cameraMoveStep.x = 1;
			break;
		case 'e': // E: Move camera up
			cameraMoveStep.y = 1;
			break;
		case 'f': // F: Move camera down
			cameraMoveStep.y = -1;
			break;
		default:
			return false; // unhandled key
	}
	return true;
}

bool InputMgr::keyReleased(const OgreBites::KeyboardEvent& evt) {
	switch (evt.keysym.sym) {
		//entity control keys
		case OgreBites::SDLK_UP:
		case OgreBites::SDLK_KP_8: // W or Numpad8: increase desired speed
		case OgreBites::SDLK_DOWN:
		case OgreBites::SDLK_KP_2: // S or Numpad2: decrease desired speed
			desiredSpeedStep = 0;
			break;
		case OgreBites::SDLK_LEFT:
		case OgreBites::SDLK_KP_4: // A or Numpad4: decrease desired heading
		case OgreBites::SDLK_RIGHT:
		case OgreBites::SDLK_KP_6: // D or Numpad6: increase desired heading
			desiredHeadingStep = 0;
			break;
		// camera control keys
		case OgreBites::SDLK_LSHIFT: // Shift: toggle camera pitch vs move
			inputShift = false;
			cameraPitchStep = 0; // Reset camera pitch step
			cameraYawStep = 0; // Reset camera yaw step
			break;
		case 'w':
		case 's':
			cameraPitchStep = 0;
			cameraMoveStep.z = 0;
			break;
		case 'a': // A: Move camera left, Shift + A: yaw camera left
		case 'd': // D: Move camera right, Shift + D: yaw camera right
			cameraYawStep = 0;
			cameraMoveStep.x = 0;
			break;
		case 'e': // E: Move camera up
		case 'f': // F: Move camera down
			cameraMoveStep.y = 0;
			break;
		default:
			return false; // unhandled key
	}
	return true;
}


void InputMgr::UpdateCamera(float dt) {
	// Move camera by size of vector
	engine->gfxMgr->GetCameraNode()->translate(cameraMoveVec * dt, Ogre::Node::TS_LOCAL);
	cameraMoveVec = Ogre::Vector3::ZERO; // Reset camera move vector after applying
}

void InputMgr::ProcessInput(float dt) {
/*
 * 		bool inputShift = false;
		int desiredSpeedStep = 0;
		int desiredHeadingStep = 0;
		int cameraPitchStep = 0;
		int cameraYawStep = 0;
		Ogre::Vector3 cameraMoveStep = Ogre::Vector3::ZERO;

		Ogre::Vector3 cameraMoveVec = Ogre::Vector3::ZERO;
 */
	if (desiredSpeedStep != 0) {
		engine->entityMgr->GetSelectedEntity()->IncrementDesiredSpeed(desiredSpeedStep * desiredVelocityStep * dt);
	}
	if (desiredHeadingStep != 0) {
		std::cout << "changing heading\n";
		engine->entityMgr->GetSelectedEntity()->IncrementDesiredHeading(desiredHeadingStep * desiredAnglesStep * dt);
	}
	if (cameraPitchStep != 0) {
		engine->gfxMgr->GetCameraNode()->pitch(Ogre::Degree(cameraPitchStep * 15 * dt));
	}
	if (cameraYawStep != 0) {
		engine->gfxMgr->GetCameraNode()->yaw(Ogre::Degree(cameraYawStep * 15 * dt), Ogre::Node::TS_WORLD);
	}
	if (cameraMoveStep != Ogre::Vector3::ZERO) {
		cameraMoveVec += cameraMoveStep * cameraStep;
	}

	UpdateCamera(dt);
}
