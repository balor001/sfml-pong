#pragma once

class GameObject
{
public:

    // Updates the bounding box values: min_x, min_y, max_x and max_y
    virtual void update() = 0;

    double min_x, min_y, max_x, max_y = 0;

private:

};