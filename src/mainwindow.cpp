#include "mainwindow.hpp"

MainWindow::MainWindow(sf::RenderWindow *window) {
  m_window = window;

  std::cout << "Menu created" << std::endl;

  m_choiceClock.restart();
  m_choiceTime = sf::Time(sf::seconds(0.2f));
  
  m_menuArraySize = 2;
  m_selectedButton = 0;

  std::string menuStringArray[m_menuArraySize] = {"Play", "Quit"};

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

  select(m_selectedButton);
}

MainWindow::~MainWindow() {

}

void MainWindow::start() {
  while (m_window->isOpen()) {
	while (m_window->pollEvent(m_event)) {
	  if (m_event.type == sf::Event::Closed) {
		close();
		break;
	  }
	  if (m_event.type == sf::Event::Resized) {
		resize();
	  }
	}	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
	  if (m_selectedButton == 0) {
		m_game = new Game(m_window);
		m_game->start();
	  } else if (m_selectedButton == 1) {
		close();
		break;
	  }
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_choiceClock.getElapsedTime() >= m_choiceTime) {
	  m_choiceClock.restart();
	  if (m_selectedButton - 1 >= 0) {
		deselect(m_selectedButton);
		select(m_selectedButton - 1);
	  } else {
		deselect(m_selectedButton);
		select(m_menuArraySize - 1);
	  }
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_choiceClock.getElapsedTime() >= m_choiceTime) {
	  m_choiceClock.restart();
	  if (m_selectedButton + 1 < m_menuArraySize) {
		deselect(m_selectedButton);
		select(m_selectedButton + 1);
	  } else {
		deselect(m_selectedButton);
		select(0);
	  }
	}
	
	m_window->clear(sf::Color(109, 153, 255));

	for (int i(0); i < m_menuArraySize; i++) {
	  m_window->draw(m_menuArray[i]);
	}
	
	m_window->display();
  }
}

void MainWindow::resize() {
  m_window->setView(sf::View(sf::FloatRect(0, 0, m_event.size.width, m_event.size.height)));
  for (int i(0); i < m_menuArraySize; i++) {
	m_menuArray[i].setPosition(m_window->getSize().x/2 - 100, 200 + 100 * i);
  }
}

void MainWindow::select(int sButton) {
  m_selectedButton = sButton;
  m_menuArray[m_selectedButton].setCharacterSize(80);
  m_menuArray[m_selectedButton].setPosition(m_menuArray[m_selectedButton].getPosition().x - 10, m_menuArray[m_selectedButton].getPosition().y);
}

void MainWindow::deselect(int sButton) {
  m_menuArray[sButton].setCharacterSize(60);
  m_menuArray[sButton].setPosition(m_menuArray[m_selectedButton].getPosition().x + 10, m_menuArray[m_selectedButton].getPosition().y);
}

void MainWindow::close() {
  std::cout << "App closed" << std::endl;
  m_window->close();
}
