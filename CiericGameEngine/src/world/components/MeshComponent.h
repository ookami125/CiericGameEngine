#pragma once
#include "BaseComponent.h"
#include "..\..\graphics\Mesh.h"

using namespace GameEngine::Graphics;

namespace GameEngine::World::Components
{
	class MeshComponent : public BaseComponent
	{
	public:
		Mesh* mesh;
	public:
		MeshComponent(Mesh* mesh);

		static ComponentType* GetStaticType()
		{
			static ComponentType type({ "Mesh" });
			return &type;
		}

		inline virtual ComponentType* GetType() const override { return GetStaticType(); }
	};
}