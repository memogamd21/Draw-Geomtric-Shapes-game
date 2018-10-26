#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = 0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::UnchngFillClr(color Uclr) {
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Uclr;
}

void CFigure::setMidpoint(int x, int y)
{
	midPoint.x = x;
	midPoint.y = y;
}

void CFigure::setID(int id) {
	 ID = id;
}
