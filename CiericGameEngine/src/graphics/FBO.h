#pragma once
#include <GL\glew.h>

namespace GameEngine::Graphics
{
	class FBO
	{
		GLuint Id;
		GLuint ColorBuffer;
		GLuint DepthBuffer;
		GLenum status;
	public:
		FBO(int width, int height);
		void attach();
		void detach();
		GLuint GetColorBuffer();
		GLuint GetDepthBuffer();
	};
}