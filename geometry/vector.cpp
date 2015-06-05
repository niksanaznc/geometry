#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

#include "vector.h"
#include "plain.h"

Vector::Vector(double x , double y , double z) : v1(x) , v2(y) , v3(z)
{}

Vector::Vector(Point3D A , Point3D B) : v1(B.getX() -A.getX()) , v2(B.getY() -A.getY()) , v3(B.getZ() -A.getZ())
{}

Vector::Vector(Plain alpha)
{
	v1 = alpha.getA();
	v2 = alpha.getB();
	v3 = alpha.getC();
}

void Vector::print() const
{
	cout<<'('<<getV1()<<','<<getV2()<<','<<getV3()<<')'<<endl;
}

Vector sumVectors(Vector v1, Vector v2)
{
	return Vector(v1.getV1() + v2.getV1() , v1.getV2() + v2.getV2() , v1.getV3() + v2.getV3());
}

Vector Vector::operator+(Vector const& v)
{
	return Vector(v1 + v.getV1() , v2 + v.getV2() , v3 + v.getV3());
}

void Vector::operator+=(Vector const& v)
{
	v1 += v.getV1();
	v2 += v.getV2();
	v3 += v.getV3();
}

double Vector::operator*(Vector const& v)
{
	return v.getV1()*getV1() + v.getV2()*getV2() + v.getV3()*getV3();
}

double Vector::operator*=(Vector const& v)
{
	return *this * v;
}

Vector Vector::Xmultiply(Vector const& v)
{
	return Vector(getV2()*v.getV3()-v.getV2()*getV3() , getV3()*v.getV1()-v.getV3()*getV1() , getV1()*v.getV2()-v.getV1()*getV2());
}

double Vector::getLenght() const
{
	return sqrt(getV1()*getV1() + getV2()*getV2() + getV3()*getV3());
}