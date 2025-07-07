/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Input Manager class definition
 */

#include "inputMgr.h"
#include "engine.h"
#include "gfxMgr.h"
//#include "entityMgr.h"

InputMgr::InputMgr(Engine *engine)
	: Mgr(engine) {
	this->engine = engine;
}

InputMgr::~InputMgr() {
}

void InputMgr::Init() {
	engine->gfxMgr->addInputListener(this);
}

void InputMgr::Load() {

}

void InputMgr::Tick(float dt) {
	ProcessInput(dt);
}

// input press events
bool InputMgr::keyPressed(const OgreBites::KeyboardEvent& evt) {
	switch (evt.keysym.sym) {
		// Escape: Quit the application
		case OgreBites::SDLK_ESCAPE:
			engine->Stop();
			break;
		// Space: Reset view angle
		case OgreBites::SDLK_SPACE:
			//TODO: reset view angle
			break;
		// Left/Right: adjust simulation speed
		case OgreBites::SDLK_LEFT:
		case OgreBites::SDLK_RIGHT:
			//TODO: adjustSpeed(evt.keysym.sym == SDLK_RIGHT);
			break;
		// 0-9: Select specific planet
		case '0':	//sun
		case '1':	//mercury
		case '2':	//venus
		case '3':	//earth
		case '4':	//mars
		case '5':	//jupiter
		case '6':	//saturn
		case '7':	//uranus
		case '8':	//neptune
		case '9':	//pluto
			engine->entityMgr->SetSelected(evt.keysym.sym - '0');
			break;
		//camera controls
		case 'w':
		case 's':
		case 'a':
		case 'd':
		case 'r':
		case 'f':
			keyStates[evt.keysym.sym] = true;
			break;
		default:
			return false;
	}
	return true;
}

bool InputMgr::keyReleased(const OgreBites::KeyboardEvent& evt) {
	if (keyStates.contains(evt.keysym.sym)) {
		keyStates[evt.keysym.sym] = false;
	}
	return true;
}

bool InputMgr::isKeyDown(int key) {
	if (keyStates.contains(key)) {
		return keyStates[key];
	} else {
		keyStates[key] = false;
	}
	return false;
}

void InputMgr::ProcessInput(float dt) {
	// W/S: Zoom camera in/out
	if (isKeyDown('w'))
		engine->camMgr->MoveZ(true, engine->entityMgr->GetSelected()->GetPlanet.scale);
	if (isKeyDown('s'))
		engine->camMgr->MoveZ(false, engine->entityMgr->GetSelected()->GetPlanet.scale);
	// A/D: Rotate camera left/right
	if (isKeyDown('a'))
		engine->camMgr->MoveX(false);
	if (isKeyDown('d'))
		engine->camMgr->MoveX(true);
	// R/F: Rotate camera up/down
	if (isKeyDown('r'))
		engine->camMgr->MoveY(true);
	if (isKeyDown('f'))
		engine->camMgr->MoveY(false);

}
