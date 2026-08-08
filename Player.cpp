#include "Player.h"
#include "Game.h"


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
        std::cerr << "Failed to load Resources/ducklingwater.png\n";
    }
    if(!textureback.loadFromFile("Resources/duckstandingback.png")) {
        std::cerr << "Failed to load Resources/duckstandingback.png\n";
    }
    if(!texturebackwater.loadFromFile("Resources/ducklingswimmingback.png")) {
        std::cerr << "Failed to load Resources/ducklingswimmingback.png\n";
    }
}

void Player::initSprite()
{
    playersprite.emplace(texturestand);
    playersprite->setPosition({270.f, 175.f});
    playersprite->setScale({2.f, 2.f});
}

void Player::handleMovement(float delta) {
    int speed = 150;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        playersprite->move({-(speed * delta), 0});
        playersprite->setTexture(texturestand);
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        playersprite->move({speed * delta, 0});
        playersprite->setTexture(texturestandright);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        playersprite->move({0, speed * delta});
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        playersprite->move({0, -(speed * delta)});
        playersprite->setTexture(textureback);
    }
}