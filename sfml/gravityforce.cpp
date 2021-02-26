#include "gravityforce.h"

// Updates the force on the particle
void GravityForce::updateForce(Particle* p, double duration) 
{
	// Make sure the particle is not null!
	if (p != nullptr)
	{
		// Only if the particle has finite mass.
		if (p->hasFiniteMass())
		{
			//... Add the gravity's accerelation*mass to the particle
			// Remember! F = ma ( a == g here...)
			p->addForce(this->gravity * p->getMass());
		}
	}
}

GravityForce::GravityForce()
{
	this->gravity = Vector3(0.0, 0.0, 0.0);
}