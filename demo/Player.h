#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include "Point.h"

namespace rj {

	class Player : public sf::Transformable {
	public:

		Player() = default;
		Player(const Player& other) = default;
		Player(Player&& other) = default;

		Player& operator = (const Player& other) = default;
		Player& operator = (Player&& other) = default;

		~Player() = default;

		void   setRaysCount(const size_t& value) noexcept;
		size_t getRaysCount() const noexcept;

		void   setFieldOfView(const float& value) noexcept;
		float  getFieldOfView() const noexcept;

		void   setRayLength(const float& length) noexcept;
		float  getRayLength() const noexcept;

		void setMinimalRayLength(const float& value) noexcept;
		float getMinimalRayLength() const noexcept;

		void draw(sf::RenderTarget & target, sf::RenderStates states = sf::RenderStates::Default) const;

		sf::RectangleShape createGraphicalRepresentation(const sf::Vector2f& size) const;

	private:

		float fieldOfView = 45.f;

		size_t raysCount = 500;
		float rayLength = 400.f;
		float minimalRayLength = 2.f;

	};

}

#endif /// !PLAYER_H