/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Utilities declaration
*/
#pragma once

#include <cmath>

template <typename T> T FixAngle(T angle) {
	if (angle < 0)
		return angle + 360;
	else if (angle > 360)
		return angle - 360;
	return angle;
}

template <typename T> T Clamp(T min, T max, T val) {
	if (val < min)
		return min;
	else if (val > max)
		return max;
	return val;
}
