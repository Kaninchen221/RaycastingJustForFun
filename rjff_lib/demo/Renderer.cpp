#include "Renderer.h"

#include <iostream>
#include <cmath>

namespace rj {

	void Renderer::update(const Player& player, const Map::Rays& rays)
	{
		prepareParticles(rays.size());

		auto currentParticle = particles.rbegin();
		auto currentRay = rays.begin();

		while (currentParticle != particles.rend() &&
			currentRay != rays.end())
		{

			float distanceToIntersection = getDistanceToRay(player, *currentRay);

			const float particleScale = getLinearScale(distanceToIntersection, player.getRayLength());

			//std::cout << "S : " << particleScale << '\n';

			auto particleColor = currentParticle->getFillColor();
			
			//particleColor = linearDarken(particleColor, particleScale);
			particleColor = gammaDarken(particleColor, particleScale);

			/// Particle Scaling
			/// TODO : Make this more readable
			auto particleSize = currentParticle->getSize();
			auto particlePosition = currentParticle->getPosition();

			float reductionScale = (1.f - particleScale) / 2.f;
			//float reductionScale = particleScale / 2.f;

			float reductionSize = renderingArea.y * reductionScale;
			float reductionPosition = renderingArea.y * reductionScale / 2.f;

			particleSize.y -= reductionSize;
			particlePosition.y += reductionPosition;

			currentParticle->setSize(particleSize);
			currentParticle->setPosition(particlePosition);
			/// Particle Scaling
			/// Reducing fisheye effect
			/// TODO : Make this more readable
			particleSize = currentParticle->getSize();
			particlePosition = currentParticle->getPosition();

			auto centerOfRendering = getCenterPointOfRendering();

			Point particleOffsetToCenterPoint; 
			particleOffsetToCenterPoint.x = particlePosition.x - centerOfRendering.x;
			particleOffsetToCenterPoint.y = particlePosition.y - centerOfRendering.y;

			float angleFromOpticalAxisInRadians =
				std::atan2(particleOffsetToCenterPoint.y, particleOffsetToCenterPoint.x);

			if (angleFromOpticalAxisInRadians < 0.f) /// Correction
				angleFromOpticalAxisInRadians *= -1.f;

			const float f = 8.f * 2.8f;
			///r=2*f*tan(theta /2.f)
			//float r = 2.f * f * std::tan(angleFromOpticalAxisInRadians / 2.f); /// Panoramiczny
			float r = f * angleFromOpticalAxisInRadians; /// Liniowy
			r /= 2.f;

			float correctedSize = particleSize.y + (r * 2.f);
			float correctedPosition = particlePosition.y - r;

			//float correctedSize = particleSize.y + r;
			//float correctedPosition = particlePosition.y - (r * 2.f);

			particleSize.y = correctedSize;
			particlePosition.y = correctedPosition;

			//currentParticle->setSize(particleSize);
			//currentParticle->setPosition(particlePosition);
			/// Reducing fisheye effect


			currentParticle->setFillColor(particleColor);

			++currentParticle;
			++currentRay;
		}

	}

	void Renderer::draw(sf::RenderTarget & target)
	{
		drawParticles(target);
	}

	void Renderer::setRenderingStartPoint(const Point & point) noexcept
	{
		renderingStartPoint = point;
	}

	Point Renderer::getRenderingStartPoint() const noexcept
	{
		return renderingStartPoint;
	}

	void Renderer::setRenderingArea(const sf::Vector2f & area) noexcept
	{
		renderingArea = area;
	}

	sf::Vector2f Renderer::getRenderingArea() const noexcept
	{
		return renderingArea;
	}

	void Renderer::prepareParticles(const size_t& particlesCount)
	{
		particles.clear();
		particles.reserve(particlesCount);

		float widthForParticle = renderingArea.y / particlesCount;
		float heightForParticle = renderingArea.x;
		
		//sf::Vector2f originForParticle;
		//originForParticle.x = renderingStartPoint.x + (widthForParticle / 2.f);
		//originForParticle.x = renderingStartPoint.y + (heightForParticle / 2.f);

		Particle particle;
		particle.setPosition(renderingStartPoint);

		for (auto currentParticle = 0u; currentParticle < particlesCount; currentParticle++) {

			particle.move({ widthForParticle, 0.f });
			particle.setSize({ widthForParticle, heightForParticle });
			particle.setFillColor(sf::Color::Black);
			
			//particle.setOutlineColor(sf::Color::Blue);
			//particle.setOutlineThickness(1.f);

			particles.push_back(particle);

		}

	}

	void Renderer::drawParticles(sf::RenderTarget & target)
	{
		for (const auto& particle : particles) {
			target.draw(particle);
		}
	}

	float Renderer::getDistanceToRay(const Player & player, const Map::Ray& ray) const noexcept
	{
		//float intersectionDistance;
		//intersectionDistance = player.getRayLength();
		//
		//if (intersectionInfo.pointerToObject != nullptr) {
		//	intersectionDistance = distance(player.getPosition(), intersectionInfo.coordinates);
		//}

		//return intersectionDistance;

		return distance(ray.getFirstPoint(), ray.getSecondPoint());
	}

	float Renderer::getLinearScale(const float & distanceToIntersection, const float & rayMaxLength) const noexcept
	{
		return 1.f - (distanceToIntersection / rayMaxLength);
	}

	sf::Color Renderer::linearDarken(sf::Color color, const float & scale) const noexcept
	{
		color.r += static_cast<std::uint8_t>(255.f * scale);
		color.g += static_cast<std::uint8_t>(255.f * scale);
		color.b += static_cast<std::uint8_t>(255.f * scale);

		return color;
	}

	sf::Color Renderer::gammaDarken(sf::Color color, float scale) const noexcept
	{

		scale = gammaCorrection(0.45f, scale);
		scale = gammaCorrection(2.2f, scale);
		
		color.r += static_cast<std::uint8_t>(255.f * scale);
		color.g += static_cast<std::uint8_t>(255.f * scale);
		color.b += static_cast<std::uint8_t>(255.f * scale);		
		
		return color;
	}

	Point Renderer::getCenterPointOfRendering() const noexcept
	{
		return Point( renderingStartPoint.x + (renderingArea.x / 2), renderingStartPoint.y + (renderingArea.y / 2) );
	}

}