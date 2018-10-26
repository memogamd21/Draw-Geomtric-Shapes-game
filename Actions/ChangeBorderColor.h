#ifndef CHANGE_CURRENT_COLOR_H
#define CHANGE_CURRENT_COLOR_H

#include "Action.h"

//Add Circle Action class
class ChangeCurrentColor : public Action
{
private:
	Point p;
	color newColor;
	int selector; //Selects which color to change (1 for drawing, 2 for filling, and 3 for background)
	GfxInfo NewGfxInfo;
public:
	ChangeCurrentColor(ApplicationManager *pApp, int sel);

	//Reads Change parameters
	virtual void ReadActionParameters();

	//Applys Change to the ApplicationManager
	virtual void Execute();

};
#endif