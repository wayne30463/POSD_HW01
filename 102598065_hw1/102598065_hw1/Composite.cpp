#include "Composite.h"
#include "Component.h"
#include <sstream>
#include <iostream>
#include "define.h"
using namespace std;

Composite::Composite()
{
	_id = NULL_ID;
	_description = "empty";
}

Composite::Composite(Component* parent, int id, string description)
{
	_parent = parent;
	_id = id;
	_description = description;
}

Composite::~Composite()
{
	for (list<Component*>::iterator it = _nodelist.begin(); it != _nodelist.end(); it++)
	{
		delete (*it);
	}
}

int Composite::getId()
{
	//��Id
	return _id;
}

void Composite::setId(int id)
{
	//�]Id
	_id = id;
}

string Composite::getDescription()
{
	//��Description
	return _description;
}

void Composite::setDescription(string description)
{
	//�]Description
	_description = description;
}

list<Component*>* Composite::getNodeList()
{
	//��NodeList
	return &_nodelist;
}

Component* Composite::getParent()
{
	//��Parent Node ��}
	return _parent;
}

void Composite::setParent(Component* new_parent)
{
	//�]Parent Node ��}
	_parent = new_parent;
}

int Composite::addParent(Component* new_parent)
{
	//�s�WParent
	_parent->replaceChild(this, new_parent);
	new_parent->setParent(_parent);
	this->setParent(new_parent);
	new_parent->addChild(this);
	return RETURN_SUCCESS;
}

int Composite::addSibling(Component* new_sibling)
{
	//�s�WSibling
	new_sibling->setParent(_parent);
	_parent->addChild(new_sibling);
	return RETURN_SUCCESS;
}

int Composite::addChild(Component* new_child)
{
	//�s�WChild
	new_child->setParent(this);
	_nodelist.push_back(new_child);
	return RETURN_SUCCESS;
}

void Composite::removeChild(Component* del_child)
{
	//����Child �q list �̬屼
	for (list<Component*>::iterator it = _nodelist.begin(); it != _nodelist.end(); it++)
	{
		if ((*it)->getId() == del_child->getId())
		{
			_nodelist.erase(it);
			break;
		}
	}
}

void Composite::replaceChild(Component* old_child, Component* ins_child)
{
	//���N old_Child �b list ����m
	for (list<Component*>::iterator it = _nodelist.begin(); it != _nodelist.end(); it++)
	{
		if ((*it)->getId() == old_child->getId())
		{
			it = _nodelist.erase(it);
			_nodelist.insert(it, ins_child);
			break;
		}
	}
}

string Composite::getType()
{
	//���o Type
	return "Composite";
}
string Composite::getMap(string front_Str)
{
	//�H�r��^�� tree
	stringstream mapStr;
	bool add_line = false;
	if (_parent != nullptr)
	{
		if ((*_parent->getNodeList()).back()->getId() != _id)
		{
			add_line = true;
		}
	}
	mapStr << front_Str << "�ϡ�" << _description << "(" << this->getType() << ",ID:" << _id << ")" << endl;
	if (add_line)
		front_Str += "�U�@";
	else
		front_Str += "�@�@";
	for (list<Component*>::iterator it = _nodelist.begin(); it != _nodelist.end(); it++)
	{
		mapStr << (*it)->getMap(front_Str);
	}
	return mapStr.str();
}

Component* Composite::findNodeById(int key_id)
{
	//��id�j�M�L�ΥL��l�O���O�n�䪺
	Component* found_Node = new Composite();
	if (this->getId() == key_id)
		found_Node =  this;
	else
	{
		for (list<Component*>::iterator it = _nodelist.begin(); it != _nodelist.end(); it++)
		{
			int id = (*it)->getId();
			found_Node = (*it)->findNodeById(key_id);
			if (found_Node->getId() == key_id)
				break;
		}
	}
	return found_Node;
}
