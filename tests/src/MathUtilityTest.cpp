#include "MathUtilityTest.h"

TEST_F(MathUtilityTest, DegreesToRadians) {

	float degrees;

	degrees = 10.f;
	ASSERT_FLOAT_EQ(rj::radiansFromDegrees(degrees), 0.174532925f);

	degrees = 631.f;
	ASSERT_FLOAT_EQ(rj::radiansFromDegrees(degrees), 11.0130276f);
}

TEST_F(MathUtilityTest, RadiansToDegrees) {

	float radians;

	radians = 10.f;
	ASSERT_FLOAT_EQ(rj::degreesFromRadians(radians), 572.957795f);

	radians = 3.23f;
	ASSERT_FLOAT_EQ(rj::degreesFromRadians(radians), 185.065368f);
}