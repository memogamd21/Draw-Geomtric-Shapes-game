#ifndef MOVE_H
#define MOVE_H

#include "Action.h"

class MOVE : public Action
{
public:
	
	MOVE(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
private:
	Point P1,P2;
};

#endif // !MOVE_H