#include "../include/rjff/Camera.h"

namespace rj {

	void Camera::setFieldOfView(float value) noexcept
	{
		if (value > 1.f) {
			value = 1.f;
		}
		else if (value < 0.f) {
			value = 0.f;
		}

		fieldOfView = value;
	}

	float Camera::getFieldOfView() const noexcept
	{
		return fieldOfView;
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