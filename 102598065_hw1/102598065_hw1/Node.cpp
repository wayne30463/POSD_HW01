#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(Component* parent, int id, string description)
{
	this->setDescription(description);
	this->setParent(parent);
	this->setId(id);
}

Node::~Node()
{
}

string Node::getType()
{
	//���o Type
	return "Node";
}

int Node::addParent(Component* new_parent)
{
	//�s�WParent
	_parent->replaceChild(this, new_parent);
	new_parent->setParent(_parent);
	this->setParent(new_parent);
	new_parent->addChild(this);
	return RETURN_SUCCESS;
}

int Node::addSibling(Component* new_sibling)
{
	//�s�WSibling
	new_sibling->setParent(_parent);
	_parent->addChild(new_sibling);
	return RETURN_SUCCESS;
}