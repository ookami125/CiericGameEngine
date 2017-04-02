#pragma once
#include "Entity.h"
#include "..\Graphics.h"
#include "..\graphics\Camera.h"

namespace GameEngine::World
{
	class Scene
	{
	private:
		Graphics::Camera* m_Camera;
		std::vector<Entity*> m_Entities;
	public:
		Scene();
		Scene(const mat4& projectionMatrix);
		~Scene();

		void Add(Entity* entity);
		virtual void OnUpdate() = 0;
		void OnRender();

		inline Graphics::Camera* GetCamera() { return m_Camera; }
	};
}