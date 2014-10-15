#pragma once
#include "string"
#include "Component.h"
using namespace std;
class ComponentFactory
{
public:
	ComponentFactory();
	~ComponentFactory();
	static Component* create(Component::ComponentType, int, string);
};

