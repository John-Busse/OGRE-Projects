/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * UI Manager class declaration
*/
#pragma once

#include "main.h"
#include "mgr.h"

//forward declaration
class Engine;

class UIMgr : public Mgr {
	public:
		UIMgr(Engine*);
		~UIMgr();

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop();
	private:
		OgreBites::TrayManager* trayMgr;

		OgreBites::TextBox* entityInfoTB;

		OgreBites::TextBox* engineControlsTB;
		const std::string engineControls =
				"OGRE Solar System Render\n"
				"Press Escape to quit the application";

		OgreBites::TextBox* entityControlsTB;
		const std::string entityControls =
				"Controls:\n"
				"Space: Reset the viewing angle\n"
				"Left/Right arrows: Adjust simulation speed\n"
				"0-9: Select specific planet\n"
				"W/S: Zoom in/out\n"
				"A/D: Rotate camera left/right\n"
				"R/F: Rotate camera up/down";
};
