#include "Enemy.h"


class Robot : public Enemy {
    public:
    sf::Texture robotTexture;
    std::optional <sf::Sprite> robotSprite;
    std::vector <

    Robot();

    void handleMovement(sf::FloatRect confinement);
    void initTextures();
    void initSprites();
    private:
};

class projectile : private Robot {
    sf::Texture bubbleTexture;
    if(!(bubbleTexture.loadFromFile("Resources/enemies/robotBubble.png")) {
        std::cout << "Failed to load: Resources/enemies/robotBubble.png" << std::endl;
    }
    sf::Sprite projectile()
};

