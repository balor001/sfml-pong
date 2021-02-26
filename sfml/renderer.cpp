#include "renderer.h"
#include <iostream>

void Renderer::updateShapes(Game* pGame) {
	
	// Load texture
	if (!ball_texture.loadFromFile("ball_red.png"))
	{
		std::cout << "Loading failed!" << std::endl;
	}
	else
	{
		ball_sprite.setTexture(ball_texture);
	}
	
	// ------------------------------
	// Shapes:
	// ------------------------------
	// Background as black rectangle
	bgshape.setSize(sf::Vector2f(GameConstants::WinWidth,
		GameConstants::WinHeight));
	bgshape.setFillColor(sf::Color::Black);

	// Let's do the ground with some more graphics shapes
	//grass.setSize(sf::Vector2f(GameConstants::WinWidth, GameConstants::GrassHeight));
	//grass.setPosition(0, GameConstants::WinHeight - grass.getSize().y);
	//grass.setFillColor(sf::Color::Green);

	// Let's do the ground with some more graphics shapes
	box.setSize(sf::Vector2f(pGame->myBox.getWidth(), pGame->myBox.getHeigth()));
	box.setPosition(pGame->myBox.getPos());
	box.setFillColor(sf::Color::Magenta);

	// Let's do an object for the airblower
	airblower.setSize(pGame->myBlower.getBaseSize());
	airblower.setPosition(pGame->myBlower.getBasePos());
	airblower.setFillColor(sf::Color::Blue);
	// Let's do another airblower
	airblower_other.setSize(pGame->myBlowerOther.getBaseSize());
	airblower_other.setPosition(pGame->myBlowerOther.getBasePos());
	airblower_other.setFillColor(sf::Color::Magenta);
	// Let's do an object for the airflow
	airblower_air.setSize(pGame->myBlower.getAirflowSize());
	airblower_air.setPosition(pGame->myBlower.getAirflowPos());
	airblower_air.setFillColor(sf::Color::Yellow);
	// Let's do another airflow
	airblower_air_other.setSize(pGame->myBlowerOther.getAirflowSize());
	airblower_air_other.setPosition(pGame->myBlowerOther.getAirflowPos());
	airblower_air_other.setFillColor(sf::Color::Yellow);

	// Black hole
	black_hole.setRadius(pGame->blackholeForce.getRadius() / 100);
	black_hole.setFillColor(sf::Color::Blue);
	black_hole.setPosition(sf::Vector2f(pGame->blackholeForce.getPosition().getX() - (black_hole.getRadius()), 
		GameConstants::WinHeight - GameConstants::GrassHeight - pGame->blackholeForce.getPosition().getY() - (black_hole.getRadius())));


}

void Renderer::render(sf::RenderWindow* rw, Game* pGame)
{
	// Update the shapes we need to draw
	this->updateShapes(pGame);
	
	// --------------------------------------------------------
	// "Rendering" part of the code:
	// --------------------------------------------------------

	// Clear window
	rw->clear();

	// Draw the "background" shape
	rw->draw(bgshape);

	// Draw the "grass"
	//rw->draw(grass);

	// Draw the "box"
	rw->draw(box);

	// Draw the airblower
	rw->draw(airblower);
	rw->draw(airblower_air);

	// Draw the other airblower
	rw->draw(airblower_other);
	rw->draw(airblower_air_other);

	// Draw the black hole
	rw->draw(black_hole);

	// Draw the moving small circle
	// Check particle position - must be 0 or greater

	if (pGame->myBall_particle.getPosition().getY() >= 0.0)
	{
		// Shape for our balls
		myCircle.setFillColor(sf::Color::Cyan);
		myCircle.setRadius(pGame->myBall.getRadius());
		myCircle.setPosition(pGame->myBall.getPos());

		ball_sprite.setPosition(pGame->myBall.getPos());
		ball_sprite.setScale(sf::Vector2f(pGame->myBall.getRadius() * 2 / ball_texture.getSize().x,
			pGame->myBall.getRadius() * 2 / ball_texture.getSize().y));
	}

	// Draw one ball
	//rw->draw(myCircle);

	rw->draw(ball_sprite);


	// Draw all balls from the ball list
	for (auto it = pGame->list_balls.begin(); it != pGame->list_balls.end(); it++)
	{
		if ((*it)->m_particle->getPosition().getY() >= 0.0)
		{
			// Shape for our balls
			moving_circle.setFillColor(sf::Color::Red);
			moving_circle.setPosition(sf::Vector2f(20.0f, 500.0f));

			
			moving_circle.setPosition((*it)->getPos());
			moving_circle.setRadius((*it)->getRadius());
			rw->draw(moving_circle);
		}
	}

	// "Copy the stuff to screen"
	rw->display();
}