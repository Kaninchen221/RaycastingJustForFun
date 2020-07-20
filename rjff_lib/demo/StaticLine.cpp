#include "StaticLine.h"

namespace rj {

	void StaticLine::setFirstPoint(const sf::Vector2f & value) noexcept
	{
		firstPoint = value;
	}

	void StaticLine::setSecondPoint(const sf::Vector2f & value) noexcept
	{
		secondPoint = value;
	}

	Point StaticLine::getFirstPoint() const noexcept
	{
		return firstPoint;
	}

	Point StaticLine::getSecondPoint() const noexcept
	{
		return secondPoint;
	}

	//void StaticLine::draw(sf::RenderTarget & target) const
	//{
	//	sf::Vertex verticies[2];
	//	verticies[0].color = sf::Color::White;
	//	verticies[1].color = sf::Color::White;
	//	verticies[0].position = getFirstPoint();
	//	verticies[1].position = getSecondPoint();
	//
	//	target.draw(verticies, 2, sf::PrimitiveType::Lines);
	//}

}