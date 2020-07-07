#include "StaticLineTest.h"

StaticLineTest::StaticLineTest()
{
	firstPointTestValue = { 261.f, 85.f };
	secondPointTestValue = { 39.f, 20.f };
}

TEST_F(StaticLineTest, FirstPoint) {

	staticLine.setFirstPoint(firstPointTestValue);
	auto firstPoint = staticLine.getFirstPoint();

	ASSERT_EQ(firstPointTestValue, firstPoint);
}

TEST_F(StaticLineTest, SecondPoint) {

	staticLine.setSecondPoint(secondPointTestValue);
	auto secondPoint = staticLine.getSecondPoint();

	ASSERT_EQ(secondPointTestValue, secondPoint);
}

TEST_F(StaticLineTest, AssignValueTest) {

	staticLine.setFirstPoint(firstPointTestValue);
	staticLine.setSecondPoint(secondPointTestValue);

	rj::StaticLine copy = staticLine;

	ASSERT_EQ(staticLine, copy);
}

TEST_F(StaticLineTest, MoveValueTest) {
	
	staticLine.setFirstPoint(firstPointTestValue);
	staticLine.setSecondPoint(secondPointTestValue);

	rj::StaticLine copy = staticLine;
	rj::StaticLine moved;

	moved = std::move(staticLine);

	ASSERT_EQ(moved, copy);
}