#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    std::vector<sf::Shape *> figures;

    sf::RectangleShape rectangle(sf::Vector2f(60.f, 70.f));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineColor(sf::Color::Yellow);
    rectangle.setOutlineThickness(5.f);
    rectangle.setPosition(100, 100);

    figures.push_back(&rectangle);

    sf::CircleShape circle(49.f);
    circle.setFillColor(sf::Color::Green);

    figures.push_back(&circle);

    // Display window

    sf::RenderWindow window(sf::VideoMode(400, 400), "Task 05-06");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto figure : figures)
        {
            window.draw(*figure);
        }

        window.display();
    }

    return 0;
}
