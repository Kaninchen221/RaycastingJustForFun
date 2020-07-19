#ifndef STATICLINE_H
#define STATICLINE_H

#include "Core.h"

#include "SFML/System/Vector2.hpp"

namespace rj {

	class RJFF_API StaticLine {
	public:

		StaticLine() = default;
		StaticLine(const StaticLine& other) = default;
		StaticLine(StaticLine&& other) = default;

		StaticLine& operator = (const StaticLine& other) = default;
		StaticLine& operator = (StaticLine&& other) = default;
		
		~StaticLine() = default;

		void setFirstPoint(const sf::Vector2f& firstPoint) noexcept;
		sf::Vector2f getFirstPoint() const noexcept;

		void setSecondPoint(const sf::Vector2f& secondPoint) noexcept;
		sf::Vector2f getSecondPoint() const noexcept;

		friend bool operator == (const StaticLine& lhs, const StaticLine& rhs) noexcept;

	private:

		sf::Vector2f firstPoint;
		sf::Vector2f secondPoint;

	};

}

#endif /// !STATICLINE_H
