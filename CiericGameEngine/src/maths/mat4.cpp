#include "mat4.h"

namespace GameEngine::Maths
{

	mat4::mat4()
	{
		e[0] = e[4] = e[8] = e[12] = 0;
		e[1] = e[5] = e[9] = e[13] = 0;
		e[2] = e[6] = e[10] = e[14] = 0;
		e[3] = e[7] = e[11] = e[15] = 0;
	}

	mat4::mat4(float d)
	{
		e[0] = e[4] = e[8] = e[12] = 0;
		e[1] = e[5] = e[9] = e[13] = 0;
		e[2] = e[6] = e[10] = e[14] = 0;
		e[3] = e[7] = e[11] = e[15] = 0;
		e[0] = e[5] = e[10] = e[15] = d;
	}

	mat4::~mat4()
	{
	}

	mat4 mat4::identity()
	{
		return mat4(1);
	}

	mat4& mat4::multiply(const mat4 & other)
	{
		mat4 temp = {};
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				for (int i = 0; i < 4; i++)
					temp.e[y + x * 4] += e[x * 4 + i] * other.e[i * 4 + y];
		for (int i = 0; i < 16; i++)
			e[i] = temp.e[i];
		return *this;
	}

	mat4 & mat4::operator*=(const mat4 & other)
	{
		return multiply(other);
	}

	mat4 mat4::orthographic(float l, float r, float b, float t, float n, float f)
	{
		mat4 mat = scale(vec3(2.0f / (r - l), 2 / (t - b), -2 / (f - n)));
		mat.e[12] = -(r + l) / (r - l);
		mat.e[13] = -(t + b) / (t - b);
		mat.e[14] = -(f + n) / (f - n);
		return mat;
	}

	mat4 mat4::perspective(float fov, float ratio, float near, float far)
	{
		mat4 mat = identity();
		float a = tanf(fov / 2.0 * 3.14159f / 180.0f);
		mat.e[0] = 1.0f / (a * ratio);
		mat.e[5] = 1.0f / a;
		mat.e[10] = (-near - far) / (near - far);
		mat.e[11] = 1.0f;
		mat.e[14] = 2.0f * near * far / (near - far);
		return mat;
	}

	mat4 mat4::translation(const vec3 & translate)
	{
		mat4 mat = identity();
		mat.e[3] = translate.x;//12
		mat.e[7] = translate.y;//13
		mat.e[11] = translate.z;//14
		mat.e[15] = 1.0f;//15
		return mat;
	}


	mat4 mat4::rotation(float angle, const vec3& axis)
	{
		mat4 result(1.0f);

		float r = angle*(float)M_PI/180.0f;
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.e[0 + 0 * 4] = x * omc + c;
		result.e[0 + 1 * 4] = y * x * omc + z * s;
		result.e[0 + 2 * 4] = x * z * omc - y * s;

		result.e[1 + 0 * 4] = x * y * omc - z * s;
		result.e[1 + 1 * 4] = y * omc + c;
		result.e[1 + 2 * 4] = y * z * omc + x * s;

		result.e[2 + 0 * 4] = x * z * omc + y * s;
		result.e[2 + 1 * 4] = y * z * omc - x * s;
		result.e[2 + 2 * 4] = z * omc + c;

		return result;
	}

	mat4 mat4::scale(const vec3 & scale)
	{
		mat4 mat = mat4();
		mat.e[0] = scale.x;
		mat.e[5] = scale.y;
		mat.e[10] = scale.z;
		mat.e[15] = 1.0f;
		return mat;
	}

	mat4 operator*(mat4 lhs, const mat4 & rhs)
	{
		return lhs.multiply(rhs);
	}
}