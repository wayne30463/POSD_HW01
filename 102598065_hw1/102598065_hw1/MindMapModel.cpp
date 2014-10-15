#include "MindMapModel.h"
#include "define.h"
#include <fstream>
#include <iostream>
#include<sstream>
using namespace std;

MindMapModel::MindMapModel()
{
}

MindMapModel::~MindMapModel()
{
	if (_MindMapTree != nullptr)
	{
		delete _MindMapTree;
	}
}

string MindMapModel::getName()
{
	//���oMindMapModel name
	return _name;
}

int MindMapModel::getNodeCount()
{
	//���oNode �ƶq
	return _node_count;
}

void MindMapModel::createMindMap(string description)
{
	//���ؤ@�ӷs��MindMapTree
	if (_MindMapTree != nullptr)
	{
		delete _MindMapTree;
	}
	_node_id = 0;
	_MindMapTree = new Root(_node_id, description);
	_name = description;
	_node_count = 1;
}

Component* MindMapModel::createNode(string description)
{
	//�إߤ@�ӷs��Node
	Component* node = new Node(nullptr, _node_id + 1, description);
	return node;
}

int MindMapModel::insertNode(int ins_nodeid, string description, string option)
{
	//���J�@�ӷs��Node
	Component* ins_node = _MindMapTree->findNodeById(ins_nodeid);
	Component* new_node = this->createNode(description);
	_node_count++;
	_node_id++;
	if (!option.compare(ADD_CHILD))
	{
		return ins_node->addChild(new_node);
	}
	else if (!option.compare(ADD_PARENT))
	{
		return ins_node->addParent(new_node);
	}
	else if (!option.compare(ADD_SIBLING))
	{
		return ins_node->addSibling(new_node);
	}
	_node_count--;
	_node_id--;
	return INSERT_ERROR;
}

string MindMapModel::drawMap()
{
	//�eMindMapTree
	if (_node_count > 0)
		return _MindMapTree->getMap("");
	else
		return "empty";
}

void MindMapModel::saveMindMap()
{
	//�sMindMapTree
	ofstream fout("mindmap.txt");
	Component* draw_node;
	list<Component*> temp_list;
	for (int i = 0; i < _node_count; i++)
	{
		draw_node = _MindMapTree->findNodeById(i);
		temp_list = *(draw_node->getNodeList());
		fout << draw_node->getId() << " ";
		fout << "\"" << draw_node->getDescription().c_str() << "\" ";
		for (list<Component*>::iterator it = temp_list.begin(); it != temp_list.end(); it++)
		{
			fout << (*it)->getId() << " ";
		}
		fout << endl;
	}
	fout.close();
}

bool MindMapModel::searchNodeById(int id)
{
	//��Node
	if (_node_count == 0)
		return false;
	else if (_MindMapTree->findNodeById(id)->getId() == -1)
		return false;
	else
		return true;
}

bool MindMapModel::check_NodeIsRoot(int nodeid)
{
	//��Node�O���ORoot
	if (_MindMapTree->findNodeById(nodeid)->getType() == ROOT)
		return true;
	else
		return false;
}