#pragma once
#include "command.h"

class MoveDownCommand : public Command
{
public:

    virtual void execute(Ball& ball)
    {
        // Move the "player" up
        Vector3 vel = ball.m_particle->getVelocity();
        vel = vel + Vector3(0.0, -25.0, 0.0);
        ball.m_particle->setVelocity(vel);
    }
};