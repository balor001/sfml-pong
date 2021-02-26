#pragma once
#include "force.h"

class BlackholeForce : public Force
{
public:

	BlackholeForce();

    BlackholeForce(Vector3 pos, double f, double r) :
        position(pos), force(f), radius(r) {}

    // Updates the force on the black hole - duration not needed...Ai 
    void updateForce(Particle* p, double duration);

    // Getters for black hole force
    Vector3 getPosition() { return this->position; }
    double getForce() { return this->force; }
    double getRadius() { return this->radius; }

    // Setters for black hole force
    void setPosition(Vector3 p) { this->position = p; }
    void setForce(double f) { this->force = f; }
    void setRadius(double d) { this->radius = d; }

private:

    Vector3 position;   // Position of the black hole force
    double force;       // Force value
    double radius;      // Radius for the black hole force

};