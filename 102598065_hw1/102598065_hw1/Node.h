#pragma once
#include "Composite.h"
#include "define.h"

class Node : public Composite
{
public:
	Node(Component*, int, string);
	~Node();
	int addParent(Component*);
	int addSibling(Component*);
	string getType();
};

