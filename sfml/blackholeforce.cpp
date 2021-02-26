#include "blackholeforce.h"

void BlackholeForce::updateForce(Particle* p, double duration)
{
	Vector3 diff = this->position - p->getPosition();
	double dist = diff.norm();

	if (dist < this->radius)
	{
		Vector3 f = (diff * (1.0 / (dist * dist))) * this->force;
		p->addForce(f);
	}
}

BlackholeForce::BlackholeForce()
{
	this->position = Vector3(0.0, 0.0, 0.0);
	this->force = 0.0;
	this->radius = 0.0;
}
