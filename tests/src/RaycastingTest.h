#ifndef RAYCASTINGTEST_H
#define RAYCASTINGTEST_H

#include <gtest/gtest.h>

#include "rjff/Raycasting.h"
#include "rjff/Line.h"

class RaycastingTest : public ::testing::Test {
protected:

	RaycastingTest() = default;

	~RaycastingTest() = default;

	using LineT = rj::StaticLine;
	using LineContainerT = std::vector<LineT>;
	using IteratorT = LineContainerT::iterator;

	LineContainerT createRandomLines();
	rj::Camera createCamera();

	rj::Raycasting<IteratorT> raycasting;
};


#endif /// !RAYCASTINGTEST_H