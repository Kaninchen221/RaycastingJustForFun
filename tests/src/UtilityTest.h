#ifndef UTILITYTEST_H
#define UTILITYTEST_H

#include <gtest/gtest.h>

#include "rjff/Utility.h"

#include <type_traits>

template<class T>
void getRecurrenceAndAssert(T value, T max, std::tuple<T, size_t> expectedValue);



template<class T>
inline void getRecurrenceAndAssert(T value, T max, std::tuple<T, size_t> expectedValue)
{
	static_assert(std::is_arithmetic<T>::value);

	auto result = rj::getRecurrence(value, max);

	T resultRest = std::get<0>(expectedValue);
	size_t resultRecurrence = std::get<1>(expectedValue);

	T expectedRest = std::get<0>(expectedValue);
	size_t expectedRecurrence = std::get<1>(expectedValue);

	if constexpr (std::is_same<T, float>::value) {
		ASSERT_FLOAT_EQ(resultRest, expectedRest);
	}
	else if constexpr (std::is_same<T, double>::value) {
		ASSERT_DOUBLE_EQ(resultRest, expectedRest);
	}
	else {
		ASSERT_EQ(resultRest, expectedRest);
	}

	ASSERT_EQ(resultRecurrence, expectedRecurrence);
}

#endif /// !UTILITYTEST_H