#ifndef LINETEST_H
#define LINETEST_H

#include <gtest/gtest.h>

#include "rjff/Line.h"

class LineTest : public ::testing::Test {
protected:

	LineTest() = default;

	~LineTest() = default;

	void rotateAndAssert(const float& degress);

	struct CreateAndAssertData {
		rj::Point lhs;
		rj::Point rhs;
		float expected_m;
		float expected_b;
	};

	void createAndAssert(const CreateAndAssertData& data);

};

#endif /// !LINETEST_H