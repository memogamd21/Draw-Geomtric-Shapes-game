#include "ChangeCurrentColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeCurrentColor::ChangeCurrentColor(ApplicationManager *pApp,int sel):Action(pApp) {
	selector = sel;
}
void ChangeCurrentColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	//Showing a message depending on the color chosen to be changed
	switch (selector)
	{
	case 1:
		pOut->PrintMessage("Choose the new Drawing Color from the palette"); break;
	case 2:
		pOut->PrintMessage("Choose the new Filling Color from the palette"); break;
	case 3:
		pOut->PrintMessage("Choose the new BackGround Color from the palette"); break;
	}

	pOut->DrawClrPlt();
	newColor = pIn->getColor();
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();
}

//Execute the action
void ChangeCurrentColor::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Changing the current colors with the color read from the user
	switch (selector)
	{
	case 1:
		UI.DrawColor = newColor; break;
	case 2:
		UI.FillColor = newColor; break;
	case 3:
		UI.BkGrndColor = newColor; break;
	}
}

