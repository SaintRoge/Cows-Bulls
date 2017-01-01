#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Board {
public:
  Board(bool const isRed);
  ~Board();
  void turn();
  /*
   * Needs nothing
   * It's the board turn
   * Returns nothing
   */
private:
  bool m_isRed;
};

#endif //BOARD_HPP_INCLUDED
