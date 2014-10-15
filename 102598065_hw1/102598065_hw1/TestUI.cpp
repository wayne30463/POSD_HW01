#include <iostream>
#include "MindMapModel.h"
using namespace std;
using namespace std;
#define MAIN_CREATE "1"
#define MAIN_INSERT "2"
#define MAIN_DISPLAY "3"
#define MAIN_SAVE "4"
#define MAIN_EXIT "5"
#define STATE_MAIN 1
#define STATE_CREATE 2
#define STATE_INSERT 3
#define STATE_DISPLAY 4
#define STATE_SAVE 5
#define STATE_EXIT 6

int TextUI()
{
	MindMapModel* MindMap = new MindMapModel();
	int state = STATE_MAIN;
	bool isRunning = true;
	string input, command, node_name;
	int node_id = -1;
	while (isRunning)
	{
		switch (state)
		{
		default:
			break;
		case STATE_MAIN:
			displayMainMenu();
			cin >> input;
			cout << endl;
			if (input.compare(MAIN_CREATE) == 0)
			{
				state = STATE_CREATE;
			}
			else if (input.compare(MAIN_INSERT) == 0)
			{
				state = STATE_INSERT;
			}
			else if (input.compare(MAIN_DISPLAY) == 0)
			{
				state = STATE_DISPLAY;
			}
			else if (input.compare(MAIN_SAVE) == 0)
			{
				state = STATE_SAVE;
			}
			else if (input.compare(MAIN_EXIT) == 0)
			{
				state = STATE_EXIT;
			}
			break;
		case STATE_CREATE:
			cout << "Please enter the topic:" << endl;
			cout << ">";
			cin >> input;
			cout << endl;
			MindMap->createMindMap("123312");
			displayMindMap(MindMap);
			cout << MindMap->_MindMapTree->getDescription() << endl;
			cout << "______________________________________________" << endl;
			state = STATE_MAIN;
			break;
		case STATE_INSERT:
			displayMindMap(MindMap);
			cout << "Enter the node ID :" << endl;
			cout << ">";
			cin >> node_id;
			cout << endl;
			if (MindMap->searchNodeById(node_id))
			{
				displayInsertMenu();
				cin >> command;
				cout << "Enter the node name:" << endl;
				cout << ">";
				cin >> node_name;
				cout << endl;
				if (MindMap->insertNode(node_id, node_name, command) == 0)
				{
					displayMindMap(MindMap);
					cout << "______________________________________________" << endl;
					state = STATE_MAIN;
				}
				else
					cout << "Wrong insert command" << endl;
			}
			else
				cout << "Cannot find node ID :" << node_id << endl;
			break;
		case STATE_DISPLAY:
			displayMindMap(MindMap);
			cout << endl;
			state = STATE_MAIN;
			break;
		case STATE_SAVE:
			MindMap->saveMindMap();
			cout << endl;
			state = STATE_MAIN;
			break;
		case STATE_EXIT:
			isRunning = false;
			break;
		}
	}
	return 0;
}

void displayMainMenu()
{
	cout << "Please enter your choice:" << endl;
	cout << "1. Create a new mind map" << endl;
	cout << "2. Insert a new node" << endl;
	cout << "3. Display mind map" << endl;
	cout << "4. Save mind map" << endl;
	cout << "5. Exit" << endl;
	cout << ">";
}

void displayInsertMenu()
{
	cout << "a.Insert a parent node" << endl;
	cout << "b.Insert a child node" << endl;
	cout << "c.Insert a sibling node" << endl;
	cout << ">";
}

void displaSelectNodeMsg()
{

}

void displayMindMap(MindMapModel* MindMap)
{
	cout << "The mind map " << MindMap->getName() << " is displayed as follows:" << endl;
	cout << MindMap->drawMap();
}