#pragma once
#include "..\maths.h"

namespace GameEngine::Maths
{
	struct mat4
	{
		float e[16];

		mat4();
		mat4(float d);
		~mat4();

		static mat4 identity();

		mat4& multiply(const mat4& other);
		friend mat4 operator*(mat4 lhs, const mat4& rhs);
		mat4& operator*=(const mat4& other);

		static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
		static mat4 perspective(float fov, float ratio, float near, float far);

		static mat4 translation(const vec3& translate);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);

	};

}