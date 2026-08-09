#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Character {
    
public:
    int health, speed;
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
