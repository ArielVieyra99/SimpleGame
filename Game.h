#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>


class Game {
    private:

    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Texture pondtexture;
    std::optional <sf::Sprite> pond;
    sf::VertexArray tri1, tri2;
    sf::Font font;
    sf::Clock clock;
    


    //Functions
    void initVariables();
    void initWindow();
    void initTextures ();
    void initSprites();
    void handlePlayerMovement();
    sf::VertexArray makeTriangle2();
    sf::VertexArray makeTriangle();




    public:
        //Contructor and Desctructor
        Game();
        virtual ~Game();

        //Accessors
        const bool running() const;
        float delta;

        //Functions

        void update();
        void render();
        void pollEvents();
    
};
