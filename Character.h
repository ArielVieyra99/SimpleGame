#pragma once
#include "Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>


class Character {
    int health, speed;
public:
    //variables

    //functions
    void die(int health)
    {
        std::cout <<"die function" <<std::endl;
    }
    void takeDamage(int amount) {
        health =-amount;
    }
};



class Enemy : public Character {
    int normalDamage, heavyDamage;
};
