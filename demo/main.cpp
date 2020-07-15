#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Randomizer.h"
#include "Player.h"
#include "Error.h"
#include "Line.h"
#include "Renderer.h"

#include <ctime>
#include <iostream>
#include <functional>

int main()
{

	rj::Randomizer randomizer(std::to_string(std::time(0)));

	float size = 400.f;

	/// Create player
	rj::Player player;
	player.rotate(-90.f);

	/// Generate a map for raycasting logic
	//rj::Map map(sf::Vector2f(size, size));
	rj::Map map;

	///Create cube in map
	rj::StaticLine line;
	auto p1 = rj::Point(1.f, 1.f);
	auto p2 = rj::Point(size, 1.f);
	line.setFirstPoint(p1);
	line.setSecondPoint(p2);
	map.addWall(line);

	p1 = rj::Point(size, 1.f);
	p2 = rj::Point(size, size);
	line.setFirstPoint(p1);
	line.setSecondPoint(p2);
	map.addWall(line);

	p1 = rj::Point(size, size);
	p2 = rj::Point(1.f, size);
	line.setFirstPoint(p1);
	line.setSecondPoint(p2);
	map.addWall(line);

	p1 = rj::Point(1.f, size);
	p2 = rj::Point(1.f, 1.f);
	line.setFirstPoint(p1);
	line.setSecondPoint(p2);
	map.addWall(line);

	///Create random number of walls
	//for (auto i = 0; i < randomizer.integer(1, 6); i++) {
	//	auto p1 = rj::Point(randomizer.real(1.f, size), randomizer.real(1.f, size));
	//	auto p2 = rj::Point(randomizer.real(1.f, size), randomizer.real(1.f, size));
	//
	//	rj::StaticLine line;
	//	line.setFirstPoint(p1);
	//	line.setSecondPoint(p2);
	//
	//	map.addWall(line);
	//
	//}
	{
		auto p1 = rj::Point({ 150.f, 150.f });
		auto p2 = rj::Point({ 250.f, 150.f });
		rj::StaticLine line;
		line.setFirstPoint(p1);
		line.setSecondPoint(p2);
		map.addWall(line);

		p1 = rj::Point({ 250.f, 150.f });
		p2 = rj::Point({ 250.f, 250.f });
		line.setFirstPoint(p1);
		line.setSecondPoint(p2);
		map.addWall(line);

		p1 = rj::Point({ 250.f, 250.f });
		p2 = rj::Point({ 150.f, 250.f });
		line.setFirstPoint(p1);
		line.setSecondPoint(p2);
		map.addWall(line);

		p1 = rj::Point({ 150.f, 250.f });
		p2 = rj::Point({ 150.f, 150.f });
		line.setFirstPoint(p1);
		line.setSecondPoint(p2);
		map.addWall(line);
	}
	/// End of generating map

    // Create the main window
	sf::ContextSettings cs;
	cs.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML window", 7U, cs);

	rj::Renderer renderer;
	renderer.setRenderingStartPoint({ size + size * 0.25f, 30.f });
	renderer.setRenderingArea({ size, size * 2.f });

	//auto view = window.getView();
	//view.move(size / -2.f, size / -2.f);
	//window.setView(view);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::Q) {
					player.rotate(-1.5f);
				}
				else if (event.key.code == sf::Keyboard::E) {
					player.rotate(1.5f);
				}

			}

        }
        // Clear screen
        window.clear(sf::Color::Black);

		auto mousePos = sf::Mouse::getPosition(window);
		if (window.hasFocus())
			player.setPosition(rj::Point(mousePos.x, mousePos.y));

		map.update(player);

		renderer.update(player, map.getRays());

		map.drawRays(window, player);
		map.drawWalls(window);
		map.drawLeveler(window);
		
		player.draw(window);
		renderer.draw(window);

        window.display();
    }
    return EXIT_SUCCESS;
}
