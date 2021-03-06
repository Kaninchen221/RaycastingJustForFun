#include "CameraTest.h"

#include "rjff/Point.h"

TEST_F(CameraTest, fieldOfViewTest) {

	float testValue = 0.34123f;

	camera.setFieldOfView(testValue);
	auto horizontalFieldOfView = camera.getFieldOfView();

	ASSERT_FLOAT_EQ(testValue, horizontalFieldOfView);
}

TEST_F(CameraTest, positionTest) {

	rj::Point testPosition = { 131.f, 10.f };

	camera.setPosition(testPosition);
	auto cameraPosition = camera.getPosition();

	ASSERT_TRUE(testPosition == cameraPosition);
}

TEST_F(CameraTest, moveTest) {

	rj::Point testPosition = { 131.f, 10.f };
	camera.setPosition(testPosition);

	auto moveValue = rj::Point{ 50.f, 56.f };
	camera.move(moveValue);
	camera.move(moveValue.x, moveValue.y);

	auto cameraPosition = camera.getPosition();
	
	ASSERT_TRUE(testPosition + (moveValue * 2.f) == cameraPosition);
}

TEST_F(CameraTest, raysCountTest) {

	size_t raysCountTestValue = 14u;

	camera.setRaysCount(raysCountTestValue);
	auto cameraRaysCount = camera.getRaysCount();

	ASSERT_EQ(raysCountTestValue, cameraRaysCount);
}

TEST_F(CameraTest, raysLength) {

	float raysLengthTestValue = 120.215f;

	camera.setRaysLength(raysLengthTestValue);
	auto cameraRaysLength = camera.getRaysLength();

	ASSERT_FLOAT_EQ(raysLengthTestValue, cameraRaysLength);
}

TEST_F(CameraTest, rotationTest) {

	float rotateTestValue = 45.21f;

	camera.rotate(rotateTestValue);
	auto cameraRotation = camera.getRotation();

	ASSERT_FLOAT_EQ(rotateTestValue, cameraRotation);

	float additionalRotation = 100.2034f;
	camera.setRotation(cameraRotation + additionalRotation);

	ASSERT_FLOAT_EQ(camera.getRotation(), cameraRotation + additionalRotation);
}