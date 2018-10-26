#include "MOVE.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MOVE::MOVE(ApplicationManager * pApp):Action(pApp)
{
}

void MOVE::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose the Figure you want");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Choose where you want to move the figure to");
	
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->ClearStatusBar();

}

void MOVE::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point newCenter;
	for (int X = 0; X < pManager->getFigCount(); X++) {
		if (pManager->getFigList(X)->isInside(P1) == true) {
			pManager->getFigList(X)->SetSelected(true);
			pManager->getFigList(X)->ChngFillClr(GRAY);		
			int distx = abs((double)(P2.x - P1.x));
			int disty = abs((double)(P2.y - P1.y));
			newCenter.x = pManager->getFigList(X)->calculateMidPoint().x + distx;
			newCenter.y = pManager->getFigList(X)->calculateMidPoint().y + disty;
			pManager->getFigList(X)->setMidpoint(newCenter.x,newCenter.y);
			pManager->getFigList(X)->updatecorners(newCenter);
		}
		}



}