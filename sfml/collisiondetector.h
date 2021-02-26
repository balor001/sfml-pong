#pragma once
#include "ball.h"
#include "box.h"

class CollisionDetector 
{
public:

    // Test if there might be a collision
    static bool testAABBOverlap(GameObject* b1, GameObject* b2);

    // Detects and resolves the collision between two balls
    static bool detectAndResolveCollision(Ball* b1, Ball* b2);

    // Detects and resolves the collision between a ball and a box
    static bool detectAndResolveCollision(Ball* ball, Box* box);

private:

    // Resolves the collision i.e. computes velocities of balls b1 and b2 after
    // the collision. MODIFIES THE VELOCITIES!!!
    static void resolveCollision(Ball* b1, Ball* b2);
    // Removes any penetration between balls b1 and b2 i.e.
    // moves the objects according to their weight. MODIFIES THE POSITIONS!
    static void resolvePenetration(Ball* b1, Ball* b2, Vector3 v, double dist);


    // Resolves the collision i.e. computes velocities of ball and box after
    // the collision. MODIFIES THE VELOCITIES!!!
    static void resolveCollision(Ball* ball, Box* box);

    // Removes any penetration between ball and a box
    // moves the objects according to their weight. MODIFIES THE POSITIONS!
    static void resolvePenetration(Ball* ball, Box* box, Vector3 v, double dist);

};