#include "../include/rjff/StaticLine.h"

namespace rj {

	void StaticLine::setFirstPoint(const sf::Vector2f& firstPoint) noexcept
	{
		this->firstPoint = firstPoint;
	}

	sf::Vector2f StaticLine::getFirstPoint() const noexcept
	{
		return firstPoint;
	}

	void StaticLine::setSecondPoint(const sf::Vector2f & secondPoint) noexcept
	{
		this->secondPoint = secondPoint;
	}

	sf::Vector2f StaticLine::getSecondPoint() const noexcept
	{
		return secondPoint;
	}

	bool operator==(const StaticLine & lhs, const StaticLine & rhs) noexcept
	{
		return (lhs.firstPoint == rhs.firstPoint && lhs.secondPoint == rhs.secondPoint);
	}

}