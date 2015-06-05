#include "stdafx.h"
#include <iostream>
#include "triangle.h"

using namespace std;

Triangle::Triangle(Point3D _A , Point3D _B , Point3D _C) : A(_A) , B(_B) , C(_C)
{}

Plain Triangle::getPlain() const
{
	return Plain(A , B , C);
}

Line Triangle::getAB() const
{
	return Line(A , B);
}
Line Triangle::getBC() const
{
	return Line(B , C);
}
Line Triangle::getCA() const
{
	return Line(C , A);
}

Line Triangle::getAM() const
{
	Point3D M((B.getX() + C.getX())/2 , (B.getY() + C.getY())/2 , (B.getZ() + C.getZ())/2);
	return Line(A , M);
}
Line Triangle::getBM() const
{
	Point3D M((A.getX() + C.getX())/2 , (A.getY() + C.getY())/2 , (A.getZ() + C.getZ())/2);
	return Line(B , M);
}
Line Triangle::getCM() const
{
	Point3D M((B.getX() + A.getX())/2 , (B.getY() + A.getY())/2 , (B.getZ() + A.getZ())/2);
	return Line(C , M);
}

Point3D Triangle::getCentroid() const
{
	return Point3D(getAM() , getBM());
}

Line Triangle::getAH() const
{
	double x0 , y0 , z0;
	if(getBC().getParallel().getV1() == 0)
		x0 = A.getX();
	else
		x0 = 1;
	if(getBC().getParallel().getV2() == 0)
		y0 = A.getY();
	else
		y0 = 1;
	if(getBC().getParallel().getV3() == 0)
		z0 = A.getZ();
	else
		z0 = 1;
	Point3D H(x0 , y0 , z0);
	Vector AH(A , H);
	return Line(A , AH);
}

Line Triangle::getBH() const
{
	double x0 , y0 , z0;
	if(getCA().getParallel().getV1() == 0)
		x0 = B.getX();
	else
		x0 = 1;
	if(getCA().getParallel().getV2() == 0)
		y0 = B.getY();
	else
		y0 = 1;
	if(getCA().getParallel().getV3() == 0)
		z0 = B.getZ();
	else
		z0 = 1;
	Point3D H(x0 , y0 , z0);
	Vector BH(B , H);
	return Line(B , BH);
}

Line Triangle::getCH() const
{
	double x0 , y0 , z0;
	if(getAB().getParallel().getV1() == 0)
		x0 = C.getX();
	else
		x0 = 1;
	if(getAB().getParallel().getV2() == 0)
		y0 = C.getY();
	else
		y0 = 1;
	if(getAB().getParallel().getV3() == 0)
		z0 = C.getZ();
	else
		z0 = 1;
	Point3D H(x0 , y0 , z0);
	Vector CH(C , H);
	return Line(C , CH);
}

Point3D Triangle::getOrthocentre() const
{
	return Point3D(getAH() , getBH());
}

Line Triangle::getSAB() const
{
	Point3D S((A.getX()+B.getX())/2 , (A.getY()+B.getY())/2 , (A.getZ()+B.getZ())/2);
	double x , y , z;
	if(getAB().getParallel().getV1() == 0)
		x = 1;
	else
		x = 0;
	if(getAB().getParallel().getV2() == 0)
		y = 1;
	else
		y = 0;
	if(getAB().getParallel().getV3() == 0)
		z = 1;
	else
		z = 0;
	return Line(S , Vector(x,y,z));
}

Line Triangle::getSBC() const
{
	Point3D S((C.getX()+B.getX())/2 , (C.getY()+B.getY())/2 , (C.getZ()+B.getZ())/2);
	double x , y , z;
	if(getBC().getParallel().getV1() == 0)
		x = 1;
	else
		x = 0;
	if(getBC().getParallel().getV2() == 0)
		y = 1;
	else
		y = 0;
	if(getBC().getParallel().getV3() == 0)
		z = 1;
	else
		z = 0;
	return Line(S , Vector(x,y,z));
}

Line Triangle::getSCA() const
{
	Point3D S((A.getX()+C.getX())/2 , (A.getY()+C.getY())/2 , (A.getZ()+C.getZ())/2);
	double x , y , z;
	if(getCA().getParallel().getV1() == 0)
		x = 1;
	else
		x = 0;
	if(getCA().getParallel().getV2() == 0)
		y = 1;
	else
		y = 0;
	if(getCA().getParallel().getV3() == 0)
		z = 1;
	else
		z = 0;
	return Line(S , Vector(x,y,z));
}

Point3D Triangle::getDescribedCentre() const
{
	return Point3D(getSAB() , getSBC());
}

Line Triangle::getAL() const
{
	Vector l1(getAB().getParallel().getV1()/getAB().getParallel().getLenght() ,
		getAB().getParallel().getV2()/getAB().getParallel().getLenght() , getAB().getParallel().getV3()/getAB().getParallel().getLenght());
	Vector l2(-getCA().getParallel().getV1()/getCA().getParallel().getLenght() ,
		-getCA().getParallel().getV2()/getCA().getParallel().getLenght() , -getCA().getParallel().getV3()/getCA().getParallel().getLenght());
	return Line(A , l1 + l2);
}

Line Triangle::getBL() const
{
	Vector l1(-getAB().getParallel().getV1()/getAB().getParallel().getLenght() ,
		-getAB().getParallel().getV2()/getAB().getParallel().getLenght() , -getAB().getParallel().getV3()/getAB().getParallel().getLenght());
	Vector l2(getBC().getParallel().getV1()/getBC().getParallel().getLenght() ,
		getBC().getParallel().getV2()/getBC().getParallel().getLenght() , getBC().getParallel().getV3()/getBC().getParallel().getLenght());
	return Line(B , l1 + l2);
}

Line Triangle::getCL() const
{
	Vector l1(-getBC().getParallel().getV1()/getBC().getParallel().getLenght() ,
		-getBC().getParallel().getV2()/getBC().getParallel().getLenght() , -getBC().getParallel().getV3()/getBC().getParallel().getLenght());
	Vector l2(getCA().getParallel().getV1()/getCA().getParallel().getLenght() ,
		getCA().getParallel().getV2()/getCA().getParallel().getLenght() , getCA().getParallel().getV3()/getCA().getParallel().getLenght());
	return Line(C , l1 + l2);
}

Point3D Triangle::getInscribedCentre() const
{
	return Point3D(getAL() , getBL());
}