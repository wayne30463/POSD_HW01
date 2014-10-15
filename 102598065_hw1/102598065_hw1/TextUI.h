#pragma once
#include "MindMapModel.h"
#include <sstream>

class TextUI
{
public:
	TextUI(MindMapModel*);
	~TextUI();
	void run();
	void show_cre();
	void show_main();
	void show_ins();
	void show_ins_ck_id();
	void show_ins_ck_cmd();
	void show_ins_in_nn();
	void show_dis();
	void show_sav();
	void show_exit();
private:
	MindMapModel* _MindMap;
	istringstream _is;
	int _state;
	bool _isRunning;
	string _input, _command, _node_name;
	int _node_id;
};

