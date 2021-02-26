#include "collisiondetector.h"
#include <iostream>

// Muuta tämä niin että pallon ja pallon sijaan täällä onkin 
// GameObject ja GameObject*
// Tällöin tätä voidaan hyödyntää myös pallon ja laatikon välistä törmäystä.
// Vaihda Ball tilalle GameObject, koska ne on periytetty GameObjectista.
bool CollisionDetector::testAABBOverlap(GameObject* obj1, GameObject* obj2)
{
	float d1x = obj2->min_x - obj1->max_x;
	float d1y = obj2->min_y - obj1->max_y;
	float d2x = obj1->min_x - obj2->max_x;
	float d2y = obj1->min_y - obj2->max_y;

	if (d1x > 0.0f || d1y > 0.0f)
		return false;

	if (d2x > 0.0f || d2y > 0.0f)
		return false;

	return true;
}

bool CollisionDetector::detectAndResolveCollision(Ball* b1, Ball* b2)
{
	// Vector between b1 and b2
	Vector3 v = b2->m_particle->getPosition() - b1->m_particle->getPosition();

	// The distance is norm of vector v minus the sum of radii
	double dist = v.norm() - (b1->getRadius() + b2->getRadius());

	// If the distance is smaller than zero
	if (dist < 0.0)
	{
		// Resolve the penetration first
		resolvePenetration(b1, b2, v, dist);
		// Then resolve the collision and modify velocities
		resolveCollision(b1, b2);

		return true;
	}
	else
	{
		return false;
	}
}

void CollisionDetector::resolveCollision(Ball* b1, Ball* b2)
{
	// Compute the velocities
	Vector3 v12 = b1->m_particle->getVelocity() - b2->m_particle->getVelocity();
	Vector3 v21 = b2->m_particle->getVelocity() - b1->m_particle->getVelocity();

	Vector3 x12 = b1->m_particle->getPosition() - b2->m_particle->getPosition();
	Vector3 x21 = b2->m_particle->getPosition() - b1->m_particle->getPosition();

	double mass1 = b1->m_particle->getMass();
	double mass2 = b2->m_particle->getMass();
	double totmass = mass1 + mass2;

	Vector3 v1_new = b1->m_particle->getVelocity() - x12 * (2 * mass2 * (v12 * x12) / (totmass * x12.norm() * x12.norm()));
	Vector3 v2_new = b2->m_particle->getVelocity() - x21 * (2 * mass1 * (v21 * x21) / (totmass * x21.norm() * x21.norm()));

	b1->m_particle->setVelocity(v1_new);
	b2->m_particle->setVelocity(v2_new);
	/*Kolmas kohta eli törmäysten varsinainen ratkaisu on jälleen vähän monimutkaisempaa kuin edellinen... Yritetään selvittää pallojen törmäystä hieman alla olevalla kuvalla : TODO!!!*/
	//std::cout << "Collision";
}

void CollisionDetector::resolvePenetration(Ball* b1, Ball* b2, Vector3 v, double dist)
{
	// Compute the penetration vector between b1 and b2
	Vector3 penetration = v * (-dist / v.norm());

	// How much should we move b1 and b2?
	double invmass1 = b1->m_particle->getInverseMass();
	double invmass2 = b2->m_particle->getInverseMass();
	double totinvmass = invmass1 + invmass2;

	Vector3 move1;
	Vector3 move2;

	if (totinvmass > 0.0)
	{
		move1 = penetration * (-invmass1 / totinvmass);
		move2 = penetration * (invmass2 / totinvmass);
	}
	else
	{
		// Both have infinite mass ...
		move1 = penetration * -0.5;
		move2 = penetration * 0.5;
	}

	b1->m_particle->setPosition(b1->m_particle->getPosition() + move1);
	b2->m_particle->setPosition(b2->m_particle->getPosition() + move2);
	//b1->m_particle->setVelocity(move1-penetration);
	//b2->m_particle->setVelocity(move2+penetration);
}

