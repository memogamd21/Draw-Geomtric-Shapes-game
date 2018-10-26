#include "CCircle.h"

CCircle::CCircle(Point Poi1, Point Poi2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	P1 = Poi1;
	P2 = Poi2;
}


void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(P1, P2, FigGfxInfo, Selected);
}
bool CCircle::isInside(Point P) const
{
	if (pow((P1.x - P.x), 2) <= pow((P2.x - P.x), 2) && pow((P1.y - P.y), 2) <= pow((P2.y - P.y), 2))
	{
		return true;
	}
	else {
		return false;
	}
}

Point CCircle::calculateMidPoint() const
{
	Point P;
	double distx = (double)((P1.x - P2.x) / 2);
	double disty = (double)((P1.y - P2.y) / 2);
	P.x = P1.x - distx;
	P.y = P1.y - disty;
	return P;
}

void CCircle::updatecorners(Point P) 
{
	int distx = P.x - calculateMidPoint().x;
	int disty = P.y - calculateMidPoint().y;
	P1.x = P1.x + distx;
	P1.y = P1.y + disty;
	P2.x = P2.x + distx;
	P2.y = P2.y + disty;
}