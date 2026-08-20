#include "Player.h"


Player::Player() {
    initTextures();
    initSprite();

}

void Player::initTextures () {
    if(!texturestand.loadFromFile("Resources/duckling.png")) {
        std::cerr << "Failed to load Resources/duckling.png\n";
    }
    if(!texturestandright.loadFromFile("Resources/ducklingstandingright.png")) {
        std::cerr << "Failed to load Resources/ducklingstandingright.png\n";
    }
    if(!texturewater.loadFromFile("Resources/ducklingwater.png")) {
        std::cerr << "Failed to load Resources/ducklingwater.png\n";
    }
    if(!texturewaterright.loadFromFile("Resources/ducklingwaterright.png")) {
        std::cerr << "Failed to load Resources/ducklingwaterright.png\n";
    }
    if(!textureback.loadFromFile("Resources/duckstandingback.png")) {
        std::cerr << "Failed to load Resources/duckstandingback.png\n";
    }
    if(!texturewaterback.loadFromFile("Resources/ducklingswimmingback.png")) {
        std::cerr << "Failed to load Resources/ducklingswimmingback.png\n";
    }
    if(!texturefront.loadFromFile("Resources/Front.png")) {
        std::cerr << "Failed to load Resources/Front.png\n";
    }
    if(!texturewaterfront.loadFromFile("Resources/frontwater.png")) {
        std::cerr << "Failed to load Resources/frontwater.png\n";
    }
}

void Player::initSprite()
{
    playerSprite.emplace(texturestand);
    playerSprite->setPosition({270.f, 175.f});
    playerSprite->setScale({1.5f, 1.5f});
}

void Player::handleMovement(float delta) {
    int speed = 150;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        playerSprite->move({-(speed * delta), 0});
        if (inPond) {
            playerSprite->setTexture(texturewater);
        }
        else {
            playerSprite->setTexture(texturestand);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        playerSprite->move({speed * delta, 0});
        if(inPond) {
            playerSprite->setTexture(texturewaterright);
        }
        else {
            playerSprite->setTexture(texturestandright);
        }   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        playerSprite->move({0, speed * delta});
        if(inPond) {
            playerSprite->setTexture(texturewaterfront);
        }
        else {
            playerSprite->setTexture(texturefront);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        playerSprite->move({0, -(speed * delta)});
        if(inPond) {
            playerSprite->setTexture(texturewaterback);
        }
        else {
            playerSprite->setTexture(textureback);
        }
    }
}