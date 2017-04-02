#pragma once
#include <unordered_map>
#include "components\BaseComponent.h"

namespace GameEngine::World
{
	using namespace Components;
	class Entity
	{
	protected:
		std::unordered_map<Components::ComponentType*, Components::BaseComponent*> m_Components;
	public:
		Entity();
		~Entity();

		void AddComponent(Components::BaseComponent* component);

		template <typename T>
		const T* GetComponent() const
		{
			return GetComponentInternal<T>();
		}

		template <typename T>
		T* GetComponent()
		{
			return (T*)GetComponentInternal<T>();
		}
	private:
		template <typename T>
		const T* GetComponentInternal() const
		{
			component::ComponentType* type = T::GetStaticType();
			auto it = m_Components.find(type);
			if (it == m_Components.end())
				return nullptr;
			return (T*)it->second;
		}
	};
}