/*
 * John Busse itsjohnabusse@gmail.com
 * OGRE Solar System
 * Utilities declaration
*/
#pragma once

#include <cmath>

float FixAngle(float angle);

template <typename T> T Clamp(T min, T max, T val) {
	if (val < min)
		return min;
	else if (val > max)
		return max;
	return val;
}

//template class <int>;
//template class <float>;
