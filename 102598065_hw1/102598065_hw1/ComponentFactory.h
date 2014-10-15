#pragma once
#include "Component.h"
#include "string"
using namespace std;

class ComponentFactory
{
public:
	ComponentFactory();
	~ComponentFactory();
	Component* create(Component::ComponentType, int, string);
};

