/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * User Interface Manager child class definition
 */

#pragma once

#include "main.h"
#include "engine.h"
#include "mgr.h"

class UIMgr : public Mgr{
	public:
		UIMgr(Engine*);
		~UIMgr();

		Engine *engine;

		void Init();
		void LoadLevel();
		void Tick(float);
		void Stop();
	private:
		OgreBites::TrayManager* trayMgr;

		OgreBites::TextBox* entityInfoTB;

		OgreBites::TextBox* engineControlsTB;
		const std::string engineControls =
				"Welcome to the OGRE engine demo!\n"
				"Press Q or Escape to quit the application";

		OgreBites::TextBox* entityControlsTB;
		const std::string entityControls =
				"Entity Controls:\n"
				"Space: Stop selected entity\n"
				"Up or Numpad 8: Increase Speed\n"
				"Down or Numpad 2: Decrease Speed\n"
				"Left or Numpad 4: Turn Left\n"
				"Right or Numpad 6: Turn Right";

		OgreBites::TextBox* cameraControlsTB;
		std::string cameraControls =
				"W/S: Move Camera Forward and Backward\n"
				"Left Shift + W/S: Pitch Camera Up and Down\n"
				"A/D: Strafe Camera Left and Right\n"
				"Q/E: Yaw Camera Left and Right\n"
				"R/F: Move Camera Up and Down";
};
