#include "airblower.h"
#include "game_constants.h"

void Airblower::setAirblowerForce(AirblowerForce* p) 
{
    this->m_abf = p;
}

// Returns the position of the airblower base on the screen
sf::Vector2f Airblower::getBasePos() 
{
    sf::Vector2f ret;

    if (m_abf == nullptr) {
        return ret;
    }

    ret.x = m_abf->getPosition().getX();
    ret.y = GameConstants::WinHeight - GameConstants::GrassHeight - m_abf->getPosition().getY();

    return ret;
}

sf::Vector2f Airblower::getBaseSize() 
{
    sf::Vector2f ret;

    if (m_abf == nullptr) {
        return ret;
    }

    // Just return 2 times the max. distance in x-direction to get a sense of how far the blower actually affects... 
    ret.x = m_abf->getDist() * 2;
    ret.y = m_abf->getDist() * 2;

    return ret;
}

sf::Vector2f Airblower::getAirflowPos() 
{
    sf::Vector2f ret;

    if (m_abf == nullptr) {
        return ret;
    }

    ret.x = m_abf->getPosition().getX();
    ret.y = GameConstants::WinHeight - GameConstants::GrassHeight - m_abf->getPosition().getY() - m_abf->getHeight();

    return ret;
}

sf::Vector2f Airblower::getAirflowSize() 
{
    sf::Vector2f ret;

    if (m_abf == nullptr) {
        return ret;
    }

    // Just return 2 times the max. distance in x-direction to get a sense of how far the blower actually affects... 
    ret.x = m_abf->getDist() * 2;
    // This must be the actual height of the airblow-effect
    ret.y = m_abf->getHeight();

    return ret;
}

