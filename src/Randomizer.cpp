#include "../include/Randomizer.h"

#include <functional>

namespace rj {

	Randomizer::Randomizer(const std::string seed)
	{
		std::seed_seq seedSequence{ std::hash<std::string>{}(seed) };
		generator.seed(seedSequence);
	}

	int Randomizer::integer(const int &min, const int &max)
	{
		if (min > max)
			return 0;

		IntDistribution dist(min, max);
		return dist(generator);
	}

	float Randomizer::real(const float &min, const float &max)
	{
		if (min > max)
			return 0.f;

		RealDistribution dist(min, max);
		return dist(generator);
	}

	bool Randomizer::boolean()
	{
		BoolDistribution dist;
		return dist(generator);
	}

} /// namespace rj