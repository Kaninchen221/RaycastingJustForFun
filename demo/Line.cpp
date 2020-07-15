#include "Line.h"

namespace rj {

	Point rj::Line::getFirstPoint() const noexcept
	{
		return this->getTransform().transformPoint(firstPoint);
	}

	Point Line::getSecondPoint() const noexcept
	{
		return this->getTransform().transformPoint(secondPoint);
	}

	StaticLine Line::toStaticLine() const noexcept
	{
		StaticLine staticLine;
		staticLine.setFirstPoint(this->getFirstPoint());
		staticLine.setSecondPoint(this->getSecondPoint());

		return staticLine;
	}

	void Line::setLength(const float & value) noexcept
	{
		//setOrigin(value / 2.f, 0.f);
		secondPoint = firstPoint;
		secondPoint.x += value;
		//secondPoint = Point(value, 0.f);
	}

	float Line::getLength() const noexcept
	{
		return secondPoint.x;
	}

} /// namespace rj