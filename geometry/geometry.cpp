// geometry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "3Dpoint.h"
#include "vector.h"
#include "line.h"
#include "plain.h"
#include "triangle.h"
using namespace std;

void testLines()
{
	Point3D A(1 , 2 , 3) , B(4 , 5 , 9) , C(3 , 0 , 2);
	Line l1(A , B) , l2(C , Vector(A , B)) , l3(Plain(2 , -1 , 3 , -2) , B) , l4( Plain(2 , -3 , 1 , 3) , Plain(-4 , -1 , 5 , 1));
	l1.print(); cout<<endl;
	l2.print(); cout<<endl;
	l3.print(); cout<<endl;
	l4.print(); cout<<endl;

	l4.getPlains();

	cout<<l1.contains(A)<<' '<<l1.contains(C)<<' '<<l2.contains(B)<<endl;
	cout<<l1.isCrossedWith(l1)<<endl;
}

int main()
{
	/*Point3D A(0 , 3 , 2) , B(-2 , 4 , -2) , C(1 ,2 , -1) , D(3 ,3 ,3);
	Vector v1(1 , 1 , 1) , v2(3 , 3 , 3);
	Plain beta(0 , 0 , -1 , 4);
	Line a(A , B) , b(C , D);
	Plain alpha(2 , 3 , 5 , 4);
	Point3D X(a , beta);
	v1.Xmultiply(v2).print();
	v1 += v2;
	Triangle tr(A , B , C);
	Line aOrtho = a.getOrthoProjection(alpha);
	alpha.commonPrint();
	aOrtho.print();
	LinePlain(aOrtho , alpha);*/

	/*Vector v(2 , 3 , 2);
	Point3D A(1 , 3 , 2);
	Line l(A , v);
	l.print();
	l.getPlains();
	Line a( Plain(-30 , 6 , 21 , -9) , Plain(3 , -6 , 6 , 9));
	a.print();*/
	
	//testLines();

	Line a(Point3D(0 , -3 , 2) , Vector(13 , 5 , -13)) , b(Point3D(-2 , 3 , 4) , Vector(1 , 1 , -1));
	a.print(); cout<<endl;
	b.print(); cout<<endl;
	cout<<a.hasCommonPoint(b)<<endl;
	system("pause");
	return 0;
}



