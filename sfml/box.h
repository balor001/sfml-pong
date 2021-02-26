#pragma once
#include <SFML/Graphics.hpp>
#include "particle.h"
#include "gameobject.h"
#include "game_constants.h"

class Box : public GameObject
{
public:

	Box();
	Box(double w, double h) : width(w), height(h) {}
	~Box();

	Particle* m_particle;

	// Set's the particle
	void setPhysicsParticle(Particle* pParticle);

	// Returns the position of the ball on-screen
	sf::Vector2f getPos();

	// Get the width and heigth
	double getWidth() { return this->width; }
	double getHeigth() { return this->height; }

	void setWidth(double w) { this->width = w; }
	void setHeight(double h) { this->height = h; }

	// Updates the bounding box values: min_x, min_y, max_x and max_y
	void update();

private:

	double width, height;

};