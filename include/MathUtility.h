#ifndef MATHUTILITY_H
#define MATHUTILITY_H

//#define _USE_MATH_DEFINES
//#include <math.h>
//#include <cmath>

#include "Core.h"

namespace rj {

	struct RJFF_API Math {

		inline static constexpr float PiValue = 3.14159265358979323846f;

	};

	float radiansFromDegrees(float degrees) noexcept;

	float degreesFromRadians(float radians) noexcept;

}

#endif // !MATHUTILITY_H
