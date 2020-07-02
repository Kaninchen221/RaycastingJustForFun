#ifndef LINE_H
#define LINE_H

#include "SFML/Graphics/Transformable.hpp"

#include "StaticLine.h"

namespace rj {

	struct Line : public StaticLine, public sf::Transformable {

		Line() = default;
		Line(const Line& other) = default;
		Line(Line&& other) = default;

		Line& operator = (const Line& other) = default;
		Line& operator = (Line&& other) = default;

		~Line() = default;

		Point getFirstPoint() const noexcept;
		Point getSecondPoint() const noexcept;

		StaticLine toStaticLine() const noexcept;

	protected:

	}; /// class Line

} /// namespace rj

#endif // !LINE_H
