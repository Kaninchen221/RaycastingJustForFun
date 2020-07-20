#ifndef UTILS_H
#define UTILS_H

#include "StaticLine.h"
#include "Point.h"

#include <optional>

namespace rj {

	typedef std::optional<Point> OptPoint;

	float distance(const Point& lhs, const Point& rhs) noexcept;

	bool collision(const Point& lhs, const Point& rhs) noexcept;

	bool collision(const Point& lhs, const Point& rhs, const float& additional_zone) noexcept;

	OptPoint intersection(const StaticLine& lhs, const StaticLine& rhs) noexcept;

	float gammaCorrection(const float& gamma, const float& value);

	Point centerOfLine(const Point& lhs, const Point& rhs) noexcept;

}

#endif /// !UTILS_H