#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <gtest/gtest.h>

#include "rjff/Camera.h"

class CameraTest : public ::testing::Test {
protected:

	CameraTest() = default;

	~CameraTest() = default;

	rj::Camera camera;
};

#endif /// !CAMERATEST_H