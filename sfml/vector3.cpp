#include "vector3.h"
#include <iostream>
#include <cmath>

void Vector3::print() {

	std::cout << "[" << x << "," << y << "," << z << "]";
}

Vector3 Vector3::operator + (Vector3 other) {
	return Vector3(this->x + other.x,
				   this->y + other.y,
				   this->z + other.z);
}

Vector3 Vector3::operator - (Vector3 other) {
	return Vector3(this->x - other.x,
		           this->y - other.y,
		           this->z - other.z);
}

Vector3 Vector3::operator * (double c) {
	return Vector3(this->x * c,
			       this->y * c,
			       this->z * c);
}

// Returns the dot product of two vectors - the caller must take care of the vector lengths!
double Vector3::operator * (Vector3 other) {
	double dResult = 0.0;

	dResult += this->x * other.x;
	dResult += this->y * other.y;
	dResult += this->z * other.z;

	return dResult;
}

// Computes the Euclidian norm
double Vector3::norm() {
	// Use the dot product
	return std::sqrt((*this) * (*this));
}