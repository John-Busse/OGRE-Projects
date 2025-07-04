/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * User Interface Manager child class declaration
 */

#include "uiMgr.h"

UIMgr::UIMgr(Engine* engine) : Mgr(engine),
trayMgr(nullptr),
entityInfoTB(nullptr),
engineControlsTB(nullptr),
entityControlsTB(nullptr),
cameraControlsTB(nullptr) {
	this->engine = engine;
}

UIMgr::~UIMgr() {
	delete trayMgr;
	trayMgr = nullptr;
	delete entityInfoTB;
	entityInfoTB = nullptr;
	delete engineControlsTB;
	engineControlsTB = nullptr;
	delete entityControlsTB;
	entityControlsTB = nullptr;
	delete cameraControlsTB;
	cameraControlsTB = nullptr;
	engine = nullptr;
}

void UIMgr::Init() {
	trayMgr = new OgreBites::TrayManager("UI Manager", engine->gfxMgr->getRenderWindow());
	engine->gfxMgr->addInputListener(trayMgr);
}

void UIMgr::LoadLevel() {
	trayMgr->hideCursor();
	// Load UI elements
	// engine controls text box
	engineControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_TOPRIGHT, "EngineControls", "Engine Controls", 350, 110);
	engineControlsTB->setText(engineControls);

	// entity controls text box
	entityControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_BOTTOMLEFT, "EntityControls", "Entity Controls", 350, 175);
	entityControlsTB->setText(entityControls);

	// camera controls text box
	cameraControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_TOPLEFT, "CameraControls", "Camera Controls", 350, 170);
	cameraControlsTB->setText(cameraControls);

	// entity info text box
	std::string entityTBContent = "Selected Entity: None\n";
	entityInfoTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_BOTTOMRIGHT, "EntityInfo", "Entity Info", 300, 160);
	entityInfoTB->setText(entityTBContent);
}

void UIMgr::Tick(float dt) {
	// Update UI elements here if needed
	Entity* selectedEntity = engine->entityMgr->GetSelectedEntity();
	if (selectedEntity) {
		std::string entityInfo = "Selected Entity: " + selectedEntity->GetName() + "\n"
	 		+ "Desired Speed: " + std::to_string(int(selectedEntity->GetDesiredSpeed())) + "\n"
			+ "Speed: " + std::to_string(int(selectedEntity->GetSpeed())) + "\n"
			+ "Desired Heading: " + std::to_string(int(selectedEntity->GetDesiredHeading())) + "\n"
			+ "Heading: " + std::to_string(int(selectedEntity->GetHeading()));
		entityInfoTB->setText(entityInfo);
	} else {
		entityInfoTB->setText("Selected Entity: None");
	}
}

void UIMgr::Stop() {
	// Cleanup UI elements if needed
	/*
	if (trayMgr) {
		engine->gfxMgr->GetSceneMgr()->removeRenderQueueListener(trayMgr);
		engine->gfxMgr->GetRoot()->removeFrameListener(trayMgr);
	}*/
}
