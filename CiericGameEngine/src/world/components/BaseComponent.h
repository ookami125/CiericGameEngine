#pragma once
#include <string>

namespace GameEngine::World
{
	class Entity;
}

namespace GameEngine::World::Components
{
	struct ComponentType
	{
		std::string id;
	};

	class BaseComponent
	{
	protected:
		Entity* m_Entity;
	public:
		virtual Entity* GetEntity() { return m_Entity; }
		virtual ComponentType* GetType() const { return nullptr; }
	};
}