#include "TextUI.h"
#include "MindMapModel.h"

int main(void)
{
	MindMapModel* MindMap = new MindMapModel();
	TextUI* textUI = new TextUI(MindMap);
	textUI->run();
	delete textUI;
	delete MindMap;
	return 0;
}