#ifndef MATHUTILITY_H
#define MATHUTILITY_H

#include "Core.h"
#include "Line.h"
#include "StaticLine.h"

namespace rj {

	struct RJFF_API Math {

		inline static constexpr float PiValue = 3.14159265358979323846f;

	};

	float radiansFromDegrees(float degrees) noexcept;

	float degreesFromRadians(float radians) noexcept;

	OptPoint intersection(const StaticLine& lhs, const StaticLine& rhs) noexcept;

	bool isParallel(const StaticLine& lhs, const StaticLine& rhs) noexcept;

	OptPoint intersection(const Line& lhs, const Line& rhs) noexcept;

	bool isParallel(const Line& lhs, const Line& rhs) noexcept;

	float distance(const Point& lhs, const Point& rhs) noexcept;

}

#endif // !MATHUTILITY_H
