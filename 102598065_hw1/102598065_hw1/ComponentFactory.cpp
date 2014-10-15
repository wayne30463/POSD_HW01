#include "ComponentFactory.h"
#include "Root.h"
#include "Node.h"

ComponentFactory::ComponentFactory()
{
}


ComponentFactory::~ComponentFactory()
{
}

Component* ComponentFactory::create(Component::ComponentType ct, int id, string description)
{
	if (ct == Component::Root)
	{
		return new Root(id, description);
	}
	else if (ct == Component::Node)
	{
		return new Node(NULL, id, description);
	}
	else
	{
		return NULL;
	}
}