// Libraries
#include <iostream>
#include <SFML/Graphics.hpp>

// Project Scope
#include "Game.h"

int main()
{
    std::cout << "You should see a window that opens as well as this writing to console..."
        << std::endl;

    // Create window and set up
    sf::RenderWindow window(sf::VideoMode(1080, 800), "SFML_PROJECT");
    window.setFramerateLimit(60);

    // Instantiate & initialise an instance of the game class
    Game game(window);

    // Run the init function of the game class and check it all initialises ok
    if (!game.init())
    {
        return 0;
    }

    // A Clock starts counting as soon as it's created
    sf::Clock clock;

    // Game loop: run the program as long as the window is open
    while (window.isOpen())
    {
        // Check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;

        // Calculate delta time
        sf::Time time = clock.restart();
        float dt = time.asSeconds();

        // 'process inputs' element of the game loop
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
                game.keyPressed(event);

            if (event.type == sf::Event::MouseButtonPressed)
                game.mouseClicked(event);

            if (event.type == sf::Event::MouseMoved)
                game.mouseMoved(event);
        }


        // 'update' element of the game loop
        game.update(dt);

        // Clear the window with black/grey before the next render.
        window.clear(sf::Color(48, 44, 46));

        // 'render' element of the game loop
        game.render();
        window.display();
    }

    return 0;
}
