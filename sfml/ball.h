#pragma once
#include <SFML/Graphics.hpp>
#include "particle.h"
#include "gameobject.h"
#include "game_constants.h"

class Ball : public GameObject
{
public:

    Ball();
    Ball(double r) : radius(r) {}
    ~Ball();

    Particle* m_particle;

    // Set's the particle
    void setPhysicsParticle(Particle* pParticle);

    // Returns the position of the ball on-screen
    sf::Vector2f getPos();

    // Get the radius
    double getRadius() { return this->radius; }

    // Set the radius
    void setRadius(double r) { this->radius = r; }

    // Updates the bounding box values: min_x, min_y, max_x and max_y
    void update();

private:

    double radius;

};

