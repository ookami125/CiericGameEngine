#include "Shader.h"
#include <vector>

namespace GameEngine::Graphics
{
	ShaderObject::ShaderObject(char * path, GLuint shaderType)
	{
		FILE *f;
		fopen_s(&f, path, "rb");
		if (f == NULL)
		{
			printf("Error: file (%s) does not exist!\n", path);
			return;
		}
		fseek(f, 0, SEEK_END);
		int fsize = ftell(f);
		fseek(f, 0, SEEK_SET);
		char *source = (char *)malloc(fsize + 1);
		fread(source, fsize, 1, f);
		fclose(f);
		source[fsize] = 0;

		Id = glCreateShader(shaderType);
		glShaderSource(Id, 1, &source, &((int)fsize));
		glCompileShader(Id);

		//std::cout << source << std::endl;

		GLint isCompiled = 0;
		glGetShaderiv(Id, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			std::cout << "Error: ";
			GLint maxLength = 0;
			glGetShaderiv(Id, GL_INFO_LOG_LENGTH, &maxLength);
			std::vector<GLchar> errorLog(maxLength);
			glGetShaderInfoLog(Id, maxLength, &maxLength, &errorLog[0]);
			std::cout << &errorLog[0] << std::endl;
			glDeleteShader(Id);
			return;
		}
		delete source;
	}

	ShaderObject::~ShaderObject()
	{
		glDeleteShader(Id);
	}

	void ShaderObject::attach(GLuint program)
	{
		glAttachShader(program, Id);
	}

	bool ShaderObject::valid()
	{
		GLint isCompiled = 0;
		glGetShaderiv(Id, GL_COMPILE_STATUS, &isCompiled);
		return isCompiled==GL_TRUE;
	}

	ShaderProgram::ShaderProgram(char * vspath, char * fspath)
	{
		ShaderObject* vertShader = new ShaderObject(vspath, GL_VERTEX_SHADER);
		ShaderObject* fragShader = new ShaderObject(fspath, GL_FRAGMENT_SHADER);
		if (!vertShader->valid())
			return;
		if (!fragShader->valid())
			return;
		Id = glCreateProgram();
		vertShader->attach(Id);
		fragShader->attach(Id);
		glLinkProgram(Id);

		GLint result = GL_FALSE;
		int logLength;

		glGetProgramiv(Id, GL_LINK_STATUS, &result);
		if (result == GL_FALSE)
		{
			std::cout << "Error: ";
			glGetProgramiv(Id, GL_INFO_LOG_LENGTH, &logLength);
			std::vector<char> programError((logLength > 1) ? logLength : 1);
			glGetProgramInfoLog(Id, logLength, NULL, &programError[0]);
			std::cout << &programError[0] << std::endl;
		}

		delete vertShader;
		delete fragShader;

	}

	ShaderProgram::~ShaderProgram()
	{

	}

	void ShaderProgram::Use()
	{
		glUseProgram(Id);
	}
}