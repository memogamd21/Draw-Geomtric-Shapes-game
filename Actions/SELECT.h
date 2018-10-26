
#ifndef SELECT_H
#define SELECT_H

#include "Action.h"

class SELECT : public Action
{

private:
	Point P1;
public:
	SELECT(ApplicationManager* pApp);
	
	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
	
};
#endif
