#ifndef LINE_H
#define LINE_H
#include "stdafx.h"
#include "plain.h"


class Line
{
protected:
	Point3D A;
	Vector v;
public:
	Line(Point3D , Point3D);
	Line(Point3D , Vector);
	Line(Plain , Point3D);
	Line(Plain , Plain);
	Vector getParallel() const {return Vector(A , Point3D(A.getX() + v.getV1() , A.getY() + v.getV2() , A.getZ() + v.getV3()));}
	Point3D getPoint() const {return A;}
	void print() const;
	void getPlains() const;
	bool contains(Point3D) const;
	Line getOrthoProjection(Plain const&) const;

	bool isParallelTo(Plain const&) const;
	bool isCrossing(Plain const&) const;
	bool belongsTo(Plain const&) const;

	bool isParallelTo(Line const&) const;
	bool hasCommonPoint(Line const&) const;
	bool isCrossedWith(Line const&) const;
};



#endif