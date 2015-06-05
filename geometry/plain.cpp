#include "stdafx.h"
#include <iostream>
#include "line.h"

using namespace std;

Plain::Plain(double _A , double B , double C , double D)
{
	if(_A != 0)
	{
		v.setV1(-C/_A);
		v.setV2(0);
		v.setV3(1);
		u.setV1(-B);
		u.setV2(_A);
		u.setV3(0);
		A.setX(-D/_A);
		A.setY(0);
		A.setZ(0);
	}
	else if(B != 0)
	{
		v.setV1(B);
		v.setV2(0);
		v.setV3(0);
		u.setV1(1);
		u.setV2(-C/B);
		u.setV3(1);
		A.setX(1);
		A.setY(-D/B);
		A.setZ(0);

	}
	else 
	{
		v.setV1(0);
		v.setV2(1);
		v.setV3(0);
		u.setV1(C);
		u.setV2(1);
		u.setV3(0);
		A.setX(1);
		A.setY(1);
		A.setZ(-D/C);
	}
}

Plain::Plain(Point3D _A, Point3D B, Point3D C) : u(_A , B) , v(_A , C) , A(_A)
{}

Plain::Plain(Vector v1 , Vector v2 , Point3D B) : u(v1) , v(v2) , A(B)
{}

Plain::Plain(Line l , Point3D B) : A(B)
{
	double x = l.getParallel().getV1() , y = l.getParallel().getV2() , z = l.getParallel().getV3();
	if(x != 0)
	{
		v.setV1(-z/x);
		v.setV2(0);
		v.setV3(1);
		u.setV1(-y);
		u.setV2(x);
		u.setV3(0);
	}
	else if(y != 0)
	{
		v.setV1(y);
		v.setV2(0);
		v.setV3(0);
		u.setV1(1);
		u.setV2(-z/y);
		u.setV3(1);
	}
	else 
	{
		v.setV1(0);
		v.setV2(1);
		v.setV3(0);
		u.setV1(z);
		u.setV2(1);
		u.setV3(0);
	}
}

Plain::Plain(Plain alpha , Point3D M) : A(M) , u(alpha.getUParallel()) , v(alpha.getVParallel())
{}

void Plain::commonPrint() const
{
	cout<<'('<<getA()<<")x + ("<<getB()<<")y + ("<<getC()<<")z ";
	if(getD() != 0)
	{
		if(getD() < 0)
			cout<<"- "<<-getD();
		else
			cout<<"+ "<<getD();
	}
	cout<<" = 0"<<endl;

}

void Plain::parametricPrint() const
{
	cout<<"x = "<<A.getX()<<" + ("<<u.getV1()<<")a + ("<<v.getV1()<<")b"<<endl;
	cout<<"y = "<<A.getY()<<" + ("<<u.getV2()<<")a + ("<<v.getV2()<<")b"<<endl;
	cout<<"z = "<<A.getZ()<<" + ("<<u.getV3()<<")a + ("<<v.getV3()<<")b"<<endl;
}

void Plain::plainPosition(Plain const& beta) const
{
	double a , b ,c;
	a = -v.getV2()*u.getV3() + u.getV2()*v.getV3();
	b = -v.getV3()*u.getV1() + u.getV3()*v.getV1();
	c = -v.getV1()*u.getV2() + u.getV1()*v.getV2();
	double a1 , b1 ,c1;
	a1 = beta.getA();
	b1 = beta.getB();
	c1 = beta.getC();
	if(a != 0)
	{
		if(b != 0)
		{
			if(c != 0)
				if(a1/a == b1/b && a1/a == c1/c)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
			else
				if(a1/a == b1/b && c1 == 0)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
		}
		else
		{
			if(c != 0)
				if(b1 == 0 && a1/a == c1/c)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
			else
				if(b1 == 0 && c1 == 0)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
		}
	}
	else
	{
		if(b != 0)
		{
			if(c != 0)
				if(c1/c == b1/b && a1 == 0)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
			else
				if(a1 == 0 && c1 == 0)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
		}
		else
		{
			if(c != 0)
				if(b1 == 0 && a1 == 0)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
			else
				if(b1 == 0 && c1 == 0 && a1 == 0)
					cout<<"The plains are parallel!"<<endl;
				else
					cout<<"The plains are crossing each other!"<<endl;
		}
	}
}

double Plain::getA() const
{ return -getVParallel().getV2() * getUParallel().getV3() + getUParallel().getV2() * getVParallel().getV3(); }

double Plain::getB() const
{ return -getVParallel().getV3() * getUParallel().getV1() + getUParallel().getV3() * getVParallel().getV1(); }

double Plain::getC() const
{ return -getVParallel().getV1() * getUParallel().getV2() + getUParallel().getV1() * getVParallel().getV2(); }

double Plain::getD() const
{ return -getA() * getPoint().getX() - getB() * getPoint().getY() - getC() * getPoint().getZ(); }