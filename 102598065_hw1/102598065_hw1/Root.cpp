#include "Root.h"
#include <iostream>
using namespace std;

Root::Root(int id, string description)
{
	this->setDescription(description);
	this->setId(id);
}

Root::~Root()
{
}

string Root::getType()
{
	//���o Type
	return "Root";
}

int Root::addParent(Component* new_parent)
{
	//�s�WParent
	return RETURN_ERROR;
}

int Root::addSibling(Component* new_sibling)
{
	//�s�WSibling
	return RETURN_ERROR;
}