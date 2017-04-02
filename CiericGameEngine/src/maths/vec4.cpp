#include "vec4.h"

namespace GameEngine::Maths
{
	vec4::vec4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	vec4::vec4(const float x, const float y, const float z, const float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4::~vec4()
	{
	}

	vec4& vec4::add(const vec4& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		return *this;
	}

	vec4 & vec4::subtract(const vec4 & other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return *this;
	}

	vec4 & vec4::multiply(const vec4 & other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;
		return *this;
	}

	vec4 & vec4::divide(const vec4 & other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;
		return *this;
	}

	bool vec4::compare(const vec4 & other)
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	vec4 operator+(vec4 lhs, const vec4& rhs)
	{
		return lhs.add(rhs);
	}

	vec4 operator-(vec4 lhs, const vec4& rhs)
	{
		return lhs.subtract(rhs);
	}

	vec4 operator*(vec4 lhs, const vec4& rhs)
	{
		return lhs.multiply(rhs);
	}

	vec4 operator/(vec4 lhs, const vec4& rhs)
	{
		return lhs.divide(rhs);
	}

	vec4& vec4::operator+=(const vec4& rhs)
	{
		return add(rhs);
	}

	vec4& vec4::operator-=(const vec4& rhs)
	{
		return subtract(rhs);
	}

	vec4& vec4::operator*=(const vec4& rhs)
	{
		return multiply(rhs);
	}

	vec4& vec4::operator/=(const vec4& rhs)
	{
		return divide(rhs);
	}

	bool vec4::operator==(const vec4& rhs)
	{
		return compare(rhs);
	}

	bool vec4::operator!=(const vec4& rhs)
	{
		return !compare(rhs);
	}

	std::ostream& operator<< (std::ostream& stream, const vec4& vec)
	{
		return stream << "{" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "}";
	}
}