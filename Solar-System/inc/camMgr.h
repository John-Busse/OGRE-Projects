/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Camera Manager class declaration
*/
#pragma once

#include "main.h"
#include "mgr.h"

class CamMgr : public Mgr {
	public:
		CamMgr(Engine *engine);
		~CamMgr();

		void Init() override;
		void Load() override;
		void Tick(float) override;
		void Stop() override;

		void ResetAngle();

		void SetPos(Ogre::Vector3 pos);
		void SetRadius(float planetScale);

		void MoveX(bool right, float delta);
		void MoveY(bool up, float delta);
		void MoveZ(bool in, float scale, float delta);

		bool GetUpdateCam() { return updateCam; }
		void SetUpdateCam(bool val) { updateCam = val; }
	private:
		Ogre::SceneNode* cameraNode;

		Ogre::Vector3 camPos;
		Ogre::Vector3 focusPos;

		float radius;
		Ogre::Degree theta, phi;
		bool updateCam;
};
