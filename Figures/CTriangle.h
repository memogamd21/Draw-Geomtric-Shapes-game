#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	GfxInfo TriGfxInfo;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual Point calculateMidPoint() const;
	virtual bool isInside(Point P) const;
	double area(Point P1, Point P2, Point P3) const;
	virtual void updatecorners(Point P);
};

#endif