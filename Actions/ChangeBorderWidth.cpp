#include "ChangeBorderWidth.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChangeBorderWidth::ChangeBorderWidth(ApplicationManager * pApp) :Action(pApp)
{}

void ChangeBorderWidth::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter an integer and press ENTER");
	penWidth = pIn->getBorderWidth(pOut);
	pOut->ClearStatusBar();
}

//Execute the action
void ChangeBorderWidth::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	UI.PenWidth = penWidth;
}
