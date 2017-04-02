#include "Entity.h"

namespace GameEngine::World
{
	using namespace Components;
	
	Entity::Entity(){}

	Entity::~Entity()
	{
		for (auto it = m_Components.begin(); it != m_Components.end(); ++it)
			delete it->second;
	}

	void Entity::AddComponent(BaseComponent* component)
	{
		m_Components[component->GetType()] = component;
	}
}