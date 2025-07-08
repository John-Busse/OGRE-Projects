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
	delete trayMgr;
	trayMgr = nullptr;
	delete entityInfoTB;
	entityInfoTB = nullptr;
	delete engineControlsTB;
	engineControlsTB = nullptr;
}

void UIMgr::Init() {
	trayMgr = new OgreBites::TrayManager("UI Manager", engine->gfxMgr->getRenderWindow());
	engine->gfxMgr->addInputListener(trayMgr);
}

void UIMgr::Load() {
	trayMgr->hideCursor();

	//load UI elements
	//engine controls
	engineControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_TOPRIGHT, "EngineControls", "Engine Controls", 350, 110);
	engineControlsTB->setText(engineControls);

	// entity controls text box
	entityControlsTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_BOTTOMLEFT, "EntityControls", "Entity Controls", 350, 175);
	entityControlsTB->setText(entityControls);

	//entity info text box
	std::string entityTBContent = "Selected Entity: None\n";
	entityInfoTB = trayMgr->createTextBox(OgreBites::TrayLocation::TL_BOTTOMRIGHT, "EntityInfo", "Entity Info", 300, 160);
	entityInfoTB->setText(entityTBContent);
}

void UIMgr::Tick(float dt) {
	//update UI elements here
	PlanetInfo* info = engine->entityMgr->GetSelected()->GetPlanet();
	if (info) {
		std::string entityInfo = "Selected Entity: " + info->name + "\n"
			+ "Simulation speed: "; //TODO: get simSpeed from SimMgr
		entityInfoTB->setText(entityInfo);
	} else {
		entityInfoTB->setText("Selected Entity: None");
	}
}

void UIMgr::Stop() {

}
