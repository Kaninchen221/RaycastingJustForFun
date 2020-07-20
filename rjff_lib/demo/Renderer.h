#ifndef RENDERER_H
#define RENDERER_H

#include "Map.h"
#include "Player.h"
#include "Utils.h"

#include "SFML/Graphics/RectangleShape.hpp"

namespace rj {

	class Renderer {
	
	public:

		using Particle = sf::RectangleShape;
		using Particles = std::vector<Particle>;

		Renderer() = default;
		Renderer(const Renderer& other) = default;
		Renderer(Renderer&& other) = default;

		Renderer& operator = (const Renderer& other) = default;
		Renderer& operator = (Renderer&& other) = default;

		~Renderer() = default;

		void update(const Player& player, const Map::Rays& rays);

		void draw(sf::RenderTarget& target);

		void setRenderingStartPoint(const Point& point) noexcept;
		Point getRenderingStartPoint() const noexcept;

		void setRenderingArea(const sf::Vector2f& area) noexcept;
		sf::Vector2f getRenderingArea() const noexcept;

		float getDistanceToRay(const Player& player, const Map::Ray& ray) const noexcept;

		float getLinearScale(const float& distanceToIntersection, const float& rayMaxLength) const noexcept;

		sf::Color linearDarken(sf::Color color, const float& scale) const noexcept;

		sf::Color gammaDarken(sf::Color color, float scale) const noexcept;

		Point getCenterPointOfRendering() const noexcept;


	private:

		Point renderingStartPoint;
		sf::Vector2f renderingArea;

		Particles particles;

		void prepareParticles(const size_t& particlesCount);

		void drawParticles(sf::RenderTarget& target);


	};

}

#endif /// !RENDERER_H