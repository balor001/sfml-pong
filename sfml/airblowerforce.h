#pragma once
#include "force.h"

class AirblowerForce : public Force 
{
public:

    // Default constructor
    AirblowerForce();

    // Constructor for airblowerforce
    AirblowerForce(Vector3 p, Vector3 f, double md, double mh) :
        pos(p), force(f), maxdist(md), maxheight(mh) {}

    // Updates the physics of the airblowerforce based on elapsed time
    void updateForce(Particle* p, double duration);

    // Getters for airblowerforce
    Vector3 getPosition(){ return this->pos; }
    double getDist(){ return this->maxdist; }
    double getHeight(){ return this->maxheight; }

    // Setter for abf (AirblowerForce)
    void setPosition(Vector3 p){ this->pos = p; }
    void setForce(Vector3 f){ this->force = f; }
    void setDist(double d){ this->maxdist = d; }
    void setHeight(double h){ this->maxheight = h; }

private:

    Vector3 pos;        // Position of the airblower
    Vector3 force;      // Force-vector
    double maxdist;     // Max distance (or could be radius...)
    double maxheight;   // Max height from the blower (not a very good way to do this...)

};