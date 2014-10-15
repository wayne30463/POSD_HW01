#pragma once
#include "Composite.h"
#include "define.h"

class Root : public Composite
{
public:
	Root(int, string);
	~Root();
	int addParent(Component*);
	int addSibling(Component*);
	string getType();
};

