#ifndef PLAIN_H
#define PLAIN_H

#include "vector.h"
class Line;

class Plain
{
private:
	Point3D A;
	Vector u , v;
public:
	Plain(double = 1 , double = 1 , double = 0 , double = 0);
	Plain(Point3D , Point3D , Point3D);
	Plain(Line , Point3D);
	Plain(Plain , Point3D);
	Plain(Vector , Vector , Point3D);
	Point3D getPoint() const {return A;}
	Vector getUParallel() const {return u;}
	Vector getVParallel() const{return v;}
	
	double getA() const;
	double getB() const;
	double getC() const;
	double getD() const;

	void commonPrint() const;
	void parametricPrint() const;
	void plainPosition(Plain const&) const;
};

#endif