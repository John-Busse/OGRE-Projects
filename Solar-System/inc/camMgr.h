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

		void Load() override;
		void Tick(float dt) override;

		void ResetAngle();

		Ogre::Vector3 GetPos() const { return camPos; }
		Ogre::Vector3 GetFocus() const { return focusPos; }
		/*Updates the camera position and focus position
		*/
		void SetPos(Ogre::Vector3 planetPos);
		void SetRadius(float planetScale);

		//rotate camera left or right (x-axis) with A and D keys
		void MoveX(bool right, float delta);
		//rotate camera up or down (y-axis) with R and F keys
		void MoveY(bool up, float delta);
		//zoom camera in or out (z-axis) with W and S keys
		//zoom is multipled by the planet scale for more consistent movement
		void MoveZ(bool in, float scale, float delta);

		Ogre::SceneNode* getCameraNode() const {return cameraNode;}

		bool GetUpdateCam() const { return updateCam; }
		void SetUpdateCam(bool val) { updateCam = val; }
	private:
		Ogre::SceneNode* cameraNode;

		Ogre::Vector3 camPos;
		Ogre::Vector3 focusPos;

		float radius;
		Ogre::Degree theta, phi;
		bool updateCam;
};
