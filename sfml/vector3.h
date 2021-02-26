#pragma once

class Vector3 
{
public:

    // The default constructor
    Vector3()
    {
        x = y = z = 0.0;
    };

    // The constructor for vector
    Vector3(double x_init, double y_init, double z_init) : x(x_init), y(y_init), z(z_init){}

    // This returns the number of elements
    int length() { return 3; }

    // Adds two vectors together
    Vector3 operator + (Vector3 other);

    // Subtracts the other vector from this one
    Vector3 operator - (Vector3 other);

    // Multiplies with scalar
    Vector3 operator * (double c);

    // Computes the dot product of two vectors - the caller must take care of vector lengths!
    double operator * (Vector3 other);

    // Computes the norm of the vector
    double norm();

    // Getters for x, y and z
    double getX() { return x; };
    double getY() { return y; };
    double getZ() { return z; };

    void print();

private:
    // x, y, z
    double x;
    double y;
    double z;
};