#include "map.h"

#include <iostream>
#include <functional>
#include <iostream>

#include "SFML/Graphics/RenderTarget.hpp"

#include "Error.h"
#include "DrawableLine.h"

namespace rj {

	void Map::addWall(const Wall & wall)
	{
		walls.push_back(wall);
	}

	void Map::update(const Player& player)
	{

		Ray ray;
		initRay(ray, player);

		initLeveler(player);

		castRays(ray, player);

	}

	void Map::initRay(Ray& ray, const Player& player)
	{
		/// Left to right
		ray.setLength(player.getRayLength());
		ray.setOrigin({ 0.f, player.getFieldOfView() / -2.f });
		ray.setPosition(player.getPosition());
		
		ray.rotate(player.getRotation());
		/// Left to right
	}

	void Map::initLeveler(const Player & player)
	{
		Ray ray;

		ray.setLength(player.getFieldOfView());
		ray.setOrigin(player.getPosition());
		ray.move({ player.getFieldOfView() / 2.f, 0.f });
		ray.rotate(player.getRotation() - 90.f);

		levelerRay = ray;
	}

	void Map::updateRay(Ray & ray, const Player & player)
	{
		/// Left to right
		ray.setLength(player.getRayLength());
		auto origin = ray.getOrigin();
		origin.y += player.getFieldOfView() / player.getRaysCount();
		ray.setOrigin(origin);
		/// Left to right
	}

	void Map::castRays(Ray & ray, const Player& player)
	{
		rays.clear();
		rays.reserve(player.getRaysCount());

		wallsIntersections.clear();
		wallsIntersections.reserve(player.getRaysCount());

		IntersectionInfo<Wall*> intersection;
		intersection.coordinates = ray.getSecondPoint();
		IntersectionInfo<Wall*> intersectionToSave = intersection;

		for (auto currentRay = 0u; currentRay < player.getRaysCount(); currentRay++) {

			intersection.coordinates = ray.getSecondPoint();
			intersectionToSave = intersection;
			
			for (auto& wall : walls) {
				
				intersection = getIntersection(ray, wall);
			
				if (intersection.pointerToObject) {
					reduceRayIfIntersectionIsCloser(ray, intersection.coordinates);
					intersectionToSave = intersection;
				}
				
			}

			rays.push_back(ray);
			wallsIntersections.push_back(intersectionToSave);

			updateRay(ray, player);

		}

	}

	void Map::drawWalls(sf::RenderTarget & target) const
	{
		for (const auto& wall : walls) {

			DrawableLine drawableLine;
			drawableLine.createFromLine(wall);

			drawableLine.draw(target);

		}
	}

	void Map::drawRays(sf::RenderTarget & target, const Player& player) const
	{
		for (const auto& ray : rays) {

			DrawableLine drawableLine;
			drawableLine.createFromLine<Line>(ray);

			drawableLine.draw(target);
		}
	}

	void Map::drawLeveler(sf::RenderTarget & target) const
	{
		DrawableLine rayToDraw;
		rayToDraw.setColor(sf::Color::Yellow);
		rayToDraw.createFromLine(levelerRay);
		rayToDraw.draw(target);
	}

	const Map::WallsIntersections & Map::getIntersections() const noexcept
	{
		return wallsIntersections;
	}

	const Map::Rays & Map::getRays() const noexcept
	{
		return rays;
	}

	Map::IntersectionInfo<Map::Wall*> Map::getIntersection(Ray & ray, Wall& wall) const noexcept
	{
		auto optPoint = intersection(ray.toStaticLine(), wall);
	
		IntersectionInfo<Wall*> intersectionInfo;

		if (optPoint.has_value()) {
			intersectionInfo.coordinates = optPoint.value();
			intersectionInfo.pointerToObject = &wall;
		}
		else {
			intersectionInfo.pointerToObject = nullptr;
		}

		return intersectionInfo;
		
	}

	bool Map::reduceRayIfIntersectionIsCloser(Ray & ray, const Point & intersectionPoint)
	{
		auto proposedLength = distance(ray.getFirstPoint(), intersectionPoint);
		auto rayLength = distance(ray.getFirstPoint(), ray.getSecondPoint());

		if (proposedLength < rayLength) {
			ray.setLength(proposedLength);
			return true;
		}

		return false;
	}

} /// namespace rj