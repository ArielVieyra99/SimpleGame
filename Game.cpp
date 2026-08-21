
#include "Game.h"




void Game::initVariables()
{
    player.health = 100;
    boundsrect.setSize({385, 290});
    boundsrect.setPosition({107,55}); 
    boundsrect.setOutlineColor(sf::Color::Red);
    boundsrect.setFillColor(sf::Color::Transparent);
    boundsrect.setOutlineThickness(1.f);
    bounds.size = boundsrect.getSize();
    bounds.position =  boundsrect.getPosition();
}

void Game::initWindow() {
    window.create(sf::VideoMode({600, 400}), "Test 2");
}


Game::Game() {
    initVariables();
    initWindow();
    initTextures();
    initSprites();
    window.setFramerateLimit(90);
}


//accesors

const bool Game::running() const
{
    return window.isOpen();
}

void Game::pollEvents()
{
        while(std::optional event = window.pollEvent()) {
            if (event ->is <sf::Event::Closed>()) {
                window.close();
            }

            if (event->getIf<sf::Event::MouseButtonPressed>()) {
                setPondBounds();
            }

            
        }
}


// Public functions
void Game::update()
{   
    
    //handle movement
    delta = clock.restart().asSeconds();
    // player.handleMovement(delta);
    player.handleMovement(delta);
    this->pollEvents();
    if(inBounds()) {
        player.inBounds= true;
    }
    else {
        player.inBounds = false;
    }
}

void Game::render()
{
    window.clear(sf::Color(126, 163, 105));
    
    window.draw(*pool);
    window.draw(*player.playerSprite);
    window.draw(boundsrect);
    window.display();
}

void Game::initTextures () {

    if(!pondtexture .loadFromFile("Resources/pool.png")) {
        std::cerr << "Failed to load Resources/pool.png\n";
    }
}

void Game::initSprites() {
    pool.emplace(pondtexture);
    pool->setOrigin({
        pool->getGlobalBounds().size.x / 2,
        pool->getGlobalBounds().size.y / 2
    });
    pool->setPosition({static_cast<float>((window.getSize().x)/2.0),
    static_cast<float>((window.getSize().y)/2.0)});
    pool->setScale({1.5,1.5});
}

void Game::setPondBounds() {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
        std::cout << "Mouse was clicked (left click)" << std::endl;
        auto pos = sf::Mouse::getPosition(window);
        std::cout << pos.x << "\t" << pos.y << "\n\n";
        tri6.append(
            sf::Vertex {
                sf::Vector2f (
                    static_cast <float> (pos.x),
                    static_cast <float> (pos.y)
                ),
                sf::Color::Red
            }
        );
    }
}

bool Game::inBounds() {
    sf::Vector2f topLeft = player.playerSprite->getPosition();
    sf::Vector2f topRight = {topLeft.x + player.playerSprite->getGlobalBounds().size.x, topLeft.y};
    sf::Vector2f bottomleft = {topLeft.x, topLeft.y + player.playerSprite->getGlobalBounds().size.y};
    return (bounds.contains(topLeft)
            || bounds.contains(topRight)
            || bounds.contains(bottomleft)
            );
}

