#include "stdafx.h"
#include <iostream>
#include "line.h"

using namespace std;

Line::Line(Point3D _A , Point3D _B) : A(_A) , v(_A , _B)
{}

Line::Line(Point3D _A , Vector _v) : A(_A) , v(_v)
{}

Line::Line(Plain alpha , Point3D M) : A(M)
{
	v.setV1(alpha.getA());
	v.setV2(alpha.getB());
	v.setV3(alpha.getC());
}

Line::Line(Plain alpha , Plain beta)
{
	double a , b ,c , d;
	a = alpha.getA();
	b = alpha.getB();
	c = alpha.getC();
	d = alpha.getD();
	double a1 , b1 ,c1 ,d1;
	a1 = beta.getA();
	b1 = beta.getB();
	c1 = beta.getC();
	d1 = beta.getD();
	if((a*c1 - a1*c) != 0)
	{
		A.setX((c*d1-d*c1)/(a*c1 - a1*c));
		A.setY(0);
		A.setZ((d*a1-d1*a)/(a*c1-a1*c));
	}
	else if((b*c1 - b1*c) != 0)
	{
		A.setX(0);
		A.setY((c*d1-d*c1)/(b*c1 - b1*c));
		A.setZ((d*b1-d1*b)/(b*c1-b1*c));
	}
	else if((b*a1 - b1*a) != 0)
	{
		A.setX((d*b1-d1*b)/(b*a1-b1*a));
		A.setY((a*d1-d*a1)/(b*a1 - b1*a));
		A.setZ(0);
	}
	Point3D B;
	if((b*c1 - b1*c) != 0)
	{
		B.setX(0);
		B.setY((c*d1-d*c1)/(b*c1 - b1*c));
		B.setZ((d*b1-d1*b)/(b*c1-b1*c));
	}
	else if((b*a1 - b1*a) != 0)
	{
		B.setX((d*b1-d1*b)/(b*a1-b1*a));
		B.setY((a*d1-d*a1)/(b*a1 - b1*a));
		B.setZ(0);
	}
	else if((a*c1 - a1*c) != 0)
	{
		B.setX((c*d1-d*c1)/(a*c1 - a1*c));
		B.setY(0);
		B.setZ((d*a1-d1*a)/(a*c1-a1*c));
	}
		
	v = Vector(A,B);
}

void Line::print() const
{
	cout<<"x = "<<A.getX()<<" + a.("<<v.getV1()<<')'<<endl;
	cout<<"y = "<<A.getY()<<" + a.("<<v.getV2()<<')'<<endl;
	cout<<"z = "<<A.getZ()<<" + a.("<<v.getV3()<<')'<<endl;
}

bool Line::contains(Point3D M) const
{
	if(v.getV1() != 0 && v.getV2() != 0 && v.getV3() != 0)
		return ((M.getX() - A.getX())/v.getV1() == (M.getY() - A.getY())/v.getV2())&& 
			   ((M.getZ() - A.getZ())/v.getV3() == (M.getY() - A.getY())/v.getV2());
	if(v.getV1() == 0 && v.getV2() == 0)
		return (M.getX() == A.getX()) && (M.getY() == A.getY());
	if(v.getV1() == 0 && v.getV3() == 0)
		return (M.getX() == A.getX()) && (M.getZ() == A.getZ());
	if(v.getV3() == 0 && v.getV2() == 0)
		return (M.getZ() == A.getZ()) && (M.getY() == A.getY());
	if(v.getV1() == 0)
		return (M.getX() == A.getX()) && ((M.getZ() - A.getZ())/v.getV3() == (M.getY() - A.getY())/v.getV2());
	if(v.getV2() == 0)
		return (M.getY() == A.getY()) && ((M.getZ() - A.getZ())/v.getV3() == (M.getX() - A.getX())/v.getV1());
	if(v.getV3() == 0)
		return (M.getZ() == A.getZ()) && ((M.getX() - A.getX())/v.getV1() == (M.getY() - A.getY())/v.getV2());
	return false;
}

Line Line::getOrthoProjection(Plain const& alpha) const
{
	double x , y , z , m;
	m = (-alpha.getA() * getPoint().getX() - alpha.getB() * getPoint().getY() - alpha.getC() * getPoint().getZ() - alpha.getD())
		/(alpha.getA() * getParallel().getV1() + alpha.getB() * getParallel().getV2() + alpha.getC() * getParallel().getV3());
	x = getPoint().getX() + m * getParallel().getV1();
	y = getPoint().getY() + m * getParallel().getV2();
	z = getPoint().getZ() + m * getParallel().getV3();
	Point3D A(x , y , z);
	//return Line(alpha.getPoint() , X);
}

