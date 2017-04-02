#pragma once
#include "BaseComponent.h"
#include "..\..\graphics\Texture.h"

using namespace GameEngine::Graphics;

namespace GameEngine::World::Components
{
	class SpriteComponent : public BaseComponent
	{
	public:
		Texture* sprite;
	public:
		SpriteComponent(Texture* sprite);

		static ComponentType* GetStaticType()
		{
			static ComponentType type({ "Texture" });
			return &type;
		}

		inline virtual ComponentType* GetType() const override { return GetStaticType(); }
	};
}