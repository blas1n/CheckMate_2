#include "Math.h"

namespace std {

	float Rad2Deg(float radian) {
		return radian * 180.0f / PI;
	}

	float Deg2Rad(float degree) {
		return degree * PI / 180.0f;
	}

}