void Line::getPlains() const
{
	double x1 , y1 , z1 , v1 = getParallel().getV1() , v2 = getParallel().getV2() , v3 = getParallel().getV3();
	if(v1 == 0)
	{
		x1 = getPoint().getX() + 1;
		y1 = getPoint().getY();
		z1 = getPoint().getZ();
		Point3D P(x1 , y1 , z1);
		double x , y , z , m;
		m = (v2*(y1 - getPoint().getY()) + v3*(z1 - getPoint().getZ()))/(v2*v2 + v3*v3);
		x = getPoint().getX();
		y = getPoint().getY() + m*v2;
		z = getPoint().getZ() + m*v3;
		Point3D H(x , y , x);
		Vector v(H , P);
		Vector u = v.Xmultiply(getParallel());
		Plain alpha(getParallel() , v , H) , beta(getParallel() , u , H);
		beta.commonPrint();
		alpha.commonPrint();
	}
	else if(v2 == 0)
	{
		x1 = getPoint().getX();
		y1 = getPoint().getY() + 1;
		z1 = getPoint().getZ();
		Point3D P(x1 , y1 , z1);
		double x , y , z , m;
		m = (v1*(x1 - getPoint().getX()) + v3*(z1 - getPoint().getZ()))/(v1*v1 + v3*v3);
		x = getPoint().getX() + m*v1;
		y = getPoint().getY();
		z = getPoint().getZ() + m*v3;
		Point3D H(x , y , x);
		Vector v(H , P);
		Vector u = v.Xmultiply(getParallel());
		Plain alpha(getParallel() , v , H) , beta(getParallel() , u , H);
		beta.commonPrint();
		alpha.commonPrint();
	}
	else if(v3 == 0)
	{
		x1 = getPoint().getX();
		y1 = getPoint().getY();
		z1 = getPoint().getZ() + 1;
		Point3D P(x1 , y1 , z1);
		double x , y , z , m;
		m = (v2*(y1 - getPoint().getY()) + v1*(x1 - getPoint().getX()))/(v1*v1 + v2*v2);
		x = getPoint().getX() + m*v1;
		y = getPoint().getY() + m*v2;
		z = getPoint().getZ();
		Point3D H(x , y , x);
		Vector v(H , P);
		Vector u = v.Xmultiply(getParallel());
		Plain alpha(getParallel() , v , H) , beta(getParallel() , u , H);
		beta.commonPrint();
		alpha.commonPrint();
	}
	else
	{
		x1 = getPoint().getX();
		y1 = getPoint().getY() + v2;
		z1 = getPoint().getZ() + v3;
		Point3D P(x1 , y1 , z1);
		double x , y , z , m;
		m = (v3*(z1 - getPoint().getZ()) + v2*(y1 - getPoint().getY()))/(v1*v1 + v2*v2 + v3*v3);
		x = getPoint().getX() + m*v1;
		y = getPoint().getY() + m*v2;
		z = getPoint().getZ() + m*v3;
		Point3D H(x , y , x);
		Vector v(H , P);
		Vector u = v.Xmultiply(getParallel());
		Plain alpha(getParallel() , v , H) , beta(getParallel() , u , H);
		beta.commonPrint();
		alpha.commonPrint();
	}
}

bool Line::isParallelTo(Plain const& alpha) const
{
	return getParallel().getV1() * alpha.getA() + getParallel().getV2() * alpha.getB() + getParallel().getV3() * alpha.getC() == 0;
}

bool Line::isCrossing(Plain const& alpha) const
{
	if(!isParallelTo(alpha))
		return getParallel().getV1() * alpha.getA() + getParallel().getV2() * alpha.getB() + getParallel().getV3() * alpha.getC() != -alpha.getD();
	return false;
}

bool Line::belongsTo(Plain const& alpha) const
{
	Point3D B(A.getX() + v.getV1() , A.getY() + v.getV2() , A.getZ() + v.getV3());
	if(A.belongsTo(alpha) && B.belongsTo(alpha))
		return true;
	return false;
}

bool Line::isParallelTo(Line const& l) const
{
	Vector v = getParallel().Xmultiply(l.getParallel());
	if(v.getV1() == 0 && v.getV2() == 0 && v.getV3() == 0)
		return true;
	return false;
}

bool Line::hasCommonPoint(Line const& l) const
{
	double m1 = ((getPoint().getY() - l.getPoint().getY()) * getParallel().getV1() + getParallel().getV2() * (l.getPoint().getX() - getPoint().getX()))
		/ (l.getParallel().getV2() * getParallel().getV1() - l.getParallel().getV1() * getParallel().getV2());
	double m2 = (l.getPoint().getX() + m1 * l.getParallel().getV1() - getPoint().getX()) / getParallel().getV1();
	return getPoint().getZ() + m2 * getParallel().getV3() == l.getPoint().getZ() + m1 * l.getParallel().getV3(); 
}

bool Line::isCrossedWith(Line const& l) const
{
	if(!isParallelTo(l) && !hasCommonPoint(l))
		return true;
	return false;
}