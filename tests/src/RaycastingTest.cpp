#include "RaycastingTest.h"

#include "Randomizer.h"

#include <time.h>

TEST_F(RaycastingTest, RaycastingMainTest) {

	auto camera = createCamera();
	auto lines = createRandomLines();

	rj::Raycasting<IteratorT>::CastingProperties properties{
		camera,
		lines.begin(),
		lines.end()
	};

	auto result = raycasting.castingRays(properties);

	ASSERT_EQ(result.size(), 3u);
}

RaycastingTest::LineContainerT RaycastingTest::createRandomLines()
{
	rj::Randomizer randomizer(std::to_string(std::time(nullptr)));
	LineContainerT lines;

	for (int i = 0; i < randomizer.integer(1, 4); ++i) {
		LineT line;
		line.setFirstPoint({ randomizer.real(0.f, 400.f), randomizer.real(0.f, 400.f) });
		line.setSecondPoint({ randomizer.real(0.f, 400.f), randomizer.real(0.f, 400.f) });
		lines.push_back(line);
	}

	return lines;

}

rj::Camera RaycastingTest::createCamera()
{
	rj::Camera camera;
	camera.setFieldOfView(0.3f);
	camera.setPosition({ 200.f, 200.f });
	camera.setRaysCount(3u);
	camera.setRaysLength(200.f);

	return camera;
}
