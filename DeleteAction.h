
#ifndef DELETE_ACTION_H
#define DELETE_ACTION



#include "Action.h"

class DeleteAction : public Action
{

public:
	DeleteAction(ApplicationManager * pApp);
	virtual void ReadActionParameters()
	virtual void Execute();
};

#endif // !1