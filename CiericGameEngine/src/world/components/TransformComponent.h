#pragma once
#include "BaseComponent.h"
#include "..\..\maths.h"

using namespace GameEngine::Maths;

namespace GameEngine::World::Components
{
	class TransformComponent : public BaseComponent
	{
	public:
		mat4 transform;
	public:
		TransformComponent(const mat4& transform);

		static ComponentType* GetStaticType()
		{
			static ComponentType type({ "Transform" });
			return &type;
		}

		inline virtual ComponentType* GetType() const override { return GetStaticType(); }
	};
}