#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	rj::Randomizer randomizer(std::to_string(std::time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

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

        }
        // Clear screen
        window.clear(sf::Color::Black);

        window.display();
    }
    return EXIT_SUCCESS;
}
