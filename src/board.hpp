#ifndef BOARD_HPP_INCLUDED
#define BOARD_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Board {
public:
  Board();
  ~Board();
  bool turn(int turnNumber);
  /*
   * Needs a number
   * It's the board turn
   * Returns if you can do the turn
   */
private:
  int m_chosenInt;
  int m_turnNumber;
  
  std::vector<int> m_numberArray;
  std::vector<std::vector<int>> m_cowsbullsArray;
};

#endif //BOARD_HPP_INCLUDED
