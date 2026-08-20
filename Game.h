#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Player.h"


class Game {
    private:
    sf::RenderWindow window;
    sf::Texture pondtexture;
    std::optional <sf::Sprite> pool;
    sf::Font font;
    sf::Clock clock;
    Player player;
    float delta;
    float mouseposx, mouseposy;
    sf::VertexArray tri6{sf::PrimitiveType::LineStrip};


    


    //Functions
    void initVariables();
    void initWindow();
    void initTextures ();
    void initSprites();
    void handlePlayerMovement();
    void setPondArea();

    public:
        //Contructor and Desctructor
        Game();
        // virtual ~Game();
        //Accessors

        //Functions
        const bool running() const;
        void update();
        void render();
        void pollEvents();
    
};
