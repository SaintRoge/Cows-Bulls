#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
  Game(sf::RenderWindow *window);
  ~Game();
  void start();
private:
  sf::RenderWindow *m_window;
  sf::Event m_event;
};

#endif //GAME_HPP_INCLUDED
