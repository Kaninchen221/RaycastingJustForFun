#include "../include/Camera.h"

namespace rj {

	void Camera::setHorizontalFieldOfView(float value) noexcept
	{
		horizontalFieldOfView = value;
	}

	float Camera::getHorizontalFieldOfView() const noexcept
	{
		return horizontalFieldOfView;
	}

	void Camera::setPosition(Point position) noexcept
	{
		this->position = position;
	}

	Point Camera::getPosition() const noexcept
	{
		return position;
	}

	void Camera::move(Point offset) noexcept
	{
		position += offset;
	}

	void Camera::move(float x, float y) noexcept
	{
		position.x += x;
		position.y += y;
	}

	void Camera::setRaysCount(size_t count) noexcept
	{
		raysCount = count;
	}

	size_t Camera::getRaysCount() const noexcept
	{
		return raysCount;
	}

	void Camera::setRaysLength(float length) noexcept
	{
		raysLength = length;
	}

	float Camera::getRaysLength() const noexcept
	{
		return raysLength;
	}

	void Camera::rotate(float degrees) noexcept
	{
		rotationInDegrees += degrees;
	}

	void Camera::setRotation(float degrees) noexcept
	{
		rotationInDegrees = degrees;
	}

	float Camera::getRotation() const noexcept
	{
		return rotationInDegrees;
	}

}