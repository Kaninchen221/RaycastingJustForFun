#include "Utils.h"

#include <cmath>

namespace rj {

	float distance(const Point & lhs, const Point & rhs) noexcept
	{
		return std::sqrt(
			std::pow(rhs.x - lhs.x, 2) +
			std::pow(rhs.y - lhs.y, 2)
		);
	}

	bool collision(const Point & lhs, const Point & rhs) noexcept
	{
		if (lhs == rhs) {
			return true;
		}

		return false;
	}

	bool collision(const Point & lhs, const Point & rhs, const float & additional_zone) noexcept
	{
		auto dist_val = distance(lhs, rhs);

		if (dist_val <= additional_zone) {
			return true;
		}

		return false;
	}

	OptPoint intersection(const StaticLine & lhs, const StaticLine & rhs) noexcept
	{
		auto p1 = lhs.getFirstPoint();
		auto p2 = lhs.getSecondPoint();
		auto p3 = rhs.getFirstPoint();
		auto p4 = rhs.getSecondPoint();

		float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
		if (den == 0) {
			return std::nullopt;
		}
		float t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x));
		//std::cout << "T value: " << t << "\n";
		if (0 <= t && t <= 1) {
			float u = -(((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / ((p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x)));
			if (0 <= u && u <= 1) {
				//std::cout << "U value: " << u << "\n";
				Point retValue;
				retValue.x = (p3.x + (u * (p4.x - p3.x)));
				retValue.y = (p3.y + (u * (p4.y - p3.y)));
				return retValue;
			}
			return std::nullopt;
		}
		return std::nullopt;
	}

	float gammaCorrection(const float & gamma, const float & value)
	{
		return std::pow(value, gamma);
	}

	Point centerOfLine(const Point & lhs, const Point & rhs) noexcept
	{
		return {
			(lhs.x + rhs.x) / 2.f,
			(rhs.y + rhs.y) / 2.f
		};
	}

}