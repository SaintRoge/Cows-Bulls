#include "board.hpp"

Board::Board() {
  
}

Board::~Board() {

}

bool Board::turn(int turnNumber) {
  if (turnNumber <= 9876 && turnNumber >= 1234 && m_chosenNumber != NULL) {
	
  } else if (turnNumber <= 987 && m_chosenNumber != NULL) {
	
  } else {
	return false;
  }
}

bool Board::setChosenNumber(int chosenNumber) {

}

bool Board::ifChosenNumber(int chosenNumber) {

}
