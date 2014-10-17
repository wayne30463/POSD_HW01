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
	//主選單
	cout << "Please enter your choice:" << endl;
	cout << "1. Create a new mind map" << endl;
	cout << "2. Insert a new node" << endl;
	cout << "3. Edit a node" << endl;
	cout << "4. Display mind map" << endl;
	cout << "5. Save mind map" << endl;
	cout << "6. Load a mind map" << endl;
	cout << "7. Redo" << endl;
	cout << "8. Undo" << endl;
	cout << "9. Exit" << endl;
	cout << ">";
}

void DisplayMsg::displayEditMenu()
{
	//插入選單
	cout << "a. Edit the description of a node" << endl;
	cout << "b. Change the parent of a node" << endl;
	cout << "c. Delete a node" << endl;
	cout << ">";
}

void DisplayMsg::displayInsertMenu()
{
	//插入選單
	cout << "a.Insert a parent node" << endl;
	cout << "b.Insert a child node" << endl;
	cout << "c.Insert a sibling node" << endl;
	cout << ">";
}

void DisplayMsg::enterNodeIdMsg()
{
	//提示訊息-輸入NodeId
	cout << "Enter the node ID :" << endl;
	cout << ">";
}

void DisplayMsg::enterEdtNodeIdMsg()
{
	//提示訊息-輸入NodeId
	cout << "Enter the edit node ID :";
}

void DisplayMsg::enterEdtParIdMsg()
{
	//提示訊息-輸入NodeId
	cout << "Enter the parent ID:";
}

void DisplayMsg::enterNodeNameMsg()
{
	//提示訊息-輸入NodeName
	cout << "Enter the description:" << endl;
	cout << ">";
}

void DisplayMsg::enterTopicMsg()
{
	//提示訊息-輸入Topic
	cout << "Please enter the topic:" << endl;
	cout << ">";
}

void DisplayMsg::displayLine()
{
	//畫線
	cout << "______________________________________________" << endl;
}

void DisplayMsg::WrongEdtCom()
{
	//錯誤訊息-指令錯誤
	cout << "The command is not found!!" << endl;
}

void DisplayMsg::WrongInsCom()
{
	//錯誤訊息-指令錯誤
	cout << "Wrong insert command!!" << endl;
}

void DisplayMsg::WrongId(int node_id)
{
	//錯誤訊息-Id錯誤
	cout << "Cannot find node ID :" << node_id << endl;
}

void DisplayMsg::WrongId()
{
	//錯誤訊息-Id錯誤
	cout << "The node is not exist!!" << endl;
}

void DisplayMsg::displayMindMap(string name, string map)
{
	//畫map
	cout << "The mind map " << name.c_str() << " is displayed as follows:" << endl;
	cout << map.c_str() << endl;
}

void DisplayMsg::saveSuccessMsg()
{
	//提示訊息-儲存成功
	cout << "Save MindMap Success" << endl;
}

void DisplayMsg::WrongRootCannotAddPar()
{
	//錯誤訊息-Root沒有老爸老媽
	cout << "Root can't insert parent node" << endl;
}

void DisplayMsg::WrongRootCannotAddSib()
{
	//錯誤訊息-Root沒有兄弟
	cout << "Root can't insert sibling node" << endl;
}

void DisplayMsg::WrongRootCannotChangePar()
{
	//錯誤訊息-Root不能當別人家小孩
	cout << "Root can't be changed the parent" << endl;
}

void DisplayMsg::WrongRootCannotDel()
{
	//錯誤訊息-Root死不了啦
	cout << "You can’t delete the root." << endl;
}

void DisplayMsg::WrongCannotInputStr()
{
	//錯誤訊息-Node Id 不是字串
	cout << "Can't input string for node id" << endl;
}

void DisplayMsg::enterIfWantSave()
{
	//提示訊息-是否儲存
	cout << "Do you want SAVE before EXIT ? (y/n)" << endl;
	cout << ">";
}

void DisplayMsg::WrongCannotSeletcItself()
{
	cout << "You can’t select itself!!" << endl;
}

void DisplayMsg::WrongRootCannotAddSelect(string select)
{ 
	if (select == ADD_PARENT)
		WrongRootCannotAddPar();
	else
		WrongRootCannotAddSib();
}

void DisplayMsg::WrongRootCannotEdtSelect(string select)
{
	if (select == DELETE_NODE)
		WrongRootCannotDel();
	else
		WrongRootCannotChangePar();
}