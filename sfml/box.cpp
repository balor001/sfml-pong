#include "game_constants.h"
#include "box.h"

// Set's our particle pointer to given pParticle
void Box::setPhysicsParticle(Particle* pParticle)
{
    this->m_particle = pParticle;
}

// Returns the position of the ball on-screen
sf::Vector2f Box::getPos()
{
    sf::Vector2f ret;

    if (m_particle == nullptr) {
        return ret;
    }

    ret.x = m_particle->getPosition().getX() - width / 2.0;
    ret.y = GameConstants::WinHeight - GameConstants::GrassHeight - m_particle->getPosition().getY() - height / 2.0;

    return ret;
}

void Box::update()
{
    this->min_x = m_particle->getPosition().getX() - width / 2.0;
    this->max_x = m_particle->getPosition().getX() + width / 2.0;
    this->min_y = m_particle->getPosition().getY() - height / 2.0;
    this->max_y = m_particle->getPosition().getY() + height / 2.0;
}

Box::Box()
{
    this->width = 0.0;
    this->height = 0.0;
    this->m_particle = nullptr;
    this->min_x = 0.0;
    this->min_y = 0.0;
    this->max_x = 0.0;
    this->max_y = 0.0;
}

Box::~Box()
{
}


