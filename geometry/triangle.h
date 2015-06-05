#ifndef TRIANGLE_3D_H
#define TRIANGLE_3D_H

#include "3Dpoint.h"
#include "plain.h"
#include "line.h"

class Triangle
{
private:
	Point3D A , B , C;

public:
	Triangle(Point3D, Point3D, Point3D);
	Plain getPlain() const;
	// селектори за страните
	Line getAB() const;
	Line getBC() const;
	Line getCA() const;
	// селектори за медианите и медицентъра
	Line getAM() const;
	Line getBM() const;
	Line getCM() const;
	Point3D getCentroid() const;
	// селектори за височините и ортоцентъра
	Line getAH() const;
	Line getBH() const;
	Line getCH() const;
	Point3D getOrthocentre() const;
	// селектори за симетралите и центъра на описаната окръжност
	Line getSAB() const;
	Line getSBC() const;
	Line getSCA() const;
	Point3D getDescribedCentre() const;
	// селектори за ъглополовящите и центъра на вписаната окръжност
	Line getAL() const;
	Line getBL() const;
	Line getCL() const;
	Point3D getInscribedCentre() const;
};

#endif