#ifndef STATICLINETEST_H
#define STATICLINETEST_H

#include "rjff/StaticLine.h"

#include "gtest/gtest.h"

class StaticLineTest : public ::testing::Test {
protected:

	StaticLineTest();

	~StaticLineTest() = default;

	void SetUp() override {};

	rj::StaticLine staticLine;

	sf::Vector2f firstPointTestValue;
	sf::Vector2f secondPointTestValue;
};



#endif // !STATICLINETEST_H