#include "Game.h"
#include "Character.h"
#include "Player.h"

//Private Functions

void Game::initVariables()
{
    player.health = 100;
    
}

void Game::initWindow() {
    window.create(sf::VideoMode({600, 400}), "Test 2");
}



// }

Game::Game() {
    initVariables();
    initWindow();
    initTextures();
    initSprites();
    tri1 = makeTriangle();
    tri2 = makeTriangle2();
    window.setFramerateLimit(60);
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
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
                    std::cout << "Mouse was clicked (left click)" << std::endl;
                    auto pos = sf::Mouse::getPosition(window);
                    tri3.append(
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

            
        }
}


// Public functions
void Game::update()
{
    //handle movement
    delta = clock.restart().asSeconds();
    //Why not able to check this??
    player.handleMovement(delta);
    this->pollEvents();

}

void Game::render()
{
    window.clear();
    window.draw(*pond);
    // window.draw(tri1);
    // window.draw(tri2);
    window.draw(tri3);
    window.draw(*player.playersprite);
    window.display();
}


sf::VertexArray Game::makeTriangle() {
    sf::VertexArray outline(sf::PrimitiveType::LineStrip, 4);
    outline[0].position = {77,181};
    outline[1].position = {256,57};
    outline[2].position = {290,213};
    outline[3].position = {77,181};

    outline[0].color = sf::Color::Red;
    outline[1].color = sf::Color::Red;
    outline[2].color = sf::Color::Red;
    outline[3].color = sf::Color::Red;
    return outline;
}


sf::VertexArray Game::makeTriangle2() {
    sf::VertexArray outline(sf::PrimitiveType::LineStrip, 4);
    outline[0].position = {256,57};
    outline[1].position = {77,181};
    outline[2].position = {134, 102};
    outline[3].position = {256, 57};

    outline[0].color = sf::Color::Red;
    outline[1].color = sf::Color::Red;
    outline[2].color = sf::Color::Red;
    outline[3].color = sf::Color::Red;
    return outline;
}

void Game::initTextures () {

    if(!pondtexture .loadFromFile("Resources/pond.png")) {
        std::cerr << "Failed to load Resources/pond.png\n";
    }
}

void Game::initSprites() {
    pond.emplace(pondtexture);
    sf::FloatRect pondBounds = pond->getGlobalBounds();
    float pondWidth = pondBounds.size.x;
    float pondHeight = pondBounds.size.y;
    pond->setOrigin({
        pondWidth / 2,
        pondHeight / 2
    });

    pond->setPosition({static_cast<float>((window.getSize().x)/2.0),
    static_cast<float>((window.getSize().y)/2.0)});
    pond->setScale({2.5,2.5});
}


void setPondArea(sf::VertexArray& tri3) {
    
}

