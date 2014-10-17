#include "DeleteComponentCommand.h"


DeleteComponentCommand::DeleteComponentCommand(MindMapModel* mindmap, int id)
{
	_node = mindmap->getNodeById(id);
	_parentnodelist = _node->getParent()->getNodeList();
	_mindmap = mindmap;
}

DeleteComponentCommand::~DeleteComponentCommand()
{
}

void DeleteComponentCommand::execute()
{
	_mindmap->deleteNodeById(_node->getId());
}

void DeleteComponentCommand::unexecute()
{
	_mindmap->restoreNode(_node, _parentnodelist);
}

