#ifndef VECTOR_H
#define VECTOR_H

#include "3Dpoint.h"

class Plain;

class Vector
{
private:
	double v1 , v2 , v3;
public:
	Vector(double = 0 , double = 0 , double = 0);
	Vector(Point3D , Point3D);
	Vector(Plain);

	double getV1() const{return v1;}
	double getV2() const{return v2;}
	double getV3() const{return v3;}

	void setV1(double v){v1 = v;}
	void setV2(double v){v2 = v;}
	void setV3(double v){v3 = v;}

	void print() const;
	double getLenght() const;
	double operator*(Vector const&);
	double operator*=(Vector const&);
	Vector operator+(Vector const&);
	void operator+=(Vector const&);
	Vector Xmultiply(Vector const&);
};


#endif