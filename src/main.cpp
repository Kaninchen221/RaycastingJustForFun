#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Randomizer.h"
#include "Player.h"
#include "Error.h"
#include "Line.h"

#include <ctime>
#include <iostream>
#include <functional>

/// TODO : Start today with creating function to handle exceptions !!!

int main()
{
	rj::Line line;
	auto func = std::bind(&rj::StaticLine::setFirstPoint, &line, sf::Vector2f(0.f, 0.f));
	func();

	rj::Randomizer randomizer(std::to_string(std::time(0)));

	std::cout << randomizer.real(1.f, -1.f) << "\n";
	float size = 400.f;
	std::cout << randomizer.real(1, -1) << "\n";

	/// Create player
	auto player = std::make_shared<rj::Player>();

	/// Generate a map for raycasting logic
	//rj::Map map(sf::Vector2f(size, size));
	rj::Map map;

	for (auto i = 0; i < randomizer.integer(1, 6); i++) {
		auto p1 = rj::Point(randomizer.real(1.f, size), randomizer.real(1.f, size));
		auto p2 = rj::Point(randomizer.real(1.f, size), randomizer.real(1.f, size));

		rj::StaticLine line;
		line.setFirstPoint(p1);
		line.setSecondPoint(p2);

		map.addWall(line);

	}

	map.setPlayer(player);
	/// End of generating map

    // Create the main window
	sf::ContextSettings cs;
	cs.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window", 7U, cs);

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
					player->rotate(-3.f);
				}
				else if (event.key.code == sf::Keyboard::E) {
					player->rotate(3.f);
				}

			}

        }
        // Clear screen
        window.clear(sf::Color::Black);

		map.update();
		map.drawIntersections(window);
		map.drawWalls(window);
		//map.drawVisualization(window);
		player->draw(window);
		auto mousePos = sf::Mouse::getPosition(window);
		if(window.hasFocus())
			player->setPosition(rj::Point(mousePos.x, mousePos.y));

        window.display();
    }
    return EXIT_SUCCESS;
}
