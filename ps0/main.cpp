#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    window.setFramerateLimit(60);
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    unsigned int x = 200;
    unsigned int y = 200;
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite.move(-5,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            sprite.move(5,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.move(0,-5);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.move(0,5);
        
        
        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}

