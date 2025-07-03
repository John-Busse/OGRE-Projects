/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Utilities declaration
 */

#pragma once

#include <cmath>

float FixAngle(float angle);
float Clamp(float min, float max, float val);
bool IsApproxEqual(float a, float b, float epsilon = 0.1f);
