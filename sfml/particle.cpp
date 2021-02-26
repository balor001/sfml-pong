#include "particle.h"
#include <iostream>

void Particle::update(double deltaTime) 
{
    // Update position vector: s2 = s1 + v1*t
    position = position + velocity * deltaTime;

    Vector3 resultAcc = acceleration;

    // If the object is not kinematic, 
    // compute the acceleration according to current force resultant F = ma --> a = F/m
    if (!isKinematic() && hasFiniteMass()) {
        resultAcc = resultAcc + forceResultant * dInverseMass;
    }

    // Update velocity vector: v2 = v1 + a*t 
    // velocity = velocity + acceleration*deltaTime;
    velocity = velocity + resultAcc * deltaTime;

    // Remember to clear out the forceResultant!
    clearForces();
}

void Particle::printPosition() 
{
    this->position.print();
}

void Particle::setMass(double m) 
{
    if (m > 0.0) {
        this->dInverseMass = 1.0 / m;
    }
}

double Particle::getMass() 
{
    if (this->hasFiniteMass()) 
    {
        return 1.0 / dInverseMass;
    }
    return -1.0;
}

void Particle::setInverseMass(double im) 
{
    this->dInverseMass = im;
}

double Particle::getInverseMass()
{
    return this->dInverseMass;
}

void Particle::addForce(Vector3 f) 
{
    if (!isKinematic()) {
        forceResultant = forceResultant + f;
        // forceResultant += f; // This doesn't work yet...
    }
}

void Particle::clearForces() 
{
    forceResultant = Vector3(0, 0, 0);
}