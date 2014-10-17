#include "EditComponentCommand.h"


EditComponentCommand::EditComponentCommand(MindMapModel* mindmap, int id, string description)
{
	_mindmap = mindmap;
	_id = id;
	_newdescription = description;
	_olddescription = mindmap->getNodeDescriptionById(id);
}

EditComponentCommand::~EditComponentCommand()
{
}

void EditComponentCommand::execute()
{
	_mindmap->editNodeById(_id, _newdescription);
}

void EditComponentCommand::unexecute()
{
	_mindmap->editNodeById(_id, _olddescription);
}
