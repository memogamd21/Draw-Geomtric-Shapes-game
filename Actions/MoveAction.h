#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H

#include "Action.h"

class MoveAction : public Action
{
public:

	MoveAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
private:
	Point P1, P2;
};

#endif // !MOVE_H