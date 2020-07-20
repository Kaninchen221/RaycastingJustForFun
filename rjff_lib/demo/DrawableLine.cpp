#include "DrawableLine.h"

rj::DrawableLine::DrawableLine()
{
	setColor(sf::Color::White);
}

void rj::DrawableLine::setColor(const sf::Color & color)
{
	verticies[0].color = color;
	verticies[1].color = color;
}

void rj::DrawableLine::draw(sf::RenderTarget & target) const
{
	target.draw(verticies.data(), 2, sf::PrimitiveType::Lines);
}
