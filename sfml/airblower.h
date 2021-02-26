#pragma once
#include <SFML/Graphics.hpp>
#include "airblowerforce.h"

class Airblower 
{
public:

    Airblower() { this->m_abf = nullptr; }

    sf::Vector2f getBasePos();
    sf::Vector2f getBaseSize();

    sf::Vector2f getAirflowPos();
    sf::Vector2f getAirflowSize();

    void setAirblowerForce(AirblowerForce* p);

    AirblowerForce* m_abf;

private:

};
