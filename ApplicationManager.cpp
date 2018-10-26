#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ChangeBorderWidth.h"
#include "Actions\ChangeCurrentColor.h"
#include "Actions\SelectAction.h"
#include "Actions\MoveAction.h"





//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this);
		break;
	case DRAW_TRI:
		pAct = new AddTriAction(this);
		break;
	case CHNG_DRAW_CLR:
		pAct = new ChangeCurrentColor(this, 1);
		break;
	case CHNG_FILL_CLR:
		pAct = new ChangeCurrentColor(this, 2);
		break;
	case CHNG_BK_CLR:
		pAct = new ChangeCurrentColor(this, 3);
		break;
	case SELECT:
		pAct = new SelectAction(this);
		break;
	/*case UNSELECT:
		pAct = new SelectAction(this, 0);
		break*/
	case CHANGEborCOL:
		pOut->PrintMessage("You are changing the border color");
		break;
	case CHANGEborwid:
		pAct = new ChangeBorderWidth(this);
		break;
	/*case CHANGEFILCOL:
		pOut->PrintMessage("You are changing the filling color");
		break;*/ //implicit in the "selecting" and "changeCurrentColor" actions
	case DEL:
		pOut->PrintMessage("You are deleting the figure");
		break;
	case MOVE:
		pAct = new MoveAction(this);
			break;
	case SAVE:
		pOut->PrintMessage("You are saving the file");
		break;
	case LOAD:
		pOut->PrintMessage("You are now Loading the figure");
		break;
	case EXIT:
		pOut->PrintMessage("You are now going to exit");
		break;
		
		case STATUS: //a click on the status bar or empty spot ==> no action
		case EMPTY: 
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
	
	pFig->setID(FigCount);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	Point P1;
	P1.x = x;
	P1.y = y;
	for (int X = 0; X < FigCount; X++) {
		if (FigList[X]->isInside(P1) == true) {
			return FigList[X];
		}
		else {
			return NULL;
		}

	}
	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

void ApplicationManager::setFigList(int i)
{
	FigList[i] = NULL;
}

CFigure* ApplicationManager::getSelected()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true) {
			return FigList[i];
		}
	}
}