#pragma once
#include "particle.h"

class EffectParticle : public Particle 
{
public:

    EffectParticle(double lt, bool bact, int color) : dLifetime(lt), bActive(bact), rgba(color) {
        Particle(Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0));
    };

    bool isActive() { return this->bActive; }
    void activate() { this->bActive = true; }
    void setLifetime(double lt) { this->dLifetime = lt; }

    void setColor(int newcolor) { this->rgba = newcolor; }
    void setRGBA(int R, int G, int B, int A);

    int getR();
    int getG();
    int getB();
    int getA();

    void update(double delta);

private:

    // Lifetime of the particle
    double dLifetime;

    // Is this particle active?
    bool bActive;

    // Maybe the color???
    int rgba;
};