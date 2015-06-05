#ifndef POINT_3D_H
#define POINT_3D_H

class Line;
class Plain;
class Vector;

class Point3D
{
private:
	double x , y , z;
public:
	Point3D(double = 0 , double = 0 , double = 0);
	Point3D(Line , Line);
	Point3D(Line , Plain);

	double getX() const {return x;}
	double getY() const {return y;}
	double getZ() const {return z;}
	void setX(double _x){x = _x;}
	void setY(double _y){y = _y;}
	void setZ(double _z){z = _z;}
	void print();
	bool belongsTo(Line const&) const; 
	bool belongsTo(Plain const&) const;
	void translate(Vector const&);
	double getDistance(Plain const&);
	double getDistance(Line const&);
};


#endif