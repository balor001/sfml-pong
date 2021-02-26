#include "inputhandler.h"

InputHandler::InputHandler() {

	// Assign the command pointers
	buttonY_ = new MoveUpCommand();
	buttonX_ = new MoveLeftCommand();
	buttonA_ = new MoveDownCommand();
	buttonB_ = new MoveRightCommand();

	//// Find a joystick...
	//sf::Joystick::update();
	//for (int i = 0; i < 31; i++) {
	//	if (sf::Joystick::isConnected(i)) {
	//		this->JoystickID = i;
	//		std::cout << "Joystick " << JoystickID << " is connected!" << std::endl;
	//		break;
	//	}
	//}

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
				return buttonY_;
				//pMyGame->BallUp();
				//buttonY_->execute();
			}
			if (event.key.code == sf::Keyboard::A)
				return buttonX_;
			//pMyGame->BallLeft();
			if (event.key.code == sf::Keyboard::S)
				return buttonA_;
			//pMyGame->BallDown();
			if (event.key.code == sf::Keyboard::D)
				return buttonB_;
			//pMyGame->BallRight();      
		}

		//if (JoystickID >= 0 && sf::Joystick::isConnected(JoystickID)) {
		//	for (int i = 0; i < 32; i++) {
		//		if (sf::Joystick::isButtonPressed(JoystickID, i)) {
		//			std::cout << "Button " << i << " was pressed!" << std::endl;
		//		}
		//	}
		//}

	} // end while

	return nullptr;
}
