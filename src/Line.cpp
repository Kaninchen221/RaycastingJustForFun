#include "../include/Line.h"

#include "../include/MathUtility.h"
#include "../include/Utility.h"

#include <cmath>

namespace rj {

	bool Line::operator==(const Line & other) noexcept
	{
		if (m == other.m) {
			if (b == other.b) {

				if (recurrence == other.recurrence)
					return true;
				else if (other.recurrence != 0u) 
					if (recurrence % other.recurrence == 0u)
						return true;
				else if (recurrence != 0u)
					if (other.recurrence % recurrence == 0u)
						return true;
				
			}
		}

		return false;
	}

	void Line::rotate(float degrees) noexcept
	{
		auto recurrancePack = getRecurrence(degrees, 45.f);
		degrees = std::get<0>(recurrancePack);
		recurrence = std::get<1>(recurrancePack);
		
		float radians = radiansFromDegrees(degrees);
		m += std::tanf(radians);

	}

	float Line::getRotation() const noexcept
	{
		float radians = std::atanf(m);
		float degrees = degreesFromRadians(radians) + (45.f * recurrence);

		return degrees;
	}

	float Line::getM() const noexcept
	{
		return m;
	}

	float Line::getB() const noexcept
	{
		return b;
	}

	void Line::create(const Point & lhs, const Point & rhs) noexcept
	{
		m = (rhs.y - lhs.y) / (rhs.x - lhs.x);
		b = rhs.y - (m * rhs.x);
	}

	bool Line::pointBelongs(const Point& point) const noexcept
	{
		float y = m * point.x + b;

		return (y == point.y);
	}

}