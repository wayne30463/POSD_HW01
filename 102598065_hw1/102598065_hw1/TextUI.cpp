#include "TextUI.h"
#include "DisplayMsg.h"
#include <iostream>
#include <string>
#include "define.h"
using namespace std;

TextUI::TextUI(MindMapModel* MindMap)
{
	_MindMap = MindMap;
	_state = STATE_MAIN;
	_isRunning = true;
	_node_id = -1;
}

TextUI::~TextUI()
{
}

void TextUI::show_cre()
{
	//���-�إ߾�
	DisplayMsg::enterTopicMsg();
	getline(cin, _input);
	cout << endl;
	_MindMap->createMindMap(_input);
	DisplayMsg::displayMindMap(_MindMap->getName(), _MindMap->drawMap());
	DisplayMsg::displayLine();
	_state = STATE_MAIN;
}

void TextUI::show_main()
{
	//���-�D�e��
	DisplayMsg::displayMainMenu();
	getline(cin, _input);
	_state = atoi(_input.c_str());
}

void TextUI::show_ins()
{
	//���-���J
	DisplayMsg::displayMindMap(_MindMap->getName(), _MindMap->drawMap());
	if (_MindMap->getNodeCount() == TREE_IS_EMPTY)
	{
		_state = STATE_MAIN;
	}
	else
	{
		DisplayMsg::enterNodeIdMsg();
		getline(cin, _input);
		_state = STATE_INSERT_CHECK_ID;
	}
}

void TextUI::show_ins_ck_id()
{
	//���-���J-��Jid
	_node_id = atoi(_input.c_str());
	if (!(_input.c_str()[0] >= ASCII_0 && _input.c_str()[0] <= ASCII_9))
	{
		DisplayMsg::WrongCannotInputStr();
		_state = STATE_INSERT;
	}
	else if (_MindMap->searchNodeById(_node_id))
	{
		DisplayMsg::displayInsertMenu();
		getline(cin, _command);
		_state = STATE_INSERT_CHECK_COMMAND;
	}
	else
	{
		DisplayMsg::WrongCannotInputStr();
		_state = STATE_INSERT;
	}
}

void TextUI::show_ins_ck_cmd()
{
	//���-���J-��J���O
	if (_command.size() != 1 || (_command.compare(ADD_CHILD) && _command.compare(ADD_PARENT) && _command.compare(ADD_SIBLING)))
	{
		DisplayMsg::WrongInsCom();
		_state = STATE_MAIN;
	}
	else if (!_command.compare(ADD_CHILD))
	{
		_state = STATE_INSERT_ENTER_NODENAME;
	}
	else if (_MindMap->check_NodeIsRoot(_node_id))
	{
		DisplayMsg::WrongRootCannotAddSelect(_command);
		_state = STATE_MAIN;
	}
	else
	{
		_state = STATE_INSERT_ENTER_NODENAME;
	}
}

void TextUI::show_ins_in_nn()
{
	//���-���J-��J�W��
	DisplayMsg::enterNodeNameMsg();
	getline(cin, _node_name);
	if (_MindMap->insertNode(_node_id, _node_name, _command) == INSERT_SUCCESS)
	{
		DisplayMsg::displayMindMap(_MindMap->getName(), _MindMap->drawMap());
		DisplayMsg::displayLine();
	}
	else if (_command.compare(ADD_PARENT))
	{
		DisplayMsg::WrongRootCannotAddPar();
	}
	else if (_command.compare(ADD_SIBLING))
	{
		DisplayMsg::WrongRootCannotAddSib();
	}
	_state = STATE_MAIN;
}

void TextUI::show_dis()
{
	//���-��ܾ�
	DisplayMsg::displayMindMap(_MindMap->getName(), _MindMap->drawMap());
	_state = STATE_MAIN;
}

void TextUI::show_sav()
{
	//���-�s��
	_MindMap->saveMindMap();
	DisplayMsg::saveSuccessMsg();
	_state = STATE_DISPLAY;
}

void TextUI::show_exit()
{
	//���-���}
	DisplayMsg::enterIfWantSave();
	getline(cin, _input);
	if (!_input.compare(YES))
	{
		_MindMap->saveMindMap();
		DisplayMsg::saveSuccessMsg();
		_state = EXIT;
	}
	else if (!_input.compare(NO))
	{
		_state = EXIT;
	}
	else
		_state = STATE_MAIN;
}

void TextUI::run()
{
	//����
	while (_isRunning)
	{
		switch (_state)
		{
		default:
			_state = STATE_MAIN;
			break;
		case STATE_MAIN:
			show_main();
			break;
		case STATE_CREATE:
			show_cre();
			break;
		case STATE_INSERT:
			show_ins();
			break;
		case STATE_INSERT_CHECK_ID:
			show_ins_ck_id();
			break;
		case STATE_INSERT_CHECK_COMMAND:
			show_ins_ck_cmd();
			break;
		case STATE_INSERT_ENTER_NODENAME:
			show_ins_in_nn();
			break;
		case STATE_DISPLAY:
			show_dis();
			break;
		case STATE_SAVE:
			show_sav();
			break;
		case STATE_EXIT:
			show_exit();
			break;
		case EXIT:
			_isRunning = false;
			break;
		}
		cout << endl;
	}
}
