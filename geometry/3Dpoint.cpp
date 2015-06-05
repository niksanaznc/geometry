#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;
#include "3Dpoint.h"
#include "line.h"

Point3D::Point3D(double _x , double _y , double _z) : x(_x) , y(_y) , z(_z)
{}

Point3D::Point3D(Line a , Line b)
{
	double m = (a.getParallel().getV1()*(b.getPoint().getY() - a.getPoint().getY()) + a.getParallel().getV2()*(a.getPoint().getX() - b.getPoint().getX()))/
				(a.getParallel().getV2()*b.getParallel().getV1() - a.getParallel().getV1()*b.getParallel().getV2());
	x = b.getPoint().getX() + m*b.getParallel().getV1();
	y = b.getPoint().getY() + m*b.getParallel().getV2();
	z = b.getPoint().getZ() + m*b.getParallel().getV3();
}

Point3D::Point3D(Line l , Plain alpha)
{
	double a , b ,c , d;
	a = alpha.getA();
	b = alpha.getB();
	c = alpha.getC();
	d = alpha.getD();
	double m = -(d + a*l.getPoint().getX() + b*l.getPoint().getY() + c*l.getPoint().getZ())/(a*l.getParallel().getV1() + b*l.getParallel().getV2() + c*l.getParallel().getV3());
	x = l.getPoint().getX() + m*l.getParallel().getV1();
	y = l.getPoint().getY() + m*l.getParallel().getV2();
	z = l.getPoint().getZ() + m*l.getParallel().getV3();
}

void Point3D::print()
{
	cout<<'('<<getX()<<','<<getY()<<','<<getZ()<<')'<<endl;
}

bool Point3D::belongsTo(Line const& l) const
{
	return l.contains(*this);
}

bool Point3D::belongsTo(Plain const& alpha) const
{
	return alpha.getA() * x + alpha.getB() * y + alpha.getC() *z + alpha.getD() == 0;
}

void Point3D::translate(Vector const& v)
{
	setX(x + v.getV1());
	setY(y + v.getV2());
	setZ(z + v.getV3());
}

double Point3D::getDistance(Plain const& alpha)
{
	double a , b ,c , d;
	a = alpha.getA();
	b = alpha.getB();
	c = alpha.getC();
	d = alpha.getD();
	return abs((a*x + b*y + c*z + d)/sqrt(a*a + b*b + c*c));
}

double Point3D::getDistance(Line const& l) 
{
	double x1 , y1 , z1 , v1 = l.getParallel().getV1() , v2 = l.getParallel().getV2() , v3 = l.getParallel().getV3() , m;
	m = (v1*(x - l.getPoint().getX()) + v2*(y - l.getPoint().getY()) + v3*(z - l.getPoint().getZ()))/(v1*v1 + v2*v2 + v3*v3);
	x1 = l.getPoint().getX() + m*v1;
	y1 = l.getPoint().getY() + m*v2;
	z1 = l.getPoint().getZ() + m*v3;
	
	Vector v(Point3D(x1 , y1 , z1) , *this);
	return v.getLenght();
}