#include "game.h"

Game::Game()
{
	// Initial position, velocity and acceleration for particle
	Vector3 pos(0.0, 1.8, 0.0);
	Vector3 vel(50.0, 99.0, 0.0);
	Vector3 acc(0.0, 0.0, 0.0);

	// The box particle - the position is the CENTER of the box
	box_particle.setPosition(Vector3(1300.0, 400.0, 0.0));
	box_particle.setMass(200.0);
	// Set our box-gameobject
	myBox.setPhysicsParticle(&box_particle);
	myBox.setWidth(300.0);
	myBox.setHeight(300.0);
	myBox.update();

	// The box particle - the position is the CENTER of the box
	box_particle2.setPosition(Vector3(800.0, 400.0, 0.0));
	box_particle2.setMass(100.0);
	// Set our box-gameobject
	myBox2.setPhysicsParticle(&box_particle2);
	myBox2.setWidth(200.0);
	myBox2.setHeight(200.0);
	myBox2.update();

	// The box particle - the position is the CENTER of the box
	box_particle3.setPosition(Vector3(1300.0, 100.0, 0.0));
	box_particle3.setMass(100.0);
	// Set our box-gameobject
	myBox3.setPhysicsParticle(&box_particle3);
	myBox3.setWidth(320.0);
	myBox3.setHeight(100.0);
	myBox3.update();

	myBall_particle.setPosition(Vector3(150.0, 150.0, 0.0));
	myBall_particle.setVelocity(Vector3(500.0, 500.0, 0.0));
	myBall_particle.setMass(500.0);
	
	myBall.setPhysicsParticle(&myBall_particle);
	myBall.setRadius(50.0);
	myBall.update();

	//
	// Next we construct the forces:
	//    
	// Gravity-force
	gravityForce.setGravity(Vector3(0, -100.0, 0));

	//// Airblower force first
	//abf_first.setPosition(Vector3(400.0, 400.0, 0.0));
	//abf_first.setForce(Vector3(50.0, 2500.0, 0.0));
	//abf_first.setDist(10);
	//abf_first.setHeight(100);

	//// Airblower force other
	//abf_other.setPosition(Vector3(1200.0, 400.0, 0.0));
	//abf_other.setForce(Vector3(50.0, 2500.0, 0.0));
	//abf_other.setDist(10);
	//abf_other.setHeight(150);

	//// Airblower related stuff
	//myBlower.setAirblowerForce(&abf_first);
	//myBlowerOther.setAirblowerForce(&abf_other);

	//// Blackhole force
	//blackholeForce.setPosition(Vector3(800.0, 400.0, 0.0));
	//blackholeForce.setForce(25000.0);
	//blackholeForce.setRadius(1000);

	// Test for some particles and balls!
	for (int i = 0; i < 0; i++) {
		Particle* p = new Particle(Vector3(5.0 + (4.0 + i / 2) * i, 0.0, 0.0),
			Vector3(10.0 + 2.0 * i, 100.0, 0.0),
			Vector3(0.0, 0.0, 0.0));
		p->setMass(1.0 + i);                        // Set mass to 2 kg
		Ball* b = new Ball(4.0 + (i / 2.0));        // Set radius to 10
		b->setPhysicsParticle(p);                   // Set physics particle for this ball
		list_particles.push_back(p);                // Push particle on the particle list
		list_balls.push_back(b);                    // Push ball on the ball list
	}

}

void Game::checkAndResolveBottomWall(Ball* ball) {
	// Test a simple bounce effect... from ground.
	if ((ball)->m_particle->getPosition().getY() - (ball)->getRadius() <= 0.0 &&
		(ball)->m_particle->getVelocity().getY() < 0.0)
	{
		Vector3 vel = (ball)->m_particle->getVelocity();
		double y = vel.getY();
		vel = vel + Vector3(0.0, -2 * y, 0.0);
		//vel = vel * damping;
		(ball)->m_particle->setVelocity(vel);
	}
}

void Game::checkAndResolveRightWall(Ball* ball) {
	// Test a simple bounce effect... from right-hand side wall.
	if ((ball)->m_particle->getPosition().getX() + (ball)->getRadius() >= GameConstants::WinWidth &&
		(ball)->m_particle->getVelocity().getX() > 0.0)
	{
		Vector3 vel = (ball)->m_particle->getVelocity();
		double x = vel.getX();
		vel = vel + Vector3(-2.0 * x, 0.0, 0.0);
		//vel = vel * damping;
		(ball)->m_particle->setVelocity(vel);
	}
}

