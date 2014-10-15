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
	//取得 Type
	return "Root";
}

int Root::addParent(Component* new_parent)
{
	//新增Parent
	return RETURN_ERROR;
}

int Root::addSibling(Component* new_sibling)
{
	//新增Sibling
	return RETURN_ERROR;
}