#include "game.h"
// make function of if the square is outside of fence
// could be a certain animal like a cow or bull just an idea
bool outOfBounds(sf::Vector2f Position, sf::RectangleShape fence);
void handlePlayerMovement(sf::Sprite &player, float speed, float delta);
void checkMouse(sf::RenderWindow& window);
// function to handle setting initial positioning and color and aspect of elements

using namespace std;


class Character {
    sf::Sprite sprite;
    int health, speed;
public:
    void die(int health);
    void takeDamage(int amount) {
        health =-amount;
    }
};

class Player : public Character {
    int score, credits;
};

class Enemy : public Character {
    int normalDamage, heavyDamage;
};


sf::VertexArray maketriangle() {
    sf::VertexArray outline(sf::PrimitiveType::LineStrip, 4);
    outline[0].position = {77,181};
    outline[1].position = {256,57};
    outline[2].position = {290,213};
    outline[3].position = {77,181};

    outline[0].color = sf::Color::Red;
    outline[1].color = sf::Color::Red;
    outline[2].color = sf::Color::Red;
    outline[3].color = sf::Color::Red;
    

    sf::VertexArray outline2(sf::PrimitiveType::LineStrip, 4);
    outline2[0].position = {256,57};
    outline2[1].position = {77,181};
    outline2[2].position = {134, 102};
    outline2[3].position = {256, 57};

    outline2[0].color = sf::Color::Red;
    outline2[1].color = sf::Color::Red;
    outline2[2].color = sf::Color::Red;
    outline2[3].color = sf::Color::Red;
    return outline;
    
}

int main() {
    sf::Clock clock;
    float speed = 150;
    // sf::RenderWindow window();
    Game game;
    sf::Texture texture("Resources/duckling.png");
    sf::Sprite player(texture);
    player.setPosition({270, 175});
    player.scale({2.0, 2.0});
    sf::Texture pondtexture ("Resources/pond.png");
    sf::Sprite pond(pondtexture);
    pond.scale({2.5 ,2.5});
    auto bounds = pond.getLocalBounds();
    pond.setOrigin({
        bounds.size.x/2,
        bounds.size.y/2
    });

    pond.setPosition({static_cast<float>(window.getSize().x /2.0),
        static_cast<float>(window.getSize().y /2.0 )});
    
    //debug pond
    

    
    
    // Text
    sf::Font font("SuperPixel-m2L8j.ttf");
    sf::Text text(font);
    text.setString("Health \t5");
    text.setScale({.5, .5});
    text.setFillColor(sf::Color::White);
    text.setPosition({10, static_cast<float>(window.getSize().y) - text.getGlobalBounds().size.y - 5});

    sf::CircleShape circle1(30.f, 5);
    circle1.setPosition({10, 10});
    circle1.setFillColor({255, 51, 51});

    sf::RectangleShape fence1({400, 300});
    fence1.setFillColor(sf::Color(153, 51, 0));
    fence1.setOutlineThickness(5);
    fence1.setOutlineColor(sf::Color(102, 51, 0));
    fence1.setPosition({100, 50});

    window.setFramerateLimit(60);

    while (game.running())
    {



        float delta = clock.restart().asSeconds();

        // handle movement below in function
        checkMouse(window);
        handlePlayerMovement(player, speed, delta);
        if (outOfBounds(player.getPosition(), fence1))
        {
            player.setColor(sf::Color(255, 128, 128, 128));
            speed = 75;
        }
        else
            player.setColor(sf::Color(255, 255, 255, 255)); // half transparent
        speed = 150;

        window.clear(sf::Color(200, 230, 153));
        window.draw(pond);
        // window.draw(fence1);
        // window.draw(circle1);
        window.draw(maketriangle());
        window.draw(player);
        window.draw(text);
        window.display();
    }
}

bool outOfBounds(sf::Vector2f Position, sf::RectangleShape fence)
{
    if (Position.x < fence.getPosition().x || Position.x > (fence.getPosition().x + fence.getSize().x) || Position.y < fence.getPosition().y || Position.y > (fence.getPosition().y + fence.getSize().y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void handlePlayerMovement(sf::Sprite &player, float speed, float delta)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        player.move({-(speed * delta), 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        player.move({speed * delta, 0});
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        player.move({0, speed * delta});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        player.move({0, -(speed * delta)});
    }
}

void checkMouse(sf::RenderWindow& window) {
    bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    static bool wasPressed = false;
    auto pos = sf::Mouse::getPosition(window);
    if (pressed && !wasPressed) {
        cout << "mouse x: \t" << pos.x << endl;
        cout << "mouse y: \t" << pos.y  << "\n\n" << endl;
    }

    wasPressed = pressed;
}
// sf::Vector2f Character::boost (sf::Vector2f &pos, int boostamount) {
//     cout << "Boosted to: " << endl;     
// }

