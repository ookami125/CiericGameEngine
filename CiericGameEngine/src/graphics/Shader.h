#pragma once
#ifndef GL_GLEW
#define GL_GLEW
#include <GL/glew.h>
#endif
#include <iostream>

namespace GameEngine::Graphics
{
	class ShaderObject
	{
	private:
		GLuint Id = 0;

	public:
		ShaderObject(char * path, GLuint shaderType);
		~ShaderObject();

		void attach(GLuint program);
		bool valid();
	};

	class ShaderProgram
	{
	private:
	public:
		GLuint Id = 0;
		ShaderProgram(char* vspath, char * fspath);
		void Use();
		~ShaderProgram();
	};
}