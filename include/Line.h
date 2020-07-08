#ifndef LINE_H
#define LINE_H

#include "Core.h"
#include "Point.h"

#include <tuple>

namespace rj {

	/// https://en.wikipedia.org/wiki/Line_(geometry)

	class RJFF_API Line {
	public:

		Line() = default;
		Line(const Line& other) = default;
		Line(Line&& other) = default;

		Line& operator = (const Line& other) = default;
		Line& operator = (Line&& other) = default;

		bool operator == (const Line& other) noexcept;

		~Line() = default;

		void rotate(float degrees) noexcept;

		float getRotation() const noexcept;

		float getM() const noexcept;

		float getB() const noexcept;

		void create(const Point& lhs, const Point& rhs) noexcept;

		bool pointBelongs(const Point& point) const noexcept;

	private:

		float m = 0.f;
		float b = 0.f;
		size_t recurrence = 0;

	};

}

#endif // !LINE_H
