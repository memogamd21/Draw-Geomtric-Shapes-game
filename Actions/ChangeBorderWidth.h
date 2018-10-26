#ifndef CHANGE_BORDER_WIDTH_H
#define CHANGE_BORDER_WIDTH_H

#include "Action.h"

//Add Circle Action class
class ChangeBorderWidth : public Action
{
private:
	int penWidth;
public:
	ChangeBorderWidth(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();

};

#endif