#ifndef DRAWABLELINE_H
#define DRAWABLELINE_H

#include "Line.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Vertex.hpp"

namespace rj {

	struct DrawableLine {

		DrawableLine();
		DrawableLine(const DrawableLine& other) = default;
		DrawableLine(DrawableLine&& other) = default;

		DrawableLine& operator = (const DrawableLine& other) = default;
		DrawableLine& operator = (DrawableLine&& other) = default;
		
		~DrawableLine() = default;

		template<class LineT = Line>
		void createFromLine(const LineT& in);

		void setColor(const sf::Color& color);

		void draw(sf::RenderTarget& target) const;

	protected:

		std::array<sf::Vertex, 2> verticies;

	};

	template<class LineT>
	inline void DrawableLine::createFromLine(const LineT & in)
	{
		verticies[0].position = in.getFirstPoint();
		verticies[1].position = in.getSecondPoint();
	}

} /// namespace rj

#endif /// !DRAWABLELINE_H