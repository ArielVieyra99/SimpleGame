#include "Game.h"
// make function of if the square is outside of fence
// could be a certain animal like a cow or bull just an idea
// bool outOfBounds(sf::Vector2f Position, sf::RectangleShape fence);
// void handlePlayerMovement(sf::Sprite &player, float speed, float delta);
// void checkMouse(sf::RenderWindow& window);
// function to handle setting initial positioning and color and aspect of elements

using namespace std;


int main() {
    Game game;

    while (game.running())
    {

        game.update();
        game.render();

        // float delta = clock.restart().asSeconds();

        // // handle movement below in function
        // checkMouse(window);
        // handlePlayerMovement(player, speed, delta);
        // if (outOfBounds(player.getPosition(), fence1))
        // {
        //     player.setColor(sf::Color(255, 128, 128, 128));
        //     speed = 75;
        // }
        // else
        //     player.setColor(sf::Color(255, 255, 255, 255)); // half transparent
        // speed = 150;

        // window.clear(sf::Color(200, 230, 153));
        // window.draw(pond);
        // // window.draw(fence1);
        // // window.draw(circle1);
        // window.draw(player);
        // window.draw(text);
        // window.display();
    }
}

// bool outOfBounds(sf::Vector2f Position, sf::RectangleShape fence)
// {
//     if (Position.x < fence.getPosition().x || Position.x > (fence.getPosition().x + fence.getSize().x) || Position.y < fence.getPosition().y || Position.y > (fence.getPosition().y + fence.getSize().y))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }



// void checkMouse(sf::RenderWindow& window) {
//     bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
//     static bool wasPressed = false;
//     auto pos = sf::Mouse::getPosition(window);
//     if (pressed && !wasPressed) {
//         cout << "mouse x: \t" << pos.x << endl;
//         cout << "mouse y: \t" << pos.y  << "\n\n" << endl;
//     }

//     wasPressed = pressed;
// }
// sf::Vector2f Character::boost (sf::Vector2f &pos, int boostamount) {
//     cout << "Boosted to: " << endl;     
// }

