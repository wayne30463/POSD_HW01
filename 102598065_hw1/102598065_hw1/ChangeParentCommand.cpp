#include "ChangeParentCommand.h"


ChangeParentCommand::ChangeParentCommand(MindMapModel* mindmap, int id, int parent)
{
	_mindmap = mindmap;
	_id = id;
	_newparentid = parent;
	_oldparentid = mindmap->getNodeById(id)->getParent()->getId();
	_nodelist = mindmap->getNodeById(id)->getNodeList();
	_oldparentnodelist = mindmap->getNodeById(id)->getParent()->getNodeList();
}

ChangeParentCommand::~ChangeParentCommand()
{
}

void ChangeParentCommand::execute()
{
	_mindmap->changeParent(_id, _newparentid);
}

void ChangeParentCommand::unexecute()
{
	_mindmap->changeParentBack(_id, _oldparentid, _nodelist, _oldparentnodelist);
}