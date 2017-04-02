#ifndef GL_GLEW
#define GL_GLEW
#include <GL/glew.h>
#endif
#include "FBO.h"

namespace GameEngine::Graphics
{
	FBO::FBO(int width, int height)
	{
		glGenFramebuffers(1, &Id);
		glGenTextures(1, &ColorBuffer);
		glGenRenderbuffers(1, &DepthBuffer);

		glBindFramebuffer(GL_FRAMEBUFFER, Id);

		glBindTexture(GL_TEXTURE_2D, ColorBuffer);
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			width, height,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			nullptr);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, ColorBuffer, 0);

		glBindRenderbuffer(GL_RENDERBUFFER, DepthBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width, height);
		glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, DepthBuffer);

		status = glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FBO::attach()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, Id);
	}

	void FBO::detach()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	GLuint FBO::GetColorBuffer()
	{
		return ColorBuffer;
	}
	
	GLuint FBO::GetDepthBuffer()
	{
		return DepthBuffer;
	}
}