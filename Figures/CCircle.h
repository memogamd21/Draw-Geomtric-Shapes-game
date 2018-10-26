#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
	GfxInfo CircGfxInfo;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(Point P) const;
	virtual Point calculateMidPoint() const;
	virtual void updatecorners(Point P) ;
};

#endif