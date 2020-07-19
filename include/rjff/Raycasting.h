#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "Camera.h"
#include "Line.h"
#include "MathUtility.h"

#include <vector>

namespace rj {

	template<class Iterator = std::vector<StaticLine>::iterator>
	class Raycasting {
	public:

		struct CastingProperties {
			Camera camera;
			Iterator begin;
			Iterator end;
		};

		struct IntersectionInfo {
			Iterator element;
			OptPoint point;
			float distance;
		};

		using CastingResult = std::vector<IntersectionInfo>;

		Raycasting() = default;
		Raycasting(const Raycasting& other) = delete;
		Raycasting(Raycasting&& other) = delete;

		Raycasting& operator = (const Raycasting& other) = delete;
		Raycasting& operator = (Raycasting&& other) = delete;

		~Raycasting() = default;

		CastingResult castingRays(CastingProperties properties) const noexcept;

	private:

		using Rays = std::vector<StaticLine>;

		Rays createRays(const Camera& camera) const noexcept;

	};

	template<class Iterator>
	inline typename Raycasting<Iterator>::CastingResult Raycasting<Iterator>::castingRays(CastingProperties properties) const noexcept
	{
		auto rays = createRays(properties.camera);

		CastingResult castingResult;
		IntersectionInfo intersectionInfoToSave;
		intersectionInfoToSave.distance = properties.camera.getRaysLength();
		intersectionInfoToSave.element = properties.end;
		auto ray = rays.cbegin();
		auto wall = properties.begin;
		while (ray != rays.cend()) {

			while (wall != properties.end) {

				auto intersectionPoint = intersection(*ray, *wall);
				if (intersectionPoint.has_value()) {

					float distanceToIntersection = distance(intersectionPoint.value(), properties.camera.getPosition());

					if (distanceToIntersection < intersectionInfoToSave.distance) {

						intersectionInfoToSave.element = wall;
						intersectionInfoToSave.point = intersectionPoint.value();
						intersectionInfoToSave.distance = distanceToIntersection;
					
					}

				}

				++wall;
			}
			castingResult.push_back(intersectionInfoToSave);

			auto wall = properties.begin;
			++ray;
		}

		return castingResult;
	}

	template<class Iterator>
	inline typename Raycasting<Iterator>::Rays Raycasting<Iterator>::createRays(const Camera & camera) const noexcept
	{
		Rays rays;

		auto position = camera.getPosition();
		auto fieldOfView = camera.getFieldOfView();
		auto raysCount = camera.getRaysCount();
		auto raysLength = camera.getRaysLength();

		float x = position.x - ((raysLength / 2.f) * fieldOfView);
		float x_step = raysLength * fieldOfView / raysCount;
		for (size_t currentRay = 0u; currentRay < camera.getRaysCount(); ++currentRay) {

			float y;
			y = std::sqrt((raysLength*raysLength) - (x*x) + (2 * position.x*x) - (position.x*position.x)) + position.y;
			
			StaticLine line;
			line.setFirstPoint({ x, y });
			line.setSecondPoint(position);
			rays.push_back(line);

			x += x_step;
		}

		return rays;
	}

}

#endif /// !RAYCASTING_H