#include "Game.h"

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
	srand(time(nullptr));
}

bool Game::init()
{
	texture = sf::Texture();
	texture.loadFromFile("../resources/kenney_fish-pack/PNG/Default size/fishTile_100.png");

	sprite.setTexture(texture);

	return true;
}

void Game::update(float dt)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	sprite.setPosition(sf::Vector2f(mouse_pos.x, mouse_pos.y));
}

void Game::render()
{
	window.draw(sprite);
}

void Game::mouseClicked(sf::Event event)
{

}

void Game::mouseMoved(sf::Event event)
{

}

void Game::keyPressed(sf::Event event)
{

}

void Game::prepState()
{

}

void Game::moveSpriteToCursor(sf::Sprite sprite)
{

}
