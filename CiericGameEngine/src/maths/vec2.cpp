#include "vec2.h"

namespace GameEngine::Maths
{
	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float x, const float y)
	{
		this->x = x;
		this->y = y;
	}

	vec2::~vec2()
	{
	}

	vec2& vec2::add(const vec2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	vec2& vec2::subtract(const vec2 & other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	vec2& vec2::multiply(const vec2 & other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	vec2& vec2::divide(const vec2 & other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	bool vec2::compare(const vec2 & other)
	{
		return x == other.x && y == other.y;
	}

	vec2 operator+(vec2 lhs, const vec2& rhs)
	{
		return lhs.add(rhs);
	}
	
	vec2 operator-(vec2 lhs, const vec2& rhs)
	{
		return lhs.subtract(rhs);
	}

	vec2 operator*(vec2 lhs, const vec2& rhs)
	{
		return lhs.multiply(rhs);
	}

	vec2 operator/(vec2 lhs, const vec2& rhs)
	{
		return lhs.divide(rhs);
	}

	vec2& vec2::operator+=(const vec2& rhs)
	{
		return add(rhs);
	}

	vec2& vec2::operator-=(const vec2& rhs)
	{
		return subtract(rhs);
	}

	vec2& vec2::operator*=(const vec2& rhs)
	{
		return multiply(rhs);
	}

	vec2& vec2::operator/=(const vec2& rhs)
	{
		return divide(rhs);
	}

	bool vec2::operator==(const vec2& rhs)
	{
		return compare(rhs);
	}

	bool vec2::operator!=(const vec2& rhs)
	{
		return !compare(rhs);
	}

	std::ostream& operator<< (std::ostream& stream, const vec2& vec)
	{
		return stream << "{" << vec.x << ", " << vec.y << "}";
	}
}