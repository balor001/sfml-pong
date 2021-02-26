#include "effect_particle.h"

void EffectParticle::update(double delta) 
{
    this->dLifetime -= delta;

    if (this->dLifetime <= 0.0) {
        this->bActive = false;
        return;
    }

    // Maybe update the alpha???

    // Call parent update
    Particle::update(delta);
    return;
}

void EffectParticle::setRGBA(int R, int G, int B, int A) {
    this->rgba = (R << 24 | G << 16 | B << 8 | A);
}

int EffectParticle::getR() {
    return (this->rgba >> 24) & 0xFF;
}

int EffectParticle::getG() {
    return (this->rgba >> 16) & 0xFF;
}

int EffectParticle::getB() {
    return (this->rgba >> 8) & 0xFF;;
}

int EffectParticle::getA() {
    return (this->rgba) & 0xFF;
}