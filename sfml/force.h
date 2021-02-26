// Abstract base class for forces 
// Based on the book 'Game Physics Engine Development' by Ian Millington
// 
// You should derive your forces from this class and override
// the updateForce-method to implement the actual force effect.
#pragma once
#include "particle.h"

class Force 
{
public:

	// Pure virtual method - this need to be overriden in derived class
	virtual void updateForce(Particle * p, double duration) = 0;
};