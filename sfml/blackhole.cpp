/*#include "blackhole.h"
#include "game_constants.h"

void Blackhole::setBlackholeForce(BlackholeForce* p)
{
    this->m_bhf = p;
}

// Returns the position of the airblower base on the screen
sf::Vector2f Blackhole::getBasePos()
{
    sf::Vector2f ret;

    if (m_bhf == nullptr) {
        return ret;
    }

    ret.x = m_bhf->getPosition().getX();
    ret.y = GameConstants::WinHeight - GameConstants::GrassHeight - m_bhf->getPosition().getY();

    return ret;
}

sf::Vector2f Blackhole::getBaseSize()
{
    sf::Vector2f ret;

    if (m_bhf == nullptr) {
        return ret;
    }

    // Just return 2 times the max. distance in x-direction to get a sense of how far the blower actually affects... 
    ret.x = m_bhf->getRadius() * 2;
    ret.y = m_bhf->getRadius() * 2;

    return ret;
}

sf::Vector2f Blackhole::getAirflowPos()
{
    sf::Vector2f ret;

    if (m_bhf == nullptr) {
        return ret;
    }

    ret.x = m_bhf->getPosition().getX();
    ret.y = GameConstants::WinHeight - GameConstants::GrassHeight - m_bhf->getPosition().getY() - m_bhf->getHeight();

    return ret;
}

sf::Vector2f Blackhole::getAirflowSize()
{
    sf::Vector2f ret;

    if (m_bhf == nullptr) {
        return ret;
    }

    // Just return 2 times the max. distance in x-direction to get a sense of how far the blower actually affects... 
    ret.x = m_bhf->getRadius() * 2;
    // This must be the actual height of the airblow-effect
    ret.y = m_bhf->getHeight();

    return ret;
}
*/

