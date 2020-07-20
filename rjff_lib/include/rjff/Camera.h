#ifndef CAMERA_H
#define CAMERA_H

#include "Point.h"

namespace rj {

	class Camera {
	public:

		Camera() = default;
		Camera(const Camera& other) = default;
		Camera(Camera&& other) = default;

		Camera& operator = (const Camera& other) = default;
		Camera& operator = (Camera&& other) = default;

		~Camera() = default;
	
		void setFieldOfView(float value) noexcept;
		float getFieldOfView() const noexcept;

		void setPosition(Point position) noexcept;
		Point getPosition() const noexcept;

		void move(Point offset) noexcept;
		void move(float x, float y) noexcept;

		void setRaysCount(size_t count) noexcept;
		size_t getRaysCount() const noexcept;

		void setRaysLength(float length) noexcept;
		float getRaysLength() const noexcept;

		void rotate(float degrees) noexcept;

		void setRotation(float degrees) noexcept;
		float getRotation() const noexcept;

	private:
	
		float fieldOfView = 0.f;
		Point position = { 0.f, 0.f };
		size_t raysCount = 0u;
		float raysLength = 0.f;
		float rotationInDegrees = 0.f;

	};

}

#endif /// !CAMERA_H