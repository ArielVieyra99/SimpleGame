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
    sf::RectangleShape boundsrect;
    sf::Rec<float> bounds {(10.f,10.f), (10.f,10.f)};

    //Functions
    void initVariables();
    void initWindow();
    void initTextures ();
    void initSprites();
    void handlePlayerMovement();
    void setPondArea();
    void setPondBounds();
    bool inBounds();

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
