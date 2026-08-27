#include "Robot.h"

Robot::Robot() {
    initTextures();
    initSprites();
    health = 200;
}
void Robot::handleMovement(sf::FloatRect confinement) {
    if(!confinement.contains(robotSprite->getPosition())) {
        inBounds = true;
    }
    else {
        inBounds = false;
    }
}

void Robot::initTextures() {
    if(!robotTexture.loadFromFile("Resources/enemies/Robot.png")) {
        std::cout << "Failed to load: Resources/enemies/robot.png" << std::endl;
    }
}
void Robot::initSprites() {
    robotSprite.emplace(robotTexture);
}