#pragma once
#include "Character.h"
    

class Player : public Character {
    private:
    sf::Texture texturestand;
    sf::Texture texturestandright;
    sf::Texture texturewater;
    sf::Texture texturewaterright;
    sf::Texture textureback;
    sf::Texture texturefront;
    sf::Texture texturewaterfront;
    sf::Texture texturewaterback;
    
    

    void initTextures();
    void initSprite();
    
    public:
    Player();
    int score, credits;
    std::optional<sf::Sprite> playerSprite;
    bool inBounds;

    void handleMovement (float delta);
    sf::Texture getTexture();
    
};