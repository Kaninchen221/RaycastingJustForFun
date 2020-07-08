#include "..\include\MathUtility.h"

float rj::radiansFromDegrees(float degrees) noexcept
{
	return degrees * Math::PiValue / 180.f;
}

float rj::degreesFromRadians(float radians) noexcept
{
	return radians * 180.f / Math::PiValue;
}
