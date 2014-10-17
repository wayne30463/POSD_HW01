#pragma once
#include "Command.h"
#include "MindMapModel.h"
#include <list>

class ChangeParentCommand : public Command
{
public:
	ChangeParentCommand(MindMapModel*, int, int);
	~ChangeParentCommand();
	void execute();
	void unexecute();
private:
	int _oldparentid;
	int _newparentid;
	int _id;
	list<Component*> _nodelist;
	list<Component*> _oldparentnodelist;
	MindMapModel* _mindmap;
};

