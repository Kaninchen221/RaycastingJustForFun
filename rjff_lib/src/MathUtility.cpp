#include "../include/rjff/MathUtility.h"

namespace rj {

	float radiansFromDegrees(float degrees) noexcept
	{
		return degrees * Math::PiValue / 180.f;
	}

	float degreesFromRadians(float radians) noexcept
	{
		return radians * 180.f / Math::PiValue;
	}

	OptPoint intersection(const StaticLine & lhs, const StaticLine & rhs) noexcept
	{
		auto p1 = lhs.getFirstPoint();
		auto p2 = lhs.getSecondPoint();
		auto p3 = rhs.getFirstPoint();
		auto p4 = rhs.getSecondPoint();

		if (isParallel(lhs, rhs)) {
			return std::nullopt;
		}

		float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x));
		if (0 <= t && t <= 1) {
			
			float u = -(((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x)));
			if (0 <= u && u <= 1) {
				
				Point retValue;
				retValue.x = (p3.x + (u * (p4.x - p3.x)));
				retValue.y = (p3.y + (u * (p4.y - p3.y)));
				return retValue;
			}

			return std::nullopt;
		}

		return std::nullopt;

	}

	bool isParallel(const StaticLine & lhs, const StaticLine & rhs) noexcept
	{
		auto p1 = lhs.getFirstPoint();
		auto p2 = lhs.getSecondPoint();
		auto p3 = rhs.getFirstPoint();
		auto p4 = rhs.getSecondPoint();

		float parallel = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
		return (parallel == 0.f);
	}

	OptPoint intersection(const Line & lhs, const Line & rhs) noexcept
	{
		auto lhsRotation = lhs.getRotation();
		auto rhsRotation = rhs.getRotation();

		if (isParallel(lhs, rhs)) {
			return std::nullopt;
		}

		Point intersectionPoint;
		intersectionPoint.x = (rhs.getB() - lhs.getB()) / (lhs.getM() - rhs.getM());
		intersectionPoint.y = (lhs.getM() * intersectionPoint.x) + lhs.getB();

		return intersectionPoint;
	}

	bool isParallel(const Line & lhs, const Line & rhs) noexcept
	{
		auto lhsRotation = lhs.getRotation();
		auto rhsRotation = rhs.getRotation();

		return (lhsRotation == rhsRotation);
	}

	float distance(const Point & lhs, const Point & rhs) noexcept
	{
		return std::sqrt(
			std::pow(rhs.x - lhs.x, 2) +
			std::pow(rhs.y - lhs.y, 2)
		);
	}

}