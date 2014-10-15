#pragma once
#include "Component.h"

class Composite : public Component
{
public:
	Composite();
	Composite(Component*, int, string);
	~Composite();
	int getId();
	void setId(int);
	string getDescription();
	void setDescription(string);
	list<Component*>* getNodeList();
	string getNodeListStr();
	string getMap(string);
	int addChild(Component*);
	void removeChild(Component*);
	void replaceChild(Component*, Component*);
	Component* getParent();
	void setParent(Component*);
	virtual int addParent(Component*);
	virtual int addSibling(Component*);
	string getType();
	Component* findNodeById(int);
protected:
	int _id;
	string _description;
	Component* _parent;
	list<Component*> _nodelist;
};

