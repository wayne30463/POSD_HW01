#pragma once
#include "MindMapModel.h"
#include "Command.h"
#include "Component.h"
#include "string"
using namespace std;

class EditComponentCommand : public Command
{
public:
	EditComponentCommand(MindMapModel*, int, string);
	~EditComponentCommand();
	void execute();
	void unexecute();
private:
	MindMapModel* _mindmap;
	int _id;
	string _newdescription;
	string _olddescription;
};

