#ifndef POINT_H
#define POINT_H

#include <SFML/System/Vector2.hpp>

#include <optional>

namespace rj {
	
	using Point = sf::Vector2f;
	using OptPoint = std::optional<Point>;

}

#endif /// !POINT_H