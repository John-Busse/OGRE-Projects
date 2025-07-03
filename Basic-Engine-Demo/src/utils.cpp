/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Basic Game Engine Demo
 * Utilities declaration
 */

#include "utils.h"

float FixAngle(float angle) {
	if (angle < 0)
		return angle + 360;
	else if (angle > 360)
		return angle - 360;
	return angle;
}

float Clamp(float min, float max, float val) {
	if (val < min)
		return min;
	else if (val > max)
		return max;
	return val;
}

bool IsApproxEqual(float a, float b, float epsilon) {
	return std::abs(a - b) < epsilon;
}
