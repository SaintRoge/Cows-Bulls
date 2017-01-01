#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
  Game(sf::RenderWindow *window);
  ~Game();
  void start();
  /*
   * Needs nothing
   * Starts the game
   * Returns nothing 
   */
  void resize();
  /*
   * Needs nothing
   * The windows components resize
   * Returns nothing
   */
private:
  sf::RenderWindow *m_window;
  sf::Event m_event;
};

#endif //GAME_HPP_INCLUDED
