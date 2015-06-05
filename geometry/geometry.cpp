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
	testLines();
	system("pause");
	return 0;
}



