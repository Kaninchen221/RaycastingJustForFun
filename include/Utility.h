#ifndef UTILITY_H
#define UTILITY_H

#include <tuple>

namespace rj {

	template<class T>
	inline std::tuple<T, size_t> getRecurrence(T val, T max) noexcept;




	template<class T>
	std::tuple<T, size_t> getRecurrence(T val, T max) noexcept
	{
		size_t counter = 0u;
		while (val > max) {
			val -= max;
			++counter;
		}

		return { val, counter };
	}

}

#endif /// !UTILITY_H