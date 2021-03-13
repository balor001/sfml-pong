#pragma once
#include "ball.h"
#include "airblower.h"
#include "gravityforce.h"
#include "airblowerforce.h"
#include "game_constants.h"
#include "blackholeforce.h"
#include "collisiondetector.h"
#include "box.h"
#include <SFML/Graphics.hpp>
#include <list>

class Game
{
public:

	Game();

	void update(double deltaTime);

	// Member variables
	Particle box_particle;
	Particle box_particle2;
	Particle box_particle3;
	Box myBox;
	Box myBox2;
	Box myBox3;
	
	Ball myBall;
	Particle myBall_particle;

	// Member variables for forces
	GravityForce gravityForce;

	//// Member variables for Airblowers
	//Airblower myBlower;
	//Airblower myBlowerOther;

	//// Member variables for Airflows
	//AirblowerForce abf_first;
	//AirblowerForce abf_other;

	////Blackholeforce;
	//BlackholeForce blackholeForce;

	// Lists for particles and balls
	std::list<Particle*> list_particles;
	std::list<Ball*> list_balls;

private:
	// Helper for bottom wall bounce
	void checkAndResolveBottomWall(Ball* b);
	void checkAndResolveRightWall(Ball* b);
	void checkAndResolveLeftWall(Ball* b);
	void checkAndResolveTopWall(Ball* b);
};