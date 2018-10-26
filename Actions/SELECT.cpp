#include "SELECT.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



SELECT::SELECT(ApplicationManager * pApp):Action(pApp)
{
}


void SELECT::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose the Figure you want");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();	

}

void SELECT::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	for (int X = 0; X < pManager->getFigCount(); X++) {
		if (pManager->getFigList(X)->isInside(P1) == true) {
			color x = pManager->getFigList(X)->getFillColor();
			if (pManager->getFigList(X)->IsSelected() == false) {
				pManager->getFigList(X)->SetSelected(true);
				pManager->getFigList(X)->ChngFillClr(GRAY);
			}
				// if the figure is selected do the fllowing
			else if (pManager->getFigList(X)->IsSelected() == true) {
				pManager->getFigList(X)->SetSelected(false);
				pManager->getFigList(X)->UnchngFillClr(x);
				pOut->PrintMessage("Now You've unselected the figure");
			}
		}
		else {
			pManager->getFigList(X)->SetSelected(false);
		}
	}
	ReadActionParameters();


}
