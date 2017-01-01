#ifndef MAINWINDOW_HPP_INCLUDED
#define MAINWINDOW_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

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
  void resize();
  /*
   * Needs nothing
   * Resize
   * Returns nothing
   */
private:
  int m_menuArraySize;
  
  std::vector<sf::Text> m_menuArray;
  std::vector<std::string> m_menuStringArray;
  sf::RenderWindow *m_window;
  sf::Event m_event;
  sf::Font m_font;
  sf::Text m_playText;
  sf::Text m_quitText;

  Game *m_game;
};

#endif //MAINWINDOW_HPP_INCLUDED
