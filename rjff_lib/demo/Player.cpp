#include "Player.h"

namespace rj {

	void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		auto graphicalRepresentation = createGraphicalRepresentation({ 14.f, 14.f });

		target.draw(graphicalRepresentation, states);
	}

	sf::RectangleShape Player::createGraphicalRepresentation(const sf::Vector2f& size) const
	{
		sf::RectangleShape rectangle;
		rectangle.setSize(size);
		rectangle.setFillColor(sf::Color::White);
		rectangle.setOrigin(sf::Vector2f(size.x / 2.f, size.y / 2.f));

		return rectangle;
	}

	void Player::setRaysCount(const size_t & value) noexcept
	{
		raysCount = value;
	}

	void Player::setFieldOfView(const float & value) noexcept
	{
		fieldOfView = value;
	}

	size_t Player::getRaysCount() const noexcept
	{
		return raysCount;
	}

	float Player::getFieldOfView() const noexcept
	{
		return fieldOfView;
	}

	void Player::setRayLength(const float & length) noexcept
	{
		rayLength = length;
	}

	float Player::getRayLength() const noexcept
	{
		return rayLength;
	}

	void Player::setMinimalRayLength(const float & value) noexcept
	{
		minimalRayLength = value;
	}

	float Player::getMinimalRayLength() const noexcept
	{
		return minimalRayLength;
	}


} /// namespace rj