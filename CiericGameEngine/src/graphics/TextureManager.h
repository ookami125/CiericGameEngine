#pragma once
#ifndef GL_GLEW
#define GL_GLEW
#include <GL/glew.h>
#endif
#include <unordered_map>
#include <string>
#include <iostream>
#include "../lodepng/lodepng.h"
#include "Texture.h"

using namespace std;

namespace GameEngine::Graphics
{
	class TextureManager
	{
	private:
		static std::vector<Texture*> m_Textures;
	public:
		static Texture* Add(Texture* texture);
		static Texture* Get(const std::string& name);
		static void Clean();
	private:
		TextureManager() { }
	};
}