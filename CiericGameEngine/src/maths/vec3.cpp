#include "vec3.h"

namespace GameEngine::Maths
{
	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float x, const float y, const float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3::~vec3()
	{
	}

	vec3& vec3::add(const vec3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}

	vec3 & vec3::add(const float & other)
	{
		this->x += other;
		this->y += other;
		this->z += other;
		return *this;
	}

	vec3 & vec3::subtract(const vec3 & other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return *this;
	}

	vec3 & vec3::subtract(const float & other)
	{
		this->x -= other;
		this->y -= other;
		this->z -= other;
		return *this;
	}

	vec3 & vec3::multiply(const vec3 & other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		return *this;
	}

	vec3 & vec3::divide(const vec3 & other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		return *this;
	}

	vec3 & vec3::divide(const float & other)
	{
		this->x /= other;
		this->y /= other;
		this->z /= other;
		return *this;
	}

	bool vec3::compare(const vec3 & other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	vec3 operator+(vec3 lhs, const vec3& rhs)
	{
		return lhs.add(rhs);
	}

	vec3 operator+(vec3 lhs, const float & rhs)
	{
		return lhs.add(rhs);
	}
	
	vec3 operator-(vec3 lhs, const vec3& rhs)
	{
		return lhs.subtract(rhs);
	}

	vec3 operator-(vec3 lhs, const float& rhs)
	{
		return lhs.subtract(rhs);
	}

	vec3 operator*(vec3 lhs, const vec3& rhs)
	{
		return lhs.multiply(rhs);
	}

	vec3 operator/(vec3 lhs, const vec3& rhs)
	{
		return lhs.divide(rhs);
	}

	vec3 operator/(vec3 lhs, const float & rhs)
	{
		return lhs.divide(rhs);
	}

	vec3& vec3::operator+=(const vec3& rhs)
	{
		return add(rhs);
	}

	vec3 & vec3::operator+=(const float & rhs)
	{
		return add(rhs);
	}

	vec3& vec3::operator-=(const vec3& rhs)
	{
		return subtract(rhs);
	}

	vec3& vec3::operator-=(const float& rhs)
	{
		return subtract(rhs);
	}

	vec3& vec3::operator*=(const vec3& rhs)
	{
		return multiply(rhs);
	}

	vec3& vec3::operator/=(const vec3& rhs)
	{
		return divide(rhs);
	}

	vec3 & vec3::operator/=(const float & rhs)
	{
		return divide(rhs);
	}

	bool vec3::operator==(const vec3& rhs)
	{
		return compare(rhs);
	}

	bool vec3::operator!=(const vec3& rhs)
	{
		return !compare(rhs);
	}

	std::ostream& operator<< (std::ostream& stream, const vec3& vec)
	{
		return stream << "{" << vec.x << ", " << vec.y << ", " << vec.z << "}";
	}
}