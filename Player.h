#pragma once
#include "Character.h"
#include "Player.h"
#include "Game.h"

class Player : public Character {
    private:
    sf::Texture texturestand;
    sf::Texture texturestandright;
    sf::Texture texturewater;
    sf::Texture texturewaterright;
    sf::Texture textureback;
    sf::Texture texturebackwater;
    std::optional<sf::Sprite> playersprite;

    void initTextures();
    void initSprite();
    bool inPond();
    
    public:
    Player();
    int score, credits;

    void handleMovement (float delta);
    sf::Texture getTexture();
    
};