#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include "Player.h"



class Game {
    private:

    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Texture pondtexture;
    std::optional <sf::Sprite> pond;
    sf::VertexArray tri1{sf::PrimitiveType::LineStrip,4};
    sf::VertexArray tri2{sf::PrimitiveType::LineStrip,4};
    sf::Font font;
    sf::Clock clock;
    Player player;
    float delta;
    float mouseposx, mouseposy;
    sf::VertexArray tri3{sf::PrimitiveType::LineStrip};
    


    //Functions
    void initVariables();
    void initWindow();
    void initTextures ();
    void initSprites();
    void handlePlayerMovement();
    void makeTriangles();
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
