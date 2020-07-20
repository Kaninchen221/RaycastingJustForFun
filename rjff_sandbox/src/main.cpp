#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "rjff/randomizer.h"

#include <ctime>
#include <iostream>
#include <functional>

int main()
{

	rj::Randomizer randomizer(std::to_string(std::time(0)));

    // Create the main window
	sf::ContextSettings cs;
	cs.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML window", 7U, cs);

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
					//player.rotate(-1.5f);
				}
				else if (event.key.code == sf::Keyboard::E) {
					//player.rotate(1.5f);
				}

			}

        }
        // Clear screen
        window.clear(sf::Color::Black);

		auto mousePos = sf::Mouse::getPosition(window);
		if (window.hasFocus()) {
		
		}



        window.display();
    }
    return EXIT_SUCCESS;
}
