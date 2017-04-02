#include "TransformComponent.h"

namespace GameEngine::World::Components
{
	TransformComponent::TransformComponent(const mat4& transform) : transform(transform) {}
}