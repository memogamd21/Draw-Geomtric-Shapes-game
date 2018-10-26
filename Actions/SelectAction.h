
#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"

class SelectAction : public Action
{

private:
	Point P1;
public:
	SelectAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};
#endif
