/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * UI Manager class declaration
*/
#include "uiMgr.h"
#include "engine.h"
#include "entity.h"

UIMgr::UIMgr(Engine* engine) :
	Mgr(engine),
	trayMgr(nullptr),
	entityInfoTB(nullptr),
	engineControlsTB(nullptr),
	entityControlsTB(nullptr)
	{
	this->engine = engine;
}

UIMgr::~UIMgr() {
	if (entityInfoTB) {
		delete entityInfoTB;
		entityInfoTB = nullptr;
	}
	if (entityControlsTB) {
		delete entityControlsTB;
		entityControlsTB = nullptr;
	}
	if (engineControlsTB) {
		delete engineControlsTB;
		engineControlsTB = nullptr;
	}
	if (trayMgr) {
		delete trayMgr;
		trayMgr = nullptr;
	}
}

void UIMgr::Load() {
	trayMgr = new OgreBites::TrayManager("UI Manager", engine->gfxMgr->getRenderWindow());
	engine->gfxMgr->addInputListener(trayMgr);
	trayMgr->hideCursor();

	//load UI elements
	//engine controls
	engineControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_TOPRIGHT, "EngineControls", "Engine Controls", 350, 110);
	engineControlsTB->setText(engineControls);

	// entity controls text box
	entityControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_BOTTOMLEFT, "EntityControls", "Entity Controls", 350, 200);
	entityControlsTB->setText(entityControls);

	//entity info text box
	std::string entityTBContent = "Selected Entity: None\n";
	entityInfoTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_BOTTOMRIGHT, "EntityInfo", "Entity Info", 350, 200);
	entityInfoTB->setText(entityTBContent);
}

void UIMgr::Tick(float dt) {
	//update UI elements here
	Entity* selected = engine->entityMgr->GetSelected();
	if (selected) {
		std::string entityInfo = "Selected Entity: " + selected->GetPlanet()->name + "\n"
			+ "Simulation speed: " + std::to_string(int(engine->GetSpeed() * 10.0f)) + "\n";
			//if the selected planet isn't the sun
			if (selected->GetPlanet()->index) {
				entityInfo += "Orbit Angle: " + std::to_string(int(selected->GetAngle().valueDegrees())) + "\n";
			}
		entityInfoTB->setText(entityInfo);
	} else {
		entityInfoTB->setText("Selected Entity: None");
	}
}
