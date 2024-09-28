#include <SFML/Graphics.hpp>

int main() {
    // Create a window with a resolution of 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Black Screen");

    // Main loop that continues until the window is closed
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
