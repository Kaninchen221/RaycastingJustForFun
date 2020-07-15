#ifndef MAP_H
#define MAP_H

#include "DrawableLine.h"
#include "Point.h"
#include "Player.h"
#include "Utils.h"

#include <vector>
#include <memory>
#include <utility>

namespace rj {

	class Map {

	public:
	
		using Wall	= StaticLine;
		using Walls = std::vector<Wall>;

		template<class IntersectionObject>
		struct IntersectionInfo {

			Point coordinates;
			IntersectionObject pointerToObject = nullptr;

		};

		using WallsIntersections = std::vector<IntersectionInfo<Wall*>>;

		using Ray = Line;
		using Rays = std::vector<Ray>;
	
		Map() = default;
		Map(const Map& other) = default;
		Map(Map&& other) = default;
	
		Map& operator = (const Map& other) = default;
		Map& operator = (Map&& other) = default;
	
		~Map() = default;

		void update(const Player& player);

		void addWall(const Wall& wall);

		void drawWalls(sf::RenderTarget& target) const;

		void drawRays(sf::RenderTarget& target, const Player& player) const;

		void drawLeveler(sf::RenderTarget& target) const;

		const WallsIntersections& getIntersections() const noexcept;

		const Rays& getRays() const noexcept;

	private:

		void initRay(Ray& ray, const Player& player);

		void initLeveler(const Player& player);

		void updateRay(Ray& ray, const Player& player);

		void castRays(Ray& ray, const Player& player);

		IntersectionInfo<Wall*> getIntersection(Ray& ray, Wall& wall) const noexcept;

		bool reduceRayIfIntersectionIsCloser(Ray& ray, const Point& intersectionPoint);

		Walls walls;
		WallsIntersections wallsIntersections;

		Rays rays;
		Ray levelerRay;

	};

}

#endif /// !MAP_H