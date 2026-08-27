#include "Enemy.h"


class projectile {
    // sf::Texture bubbleTexture;
    void init() {
        sf::Texture bubbleTexture;
        if(!bubbleTexture.loadFromFile("Resources/enemies/robotBubble.png")) {
            std::cout << "Failed to load image Resources/enemies/robotBubble.png" << std::endl;
        }
    }
    sf::Sprite bubbleSprite;
};



class Robot : public Enemy {
    public:
    sf::Texture robotTexture;
    std::optional <sf::Sprite> robotSprite;
    std::vector <projectile> projectileList;

    Robot();

    void handleMovement(sf::FloatRect confinement);
    void initTextures();
    void initSprites();
    private:
    bool inBounds;

};