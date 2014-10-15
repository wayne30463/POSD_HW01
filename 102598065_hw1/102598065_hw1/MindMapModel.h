#pragma once
#include "Component.h"
#include "Composite.h"
#include "Root.h"
#include "Node.h"

class MindMapModel
{
public:
	MindMapModel();
	~MindMapModel();
	string getName();
	void createMindMap(string);
	int insertNode(int, string, string);
	void saveMindMap();
	string drawMap();
	bool searchNodeById(int);
	int getNodeCount();
	bool check_NodeIsRoot(int);
private:
	int _node_id = 0;
	int _node_count = 0;
	string _name;
	Component* _MindMapTree;
	Component* createNode(string);
};

