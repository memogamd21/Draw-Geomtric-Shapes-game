#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::isInside(Point P) const
{
	if ((P.x >= Corner1.x && P.y >= Corner1.y && P.x < Corner2.x && P.y < Corner2.y) || (P.x >= Corner1.x && P.y < Corner1.y && P.x < Corner2.x && P.y >= Corner2.y) ||
		(P.x < Corner1.x && P.y < Corner1.y && P.x >= Corner2.x && P.y >= Corner2.y) || (P.x < Corner1.x && P.y >= Corner1.y && P.x >= Corner2.x && P.y < Corner2.y)) {
		return true;
	}
	else { return false; }
}

Point CRectangle::calculateMidPoint() const
{
	Point P;
	double distx = (double)((Corner1.x - Corner2.x) / 2);
	double disty = (double)((Corner1.y - Corner2.y) / 2);
	P.x = Corner1.x - distx;
	P.y = Corner1.y - disty;
	return P;
}

void CRectangle::updatecorners(Point P)
{
	int distx = P.x - calculateMidPoint().x;
	int disty = P.y - calculateMidPoint().y;
	Corner1.x = Corner1.x + distx;
	Corner1.y = Corner1.y + disty;
	Corner2.x = Corner2.x + distx;
	Corner2.y = Corner2.y + disty;
}