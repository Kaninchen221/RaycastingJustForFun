#ifndef STATICLINE_H
#define STATICLINE_H

#include "Point.h"

#include <array>

namespace rj {

	class StaticLine {

	public:

		StaticLine() = default;
		StaticLine(const StaticLine& other) = default;
		StaticLine(StaticLine&& other) = default;

		StaticLine& operator = (const StaticLine& other) = default;
		StaticLine& operator = (StaticLine&& other) = default;

		~StaticLine() = default;

		void setFirstPoint(const sf::Vector2f& value) noexcept;
		void setSecondPoint(const sf::Vector2f& value) noexcept;

		Point getFirstPoint() const noexcept;
		Point getSecondPoint() const noexcept;

	protected:

		sf::Vector2f firstPoint;
		sf::Vector2f secondPoint;

	};

}

#endif /// !STATICLINE_H
