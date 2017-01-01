#include <SFML/Graphics.hpp>
#include "mainwindow.hpp"

using namespace sf;

int main(int argc, char const *argv[]) {

  RenderWindow window(VideoMode(1200, 800), "Cows-Bulls", Style::Close | Style::Resize);

  MainWindow *mainW = new MainWindow(&window);
  mainW->start();
}
