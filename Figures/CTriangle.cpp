#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

double CTriangle::area(Point P1, Point P2, Point P3) const
{
	return abs(((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2.0);
}

bool CTriangle::isInside(Point P) const
{
	double A = area(Corner1, Corner2, Corner3);
	double A1 = area(P,Corner1, Corner2);
	double A2 = area(P,Corner2,Corner3);
	double A3 = area(P, Corner1, Corner3);
	return (A == (A1 + A2 + A3));
}

Point CTriangle::calculateMidPoint() const
{
	Point P;
	int X = (Corner1.x + Corner2.x + Corner3.x) / 3;
	int Y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	P.x = Corner1.x + X;
	P.y = Corner1.y + Y;
	return P;
}

void CTriangle::updatecorners(Point P)
{
	int distx = P.x - calculateMidPoint().x;
	int disty = P.y - calculateMidPoint().y;
	Corner1.x = Corner1.x + distx;
	Corner1.y = Corner1.y + disty;
	Corner2.x = Corner2.x + distx;
	Corner2.y = Corner2.y + disty;
	Corner3.x = Corner3.x + distx;
	Corner3.y = Corner3.y + disty;
}