#include "mainwindow.hpp"

MainWindow::MainWindow(sf::RenderWindow *window) {
  m_window = window;

  std::cout << "Menu created" << std::endl;

  m_menuArraySize = 2;

  std::string menuStringArray[2] = {"Play", "Quit"};

  for (int j(0); j < m_menuArraySize; j++) {
	m_menuStringArray.push_back(menuStringArray[j]);
  }
  
  if (!m_font.loadFromFile("fonts/joystix.ttf")) {
	std::cout << "Font have not been loaded" << std::endl;
  }

  for (int i(0); i < m_menuArraySize; i++) {
	m_menuArray.push_back(sf::Text());
	m_menuArray[i].setCharacterSize(60);
	m_menuArray[i].setString(m_menuStringArray[i]);
	m_menuArray[i].setPosition(m_window->getSize().x/2 - 100, 200 + 100 * i);
	m_menuArray[i].setFont(m_font);
  }
}

MainWindow::~MainWindow() {

}

void MainWindow::start() {
  while (m_window->isOpen()) {
	while (m_window->pollEvent(m_event)) {
	  if (m_event.type == sf::Event::Closed) {
		std::cout << "Game finished" << std::endl;
		m_window->close();
		break;
	  }
	  if (m_event.type == sf::Event::Resized) {
		m_window->setView(sf::View(sf::FloatRect(0, 0, m_event.size.width, m_event.size.height)));
		m_playText.setPosition(m_window->getSize().x/2 - 100, 200);
		m_quitText.setPosition(m_window->getSize().x/2 - 100, 300);
	  }
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
	  m_game = new Game(m_window);
	  m_game->start();
	}

	
	m_window->clear(sf::Color(109, 153, 255));

	for (int i(0); i < m_menuArraySize; i++) {
	  m_window->draw(m_menuArray[i]);
	}
	
	m_window->display();
  }
}


