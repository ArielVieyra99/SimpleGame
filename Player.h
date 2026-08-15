#pragma once
#include "Character.h"
    

class Player : public Character {
    private:
    sf::Texture texturestand;
    sf::Texture texturestandright;
    sf::Texture texturewater;
    sf::Texture texturewaterright;
    sf::Texture textureback;
    sf::Texture texturebackwater;
    sf::Texture texturefront;
    

    void initTextures();
    void initSprite();
    bool inPond();
    
    public:
    Player();
    int score, credits;
    std::optional<sf::Sprite> playersprite;

    void handleMovement (float delta);
    sf::Texture getTexture();
    
};