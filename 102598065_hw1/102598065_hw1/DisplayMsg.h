#pragma once
#include <string>
using namespace std;

class DisplayMsg
{
public:
	DisplayMsg();
	~DisplayMsg();
	static void draw();
	static void enterNodeIdMsg();
	static void enterEdtNodeIdMsg();
	static void enterEdtParIdMsg();
	static void enterNodeNameMsg();
	static void enterTopicMsg();
	static void enterIfWantSave();
	static void saveSuccessMsg();
	static void displayMainMenu();
	static void displayEditMenu();
	static void displayInsertMenu();
	static void displayMindMap(string, string);
	static void displayLine();
	static void WrongInsCom();
	static void WrongEdtCom();
	static void WrongId(int);
	static void WrongId();
	static void WrongRootCannotAddSelect(string);
	static void WrongRootCannotEdtSelect(string);
	static void WrongRootCannotAddPar();
	static void WrongRootCannotAddSib();
	static void WrongRootCannotChangePar();
	static void WrongRootCannotDel();
	static void WrongCannotInputStr();
	static void WrongCannotSeletcItself();
};

