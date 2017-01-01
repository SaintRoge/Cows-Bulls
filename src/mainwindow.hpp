#ifndef MAINWINDOW_HPP_INCLUDED
#define MAINWINDOW_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.hpp"

class MainWindow {
public:
  MainWindow(sf::RenderWindow *window);
  ~MainWindow();
  void start();
  /*
   * Needss nothing
   * Starts the game
   * Returns nothing
   */
private:
  sf::RenderWindow *m_window;
  sf::Event m_event;

  Game *m_game;
};

#endif //MAINWINDOW_HPP_INCLUDED
