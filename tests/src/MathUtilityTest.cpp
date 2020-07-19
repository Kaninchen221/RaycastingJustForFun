#include "MathUtilityTest.h"

#include "rjff/StaticLine.h"
#include "rjff/Line.h"

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

TEST_F(MathUtilityTest, intersectionStaticLineStaticLineTest) {

	rj::StaticLine firstStaticLine;
	firstStaticLine.setFirstPoint({ 0.f, 0.f });
	firstStaticLine.setSecondPoint({ 10.f, 0.f });

	rj::StaticLine secondStaticLine;
	secondStaticLine.setFirstPoint({ 5.f, -10.f });
	secondStaticLine.setSecondPoint({ 5.f, 10.f });

	rj::OptPoint intersectionPoint;
	intersectionPoint = intersection(firstStaticLine, secondStaticLine);

	rj::Point expectedPoint = { 5.f, 0.f };
	
	ASSERT_TRUE(intersectionPoint.has_value());
	ASSERT_TRUE(intersectionPoint.value() == expectedPoint);
}

TEST_F(MathUtilityTest, isParallelStaticLineStaticLineTest) {

	rj::StaticLine firstStaticLine;
	firstStaticLine.setFirstPoint({ 0.f, 0.f });
	firstStaticLine.setSecondPoint({ 10.f, 0.f });

	rj::StaticLine secondStaticLine;
	secondStaticLine.setFirstPoint({ 5.f, 10.f });
	secondStaticLine.setSecondPoint({ 15.f, 10.f });

	bool parallel = isParallel(firstStaticLine, secondStaticLine);
	ASSERT_TRUE(parallel);
}

TEST_F(MathUtilityTest, intersectionLineLineTest) {

	rj::Line firstLine;
	firstLine.create({ 23.f, 21.73f }, { 10.f, 10.f });

	rj::Line secondLine;
	secondLine.create({ -10.f, -14.f }, { -40.f, -45.21f });

	rj::Point expectedPoint;
	rj::OptPoint intersectionResult;

	expectedPoint = { 33.136f, 30.876f };
	intersectionResult = rj::intersection(firstLine, secondLine);

	ASSERT_TRUE(intersectionResult.has_value());

	auto intersectionPoint = intersectionResult.value();

	ASSERT_NEAR(intersectionPoint.x, expectedPoint.x, 0.01f);
	ASSERT_NEAR(intersectionPoint.y, expectedPoint.y, 0.01f);
}

TEST_F(MathUtilityTest, isParallelLineLineTest) {

	rj::Line firstLine;
	firstLine.create({ 5.f, 5.f }, { 7.f, 7.f });

	rj::Line secondLine;
	secondLine.create({ 3.f, 3.f }, { 5.f, 5.f });

	ASSERT_TRUE(rj::isParallel(firstLine, secondLine));
}

TEST_F(MathUtilityTest, distanceTest) {

	auto firstPoint = rj::Point(10.f, 10.f);
	auto secondPoint = rj::Point(15.f, 10.f);

	auto distance = rj::distance(firstPoint, secondPoint);
	float expected = 5.f;

	ASSERT_FLOAT_EQ(distance, expected);

	secondPoint = rj::Point(15.f, 15.f);
	
	distance = rj::distance(firstPoint, secondPoint);
	expected = 5.f * std::sqrtf(2);

	ASSERT_FLOAT_EQ(distance, expected);
}