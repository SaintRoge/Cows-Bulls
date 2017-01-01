#include "mainwindow.hpp"

MainWindow::MainWindow(sf::RenderWindow *window) {
  m_window = window;
}

MainWindow::~MainWindow() {

}

void MainWindow::start() {  
  while (m_window->isOpen()) {
	while (m_window->pollEvent(m_event)) {
	  if (m_event.type == sf::Event::Closed) {
		m_window->close();
	  }
	  if (m_event.type == sf::Event::Resized) {
		m_window->setView(sf::View(sf::FloatRect(0, 0, m_event.size.width, m_event.size.height)));
	  }
	}
	m_window->clear(sf::Color(109, 153, 255));
	m_window->display();
  }
}
