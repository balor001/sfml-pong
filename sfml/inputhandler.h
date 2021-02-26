#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"
#include "moveupcommand.h"
#include "movedowncommand.h"
#include "moveleftcommand.h"
#include "moverightcommand.h"

class InputHandler {

public:

    InputHandler();

    // Sets a new command for button
    // void setCommandForButton(Command* button, Command* command);

    Command* handleInput(sf::RenderWindow* pWindow, Game* pMyGame);

private:

    //// Try to use a joystick-class for supporting game controllers
    //int JoystickID = -1;  // The id is assigned in the constructor...
     
    // All the possible controller inputs in the game
    Command* buttonX_;
    Command* buttonY_;
    Command* buttonA_;
    Command* buttonB_;
};