// Tästä eteenpäin on pallon ja boxin törmäys ja niiden ratkaisu.
bool CollisionDetector::detectAndResolveCollision(Ball* ball, Box* box)
{
	double radius = ball->getRadius(); // Radius of the ball
	double ball_x = ball->m_particle->getPosition().getX();
	double ball_y = ball->m_particle->getPosition().getY();

	// Vector between ball and box
	Vector3 v = box->m_particle->getPosition() - ball->m_particle->getPosition();

	// The distance is norm of vector v minus the sum of radii
	double dist = v.norm() - (radius + (box->getHeigth() * box->getWidth()));

	// 4 Easy cases:
	// Checks above or below
	if (ball_x >= box->min_x && ball_x <= box->max_x)
	{
		// Check above: y-coordinate collides and y-speed is negative
		if (ball_y - radius <= box->max_y && ball->m_particle->getVelocity().getY() < 0.0)
		{
			Vector3 vel = ball->m_particle->getVelocity();
			double y = vel.getY();
			vel = vel + Vector3(0.0, -2 * y, 0.0);
			//vel = vel * damping;
			ball->m_particle->setVelocity(vel);
			return true;
		}

		// Check below: y-coordinate collides and y-speed is positive
		else if (ball_y + radius >= box->min_y &&
			ball->m_particle->getVelocity().getY() > 0.0)
		{
			Vector3 vel = ball->m_particle->getVelocity();
			double y = vel.getY();
			vel = vel + Vector3(0.0, -2 * y, 0.0);
			//vel = vel * damping;
			ball->m_particle->setVelocity(vel);
			return true;
		}
	}

	// Checks left and right side
	if (ball_y >= box->min_y && ball_y <= box->max_y)
	{
		// Check left side: x-coord + radius bigger than min_x and x_speed > 0.0
		if (ball_x + radius >= box->min_x && ball->m_particle->getVelocity().getX() > 0.0)
		{
			Vector3 vel = ball->m_particle->getVelocity();
			double x = vel.getX();
			vel = vel + Vector3(-2.0 * x, 0.0, 0.0);
			//vel = vel * damping;
			ball->m_particle->setVelocity(vel);
			return true;
		}

		// Check right side: x-coord - radius smaller than max_x and x_speed < 0.0
		else if (ball_x - radius <= box->max_x && ball->m_particle->getVelocity().getX() < 0.0)
		{
			Vector3 vel = ball->m_particle->getVelocity();
			double x = vel.getX();
			vel = vel + Vector3(-2.0 * x, 0.0, 0.0);
			//vel = vel * damping;
			ball->m_particle->setVelocity(vel);
			return true;
		}

	}

	// 4 Corners:
	// ???
	// 1. Computes distance to all 4 corners 
	// 2. Check if anu of these is smaller than the radius of the ball 
	double dx, dy;

	// Top Left
	dx = box->min_x - ball_x;
	dy = ball_y - box->max_y;

	if ((dx * dx + dy * dy) <= radius * radius)
	{
		Vector3 vel = ball->m_particle->getVelocity();
		vel = vel * (-1);    // Reverse the velocity vector
		ball->m_particle->setVelocity(vel);

		return true;
	}

	// Top Right
	dx = ball_x - box->max_x;
	dy = ball_y - box->max_y;

	if ((dx * dx + dy * dy) <= radius * radius)
	{
		Vector3 vel = ball->m_particle->getVelocity();
		vel = vel * (-1);    // Reverse the velocity vector
		ball->m_particle->setVelocity(vel);
		return true;
	}

	// Bottom Right
	dx = ball_x - box->max_x;
	dy = box->min_y - ball_y;

	if ((dx * dx + dy * dy) <= radius * radius)
	{
		Vector3 vel = ball->m_particle->getVelocity();
		vel = vel * (-1);    // Reverse the velocity vector
		ball->m_particle->setVelocity(vel);
		return true;
	}

	// Bottom Left
	dx = box->min_x - ball_x;
	dy = box->min_y - ball_y;

	if ((dx * dx + dy * dy) <= radius * radius)
	{
		Vector3 vel = ball->m_particle->getVelocity();
		vel = vel * (-1);    // Reverse the velocity vector
		ball->m_particle->setVelocity(vel);
		return true;
	}
}

void CollisionDetector::resolveCollision(Ball* ball, Box* box)
{
	// Compute the velocities
	Vector3 v12 = ball->m_particle->getVelocity() - box->m_particle->getVelocity();
	Vector3 v21 = box->m_particle->getVelocity() - ball->m_particle->getVelocity();

	Vector3 x12 = ball->m_particle->getPosition() - box->m_particle->getPosition();
	Vector3 x21 = box->m_particle->getPosition() - ball->m_particle->getPosition();

	double mass1 = ball->m_particle->getMass();
	double mass2 = box->m_particle->getMass();
	double totmass = mass1 + mass2;

	Vector3 v1_new = ball->m_particle->getVelocity() - x12 * (2 * mass2 * (v12 * x12) / (totmass * x12.norm() * x12.norm()));
	Vector3 v2_new = box->m_particle->getVelocity() - x21 * (2 * mass1 * (v21 * x21) / (totmass * x21.norm() * x21.norm()));

	ball->m_particle->setVelocity(v1_new);
	box->m_particle->setVelocity(v2_new);
	/*Kolmas kohta eli törmäysten varsinainen ratkaisu on jälleen vähän monimutkaisempaa kuin edellinen... Yritetään selvittää pallojen törmäystä hieman alla olevalla kuvalla : TODO!!!*/
	//std::cout << "Collision";
}

void CollisionDetector::resolvePenetration(Ball* ball, Box* box, Vector3 v, double dist)
{
	// Compute the penetration vector between b1 and b2
	Vector3 penetration = v * (-dist / v.norm());

	// How much should we move b1 and b2?
	double invmass1 = ball->m_particle->getInverseMass();
	double invmass2 = box->m_particle->getInverseMass();
	double totinvmass = invmass1 + invmass2;

	Vector3 move1;
	Vector3 move2;

	if (totinvmass > 0.0)
	{
		move1 = penetration * (-invmass1 / totinvmass);
		move2 = penetration * (invmass2 / totinvmass);
	}
	else
	{
		// Both have infinite mass ...
		move1 = penetration * -0.5;
		move2 = penetration * 0.5;
	}

	ball->m_particle->setPosition(ball->m_particle->getPosition() + move1);
	box->m_particle->setPosition(box->m_particle->getPosition() + move2);
	//b1->m_particle->setVelocity(move1-penetration);
	//b2->m_particle->setVelocity(move2+penetration);
}