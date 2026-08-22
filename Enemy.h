#pragma once
#include "Character.h"

class Enemy : public Character {
    public:
    int health;
    sf::FloatRect hitbox;

    void attack(); //?

};