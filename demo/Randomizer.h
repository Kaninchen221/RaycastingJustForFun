#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>
#include <string>
#include <functional>

namespace rj {

	class Randomizer {

		std::random_device s_randomDevice;
		std::mt19937_64	s_generator;

		typedef std::uniform_int_distribution<int> IntDistribution;
		typedef std::uniform_real_distribution<float> RealDistribution;
		typedef std::bernoulli_distribution	BoolDistribution;

	public:

		Randomizer() = delete;
		Randomizer(const std::string seed = "seed");
		Randomizer(const Randomizer& other) = default;
		Randomizer(Randomizer&& other) = default;

		Randomizer& operator = (const Randomizer& other) = default;
		Randomizer& operator = (Randomizer&& other) = default;

		~Randomizer() = default;

		int	integer(const int &min = 0, const int &max = 1);
		float real(const float &min = 0, const float &max = 1);
		bool boolean();

	};

}

#endif /// !RANDOMIZER_H
