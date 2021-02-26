#include "airblowerforce.h"
#include <cmath>

void AirblowerForce::updateForce(Particle* p, double duration)
{
	// Make sure the particle is not null!
	if (p != nullptr) {
		// Particle has to have finite mass
		if (p->hasFiniteMass()) {
			// Distance in x-direction has to be less than maxdist
			if (std::abs(p->getPosition().getX() - this->pos.getX()) < maxdist) {
				// Distance in z-direction has to be less than maxdist
				if (std::abs(p->getPosition().getZ() - this->pos.getZ()) < maxdist) {
					// Vertical distance has to be less than maxheight
					if ((p->getPosition().getY() - this->pos.getY()) < maxheight &&
						(p->getPosition().getY() - this->pos.getY()) >= 0.0)
						// Doesn't take surface area into account...
						p->addForce(this->force);
				}
			}
		}
	}
}

AirblowerForce::AirblowerForce()
{
	this->pos = Vector3(0.0, 0.0, 0.0);
	this->force = Vector3(0.0, 0.0, 0.0);
	this->maxdist = 0.0;
	this->maxheight = 0.0;
}
