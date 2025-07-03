/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Aspect class declaration
 */

#include "aspect.h"

void Renderable::Tick(float dt) {
	entity->GetSceneNode()->setPosition(entity->GetPosition()); // Update the sceneNode position
	entity->GetSceneNode()->resetOrientation(); // Reset orientation to apply new heading
	entity->GetSceneNode()->yaw(Ogre::Degree(-entity->GetHeading())); // Apply heading as yaw

	// Show or hide bounding box based on selection state
	entity->GetSceneNode()->showBoundingBox(entity->GetSelected());
}

void Physics2D::Tick(float dt) {
	// Update speed based on desired speed
	if (entity->GetDesiredSpeed() > entity->GetSpeed())
		entity->IncrementSpeed(dt);
	else if (entity->GetDesiredSpeed() < entity->GetSpeed())
		entity->IncrementSpeed(-dt);
	if (IsApproxEqual(entity->GetDesiredSpeed(), entity->GetSpeed()))
		entity->SetSpeed(entity->GetDesiredSpeed()); // Snap to desired speed if close enough

	// Update heading based on desired heading
	if (entity->GetDesiredHeading() > entity->GetHeading()) {
		if (std::abs(entity->GetDesiredHeading() - entity->GetHeading()) <= 180)
			entity->IncrementHeading(dt);
		else
			entity->IncrementHeading(-dt);
	} else {
		if (std::abs(entity->GetDesiredHeading() - entity->GetHeading()) <= 180)
			entity->IncrementHeading(-dt);
		else
			entity->IncrementHeading(dt);
	}
	if (IsApproxEqual(entity->GetDesiredHeading(), entity->GetHeading(), 1.0f))
		entity->SetHeading(entity->GetDesiredHeading()); // Snap to desired heading if close enough

	// Calculate velocity based on speed and heading
	Ogre::Vector3 newVelocity = Ogre::Vector3::ZERO;
	newVelocity.x = Ogre::Math::Cos(Ogre::Degree(entity->GetHeading())) * entity->GetSpeed(); // Adjacent/hypotenuse
	newVelocity.z = Ogre::Math::Sin(Ogre::Degree(entity->GetHeading())) * entity->GetSpeed(); // Opposite/hypotenuse

	// Update position based on velocity
	entity->SetPosition(newVelocity * dt);
}
