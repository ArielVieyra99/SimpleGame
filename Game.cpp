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
    makeTriangles();
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
                    std::cout << pos.x << "\t" << pos.y << "\n\n";
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
    if(inTriangle(tri1[0].position,tri1[1].position, tri1[2].position,player.playersprite->getposition())) {
        std::cout << "the player is in the triangle" << std::endl;
    }


}

void Game::render()
{
    window.clear(sf::Color(126, 163, 105));
    window.draw(*pond);
    // window.draw(tri1);
    // window.draw(tri2);
    window.draw(tri3);
    window.draw(*player.playersprite);
    window.display();
}

void Game::makeTriangles() {
    tri1[0].position = {51,192};
    tri1[1].position = {291,55};
    tri1[2].position = {309,224};

    tri1[0].color = sf::Color::Red;
    tri1[1].color = sf::Color::Red;
    tri1[2].color = sf::Color::Red;

    tri2[0].position = {51,192};
    tri2[1].position = {291,55};
    tri2[2].position = {139, 88};

    tri2[0].color = sf::Color::Red;
    tri2[1].color = sf::Color::Red;
    tri2[2].color = sf::Color::Red;
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
float cross(sf::Vector2f a, sf::Vector2f b) {
    
    return a.x * b.y - a.y * b.x;
}

bool inTriangle(sf::Vector2f& a, sf::Vector2f& b, sf::Vector2f& c, sf::Vector2f p) {

    float c1 = cross(b-a, p-a);
    float c2 = cross(c-b, p-b);
    float c3 = cross(a-c, p-c);

    return (c1 >= 0 && c2 >= 0 && c3 >= 0) ||
           (c1 <= 0 && c2 <= 0 && c3 <= 0);
}

