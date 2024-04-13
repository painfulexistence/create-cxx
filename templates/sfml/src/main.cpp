#include "fmt/core.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

int main(int argc, char* args[]) {
    fmt::print("Hello from CXX!\n");

    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(800, 450), "MyApp");
    window.setFramerateLimit(144);
    window.setKeyRepeatEnabled(false);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                break;
            default:
                break;
            }
        }

        window.clear();

        window.display();
    }

    return 0;
}