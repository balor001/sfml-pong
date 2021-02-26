#include "ball.h"

// Set's our particle pointer to given pParticle
void Ball::setPhysicsParticle(Particle* pParticle) 
{
    this->m_particle = pParticle;
}

// Returns the position of the ball on-screen
sf::Vector2f Ball::getPos()
{
    sf::Vector2f ret;

    if (m_particle == nullptr) {
        return ret;
    }

    ret.x = m_particle->getPosition().getX() - radius;
    ret.y = GameConstants::WinHeight - GameConstants::GrassHeight - m_particle->getPosition().getY() - radius;

    return ret;
}

void Ball::update()
{
    this->min_x = m_particle->getPosition().getX() - radius;
    this->max_x = m_particle->getPosition().getX() + radius;
    this->min_y = m_particle->getPosition().getY() - radius;
    this->max_y = m_particle->getPosition().getY() + radius;
}

Ball::Ball()
{
    this->radius = 0.0;
    this->m_particle = nullptr;
    this->min_x = 0.0;
    this->max_x = 0.0;
    this->min_y = 0.0;
    this->max_y = 0.0;
}

Ball::~Ball()
{
}