void Game::checkAndResolveLeftWall(Ball* ball) {
	// Test a simple bounce effect... from left-hand side wall.
	if ((ball)->m_particle->getPosition().getX() - (ball)->getRadius() <= 0.0 &&
		(ball)->m_particle->getVelocity().getX() < 0.0)
	{
		Vector3 vel = (ball)->m_particle->getVelocity();
		double x = vel.getX();
		vel = vel + Vector3(-2.0 * x, 0.0, 0.0);
		//vel = vel * damping;
		(ball)->m_particle->setVelocity(vel);
	}
}

void Game::checkAndResolveTopWall(Ball* ball) {
	// Test a simple bounce effect... from top of the screen.
	if ((ball)->m_particle->getPosition().getY() + (ball)->getRadius() + GameConstants::GrassHeight >= GameConstants::WinHeight &&
		(ball)->m_particle->getVelocity().getY() > 0.0)
	{
		Vector3 vel = (ball)->m_particle->getVelocity();
		double y = vel.getY();
		vel = vel + Vector3(0.0, -2 * y, 0.0);
		//vel = vel * damping;
		(ball)->m_particle->setVelocity(vel);
	}
}

// Updates the game logic - including physics simulation
void Game::update(double deltaTime)
{
	
	// Update forces for the ball particle:
	gravityForce.updateForce(&myBall_particle, 0.0);
	//abf_first.updateForce(&myBall_particle, 0.0);
	//abf_other.updateForce(&myBall_particle, 0.0);
	//blackholeForce.updateForce(&myBall_particle, 0.0);
	myBall_particle.update(deltaTime);

	myBox.update();
	myBox2.update();

	box_particle.update(deltaTime);
	gravityForce.updateForce(&box_particle, 0.0);

	//double damping = 0.9;

	myBall.update();
	checkAndResolveBottomWall(&myBall);
	checkAndResolveLeftWall(&myBall);
	checkAndResolveRightWall(&myBall);
	checkAndResolveTopWall(&myBall);

	// Iterate through the particle list
	for (auto it = list_particles.begin(); it != list_particles.end(); it++)
	{
		gravityForce.updateForce(*it, 0.0);
	//	abf_first.updateForce(*it, 0.0);
	//	abf_other.updateForce(*it, 0.0);
	//	blackholeForce.updateForce(*it, 0.0);

		(*it)->update(deltaTime);
	}

	// Iterate though the balls 
	for (auto it = list_balls.begin(); it != list_balls.end(); it++)
	{

		// Update the ball bounding box
		checkAndResolveBottomWall(*it);
		checkAndResolveLeftWall(*it);
		checkAndResolveRightWall(*it);
		checkAndResolveTopWall(*it);

		(*it)->update();
	}

	// Collisions for ground and walls..
	// Iterate though the balls 
	for (auto it = list_balls.begin(); it != list_balls.end(); it++)
	{
		// Collision detection for balls
		// Iterate though the balls 
		for (auto it2 = list_balls.begin(); it2 != list_balls.end(); it2++)
		{
			if (it == it2)
			{
				continue;
			}
			if (CollisionDetector::testAABBOverlap((*it), (*it2)))
			{
				if (CollisionDetector::detectAndResolveCollision((*it), (*it2)));

				// There was a collision
			}


		}
		if (CollisionDetector::testAABBOverlap((*it), &myBox))
		{
			if (CollisionDetector::detectAndResolveCollision((*it), &myBox));

			// There was a collision
		}

		if (CollisionDetector::testAABBOverlap((*it), &myBall))
		{
			if (CollisionDetector::detectAndResolveCollision((*it), &myBall));

			// There was a collision
		}
	}
	if (CollisionDetector::testAABBOverlap(&myBall, &myBox))
	{
		if (CollisionDetector::detectAndResolveCollision(&myBall, &myBox));

		// There was a collision
	}

	if (CollisionDetector::testAABBOverlap(&myBall, &myBox2))
	{
		if (CollisionDetector::detectAndResolveCollision(&myBall, &myBox2));

		// There was a collision
	}
	
	if (CollisionDetector::testAABBOverlap(&myBall, &myBox3))
	{
		if (CollisionDetector::detectAndResolveCollision(&myBall, &myBox3));

		// There was a collision
	}
}