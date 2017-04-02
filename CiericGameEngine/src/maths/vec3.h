#pragma once

#include <iostream>

namespace GameEngine::Maths
{
	struct vec3
	{
		float x, y, z;
		vec3();
		vec3(const float x, const float y, const float z);
		~vec3();
		vec3& add(const vec3 & other);
		vec3& add(const float & other);
		vec3& subtract(const vec3 & other);
		vec3& subtract(const float & other);
		vec3& multiply(const vec3 & other);
		vec3& divide(const vec3 & other);
		vec3& divide(const float & other);
		bool compare(const vec3 & other);

		friend vec3 operator+(vec3 lhs, const vec3& rhs);
		friend vec3 operator+(vec3 lhs, const float& rhs);
		friend vec3 operator-(vec3 lhs, const vec3& rhs);
		friend vec3 operator-(vec3 lhs, const float& rhs);
		friend vec3 operator*(vec3 lhs, const vec3& rhs);
		friend vec3 operator/(vec3 lhs, const vec3& rhs);
		friend vec3 operator/(vec3 lhs, const float& rhs);

		vec3& operator+=(const vec3& rhs);
		vec3& operator+=(const float& rhs);
		vec3& operator-=(const vec3& rhs);
		vec3& operator-=(const float& rhs);
		vec3& operator*=(const vec3& rhs);
		vec3& operator/=(const vec3& rhs);
		vec3& operator/=(const float& rhs);
		bool operator==(const vec3& rhs);
		bool operator!=(const vec3& rhs);

		friend std::ostream& operator<< (std::ostream& stream, const vec3& vec);
	};
}
