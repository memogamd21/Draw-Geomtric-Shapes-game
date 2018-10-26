#include "DeleteAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"



DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Bye");
}


void DeleteAction::Execute()
{
	
	for (int i = 0; i < pApp->getFigCount(); i++)
	{
		if (pApp->getFigList(i)->IsSelected() == true) {
			pApp->setFigList(i);
			pApp->UpdateInterface();
		}
	
	}
}

