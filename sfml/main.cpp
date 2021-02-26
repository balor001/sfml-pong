#include <SFML/Graphics.hpp>
#include "game_constants.h"
#include "game.h"
#include "renderer.h"
#include <iostream>
#include "inputhandler.h"

int main()
{
	// Create the window - acts as a render target!
	sf::RenderWindow window(sf::VideoMode(GameConstants::WinWidth,
		GameConstants::WinHeight), "SFML works!");

	// Limit the frame rate    
	window.setFramerateLimit(60);

	// Let's contstruct our game-object and renderer-object
	Game myGame;
	Renderer myRenderer;
	InputHandler myInputHandler;

	// --------------------------------------------------------
	// The actual game loop related stuff starts somewhere around here...
	// --------------------------------------------------------

	// This should actually be computed with clock...
	double deltaTime = 0.001;
	//double delta = 1.0 / 60.0;  // This is in seconds and using the framerate

	sf::Clock clock;
	sf::Time elapsed_time = clock.restart();

	double accumulator = 0.0;

	// Get position from particle - used for interpolation later on...
	//Vector3 curr_pos = myGame.particle.getPosition();
	//Vector3 last_pos = curr_pos;

	// --------------------------------------------------------
	// The "game loop" starts right here! In SFML, it's standard practive to use
	// a while-loop like the one below.
	// --------------------------------------------------------
	while (window.isOpen()) {

		elapsed_time = clock.getElapsedTime();
		double frametime = elapsed_time.asSeconds();
		clock.restart();

		accumulator += frametime;

		// Inputhandler
		Command* cmd = myInputHandler.handleInput(&window, &myGame);

		if (cmd != nullptr)
		{
			cmd->execute(myGame.myBall);
		}

		// --------------------------------------------------------
		// Game Logic here:
		// --------------------------------------------------------

		// Update our particle physics model
		while (accumulator >= deltaTime) {

			myGame.update(deltaTime);

			//last_pos = curr_pos;
			//curr_pos = myGame.particle.getPosition();
			accumulator -= deltaTime;
		}

		// The remainder "in between simulation steps" - NOT USED NOW
		const double alpha = accumulator / deltaTime;

		// particle.printPosition(); // just for debug..

		// Interpolate the position for the particle - NOT USED NOW
		//Vector3 interp_pos = curr_pos * alpha + last_pos * (1 - alpha);

		// set the position for our moving circle, but 
		// ONLY if it is above ground -  NOT USED NOW!
		/*  interpolate the particle's position
		if (curr_pos.getY() >= 0.0){
			moving_circle.setPosition(
				sf::Vector2f(interp_pos.getX(),
							GameConstants::WinHeight-interp_pos.getY()-grass.getSize().y));
		}
		*/

		// Render the game to the screen/window using renderer object
		myRenderer.render(&window, &myGame);
	}

	return 0;
}