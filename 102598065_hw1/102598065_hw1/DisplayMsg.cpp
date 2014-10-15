#include "DisplayMsg.h"
#include <iostream>
#include "define.h"
using namespace std;

DisplayMsg::DisplayMsg()
{
}

DisplayMsg::~DisplayMsg()
{
}

void DisplayMsg::displayMainMenu()
{
	//�D���
	cout << "Please enter your choice:" << endl;
	cout << "1. Create a new mind map" << endl;
	cout << "2. Insert a new node" << endl;
	cout << "3. Display mind map" << endl;
	cout << "4. Save mind map" << endl;
	cout << "5. Exit" << endl;
	cout << ">";
}

void DisplayMsg::displayInsertMenu()
{
	//���J���
	cout << "a.Insert a parent node" << endl;
	cout << "b.Insert a child node" << endl;
	cout << "c.Insert a sibling node" << endl;
	cout << ">";
}

void DisplayMsg::enterNodeIdMsg()
{
	//���ܰT��-��JNodeId
	cout << "Enter the node ID :" << endl;
	cout << ">";
}

void DisplayMsg::enterNodeNameMsg()
{
	//���ܰT��-��JNodeName
	cout << "Enter the node name:" << endl;
	cout << ">";
}

void DisplayMsg::enterTopicMsg()
{
	//���ܰT��-��JTopic
	cout << "Please enter the topic:" << endl;
	cout << ">";
}

void DisplayMsg::displayLine()
{
	//�e�u
	cout << "______________________________________________" << endl;
}

void DisplayMsg::WrongInsCom()
{
	//���~�T��-���O���~
	cout << "Wrong insert command!!" << endl;
}

void DisplayMsg::WrongId(int node_id)
{
	//���~�T��-Id���~
	cout << "Cannot find node ID :" << node_id << endl;
}

void DisplayMsg::displayMindMap(string name, string map)
{
	//�emap
	cout << "The mind map " << name.c_str() << " is displayed as follows:" << endl;
	cout << map.c_str() << endl;
}

void DisplayMsg::saveSuccessMsg()
{
	//���ܰT��-�x�s���\
	cout << "Save MindMap Success" << endl;
}

void DisplayMsg::WrongRootCannotAddPar()
{
	//���~�T��-Root�S���Ѫ��Ѷ�
	cout << "Root can't insert parent node" << endl;
}

void DisplayMsg::WrongRootCannotAddSib()
{
	//���~�T��-Root�S���S��
	cout << "Root can't insert sibling node" << endl;
}

void DisplayMsg::WrongCannotInputStr()
{
	//���~�T��-Node Id ���O�r��
	cout << "Can't input string for node id" << endl;
}

void DisplayMsg::enterIfWantSave()
{
	//���ܰT��-�O�_�x�s
	cout << "Do you want SAVE before EXIT ? (y/n)" << endl;
	cout << ">";
}

void DisplayMsg::WrongRootCannotAddSelect(string select)
{ 
	if (select == ADD_PARENT)
		WrongRootCannotAddPar();
	else
		WrongRootCannotAddSib();
}