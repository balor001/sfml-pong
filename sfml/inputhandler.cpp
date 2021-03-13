#include "inputhandler.h"

InputHandler::InputHandler() {

	// Assign the command pointers
	buttonY_ = new MoveUpCommand();
	buttonX_ = new MoveLeftCommand();
	buttonA_ = new MoveDownCommand();
	buttonB_ = new MoveRightCommand();
}

Command* InputHandler::handleInput(sf::RenderWindow* pWindow,
	Game* pMyGame) {

	sf::Event event;
	while (pWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			pWindow->close();

		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape)
				pWindow->close();
		}

		// If W,A,S or D is pressed, give some force
		// to our ball 
		if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::W) {
				std::cout << "W" << std::endl;
				return buttonY_;
			}

			if (event.key.code == sf::Keyboard::A) {
				std::cout << "A" << std::endl;
				return buttonX_;
			}

			if (event.key.code == sf::Keyboard::S) {
				std::cout << "S" << std::endl;
				return buttonA_;
			}

			if (event.key.code == sf::Keyboard::D) {
				std::cout << "D" << std::endl;
				return buttonB_;
			}
		}
	}
	return nullptr;
}
