#include "game.hpp"

Game::Game(sf::RenderWindow *window) {
  m_window = window;
}

Game::~Game() {

}

void Game::start() {
  std::cout << "Game started" << std::endl;
  while (m_window->isOpen()) {
	while (m_window->pollEvent(m_event)) {
	  if (m_event.type == sf::Event::Closed) {
		std::cout << "Game finished" << std::endl;
		m_window->close();
		break;
	  }
	  if (m_event.type == sf::Event::Resized) {
		m_window->setView(sf::View(sf::FloatRect(0, 0, m_event.size.width, m_event.size.height)));
	  }
	}
	m_window->clear(sf::Color(109, 153, 255));
	m_window->display();	
  }
}
