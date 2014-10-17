#pragma once
#include "Command.h"
#include "MindMapModel.h"
#include <list>
using namespace std;

class DeleteComponentCommand : public Command
{
public:
	DeleteComponentCommand(MindMapModel*, int);
	~DeleteComponentCommand();
	void execute();
	void unexecute();
private:
	MindMapModel* _mindmap;
	Component* _node;
	list<Component*> _parentnodelist;
};

