#include "LineTest.h"

TEST_F(LineTest, rotateTests) {
	rotateAndAssert(0.f);
	rotateAndAssert(45.f);
	rotateAndAssert(-59.f);
	rotateAndAssert(90.f);
	rotateAndAssert(180.f);
	rotateAndAssert(270.f);
	rotateAndAssert(360.f);
	rotateAndAssert(30.f);
	rotateAndAssert(357.f);
}

void LineTest::rotateAndAssert(const float & degress)
{
	rj::Line line;
	line.rotate(degress);
	ASSERT_NEAR(line.getRotation(), degress, 0.02f);
}

TEST_F(LineTest, createFromTwoPointsTests) {

	CreateAndAssertData testData;

	testData = {
		{1.f, 1.f}, {-1.f, -1.f},
		1.f, 0.f
	};
	createAndAssert(testData);

	testData = {
		{57.f, -21.058f}, {-200.013f, -10.5f},
		-0.041079634f, -18.716460856f
	};
	createAndAssert(testData);
}

void LineTest::createAndAssert(const CreateAndAssertData & data)
{
	rj::Line line;
	line.create(data.lhs, data.rhs);

	ASSERT_FLOAT_EQ(line.getM(), data.expected_m);
	ASSERT_FLOAT_EQ(line.getB(), data.expected_b);
}

TEST_F(LineTest, pointBelongsTest) {

	rj::Line line;
	line.create({ 57.f, -21.058f }, { -200.013f, -10.5f });
	rj::Point point;

	point = { 3.50164f, -18.860306955f };
	ASSERT_TRUE(line.pointBelongs(point));

	point = { 10.50f, 18.860f };
	ASSERT_FALSE(line.pointBelongs(point));
}

TEST_F(LineTest, assignAndComparisonTest) {

	rj::Line line;
	line.create({ 57.f, -21.058f }, { -200.013f, -10.5f });

	auto secondLine = line;

	ASSERT_TRUE((secondLine == line));
}