#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[]) {

  RenderWindow window(VideoMode(1200, 800), "Cows-Bulls", Style::Close | Style::Resize);
  Event event;
  
  while (window.isOpen()) {
	while (window.pollEvent(event)) {
	  if (event.type == Event::Closed) {
		window.close();
	  }
	  if (event.type == Event::Resized) {
		window.setView(View(FloatRect(0, 0, event.size.width, event.size.height)));
	  }
	}
	window.clear(Color(109, 153, 255));
	window.display();
  }
}
