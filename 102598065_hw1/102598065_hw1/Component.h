#pragma once
#include <string>
#include <list>
using namespace std;

class Component
{
public:
	Component();
	virtual ~Component() = 0;
	enum ComponentType {
		Root = 0, Node = 1
	};
	virtual int getId() = 0;
	virtual void setId(int) = 0;
	virtual string getMap(string) = 0;
	virtual string getDescription() = 0;
	virtual void setDescription(string) = 0;
	virtual list<Component*>* getNodeList() = 0;
	virtual int addChild(Component*) = 0;
	virtual void removeChild(Component*) = 0;
	virtual void replaceChild(Component*, Component*) = 0;
	virtual Component* getParent() = 0;
	virtual void setParent(Component*) = 0;
	virtual int addParent(Component*) = 0;
	virtual int addSibling(Component*) = 0;
	virtual string getType() = 0;
	virtual Component* findNodeById(int) = 0;
};

