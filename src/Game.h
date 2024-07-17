#pragma once

// Libraries
#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
 public:
  explicit Game(sf::RenderWindow& window);
  ~Game() = default;
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void mouseMoved(sf::Event event);
  void keyPressed(sf::Event event);
  void prepState();

 private:
  sf::RenderWindow& window;
};
