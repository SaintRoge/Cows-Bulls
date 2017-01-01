#include <SFML/Graphics.hpp>

class MainWindow {
public:
  MainWindow(sf::RenderWindow *window);
  ~MainWindow();
private:
  sf::RenderWindow *m_window;
};
