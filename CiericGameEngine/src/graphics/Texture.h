#pragma once
#ifndef GL_GLEW
#define GL_GLEW
#include <GL/glew.h>
#endif
#include <string>
#include "..\lodepng\lodepng.h"

namespace GameEngine::Graphics
{
	enum class TextureWrap
	{
		NONE = 0,
		REPEAT,
		CLAMP,
		MIRRORED_REPEAT,
		CLAMP_TO_EDGE,
		CLAMP_TO_BORDER
	};

	enum class TextureFilter
	{
		NONE = 0,
		LINEAR,
		NEAREST
	};

	enum class TextureFormat
	{
		NONE = 0,
		RGB,
		RGBA,
		LUMINANCE,
		LUMINANCE_ALPHA
	};

	struct Texture
	{
		static TextureWrap s_WrapMode;
		static TextureFilter s_FilterMode;
		GLuint ID;
		uint32_t width;
		uint32_t height;
		std::string name;
		std::string path;
	public:
		~Texture() {}

		void Bind(uint32_t slot = 0) const;
		void Unbind(uint32_t slot = 0) const;

		const std::string& GetName() const;
		const std::string& GetFilepath() const;
	public:
		inline static void SetWrap(TextureWrap mode) { s_WrapMode = mode; }
		inline static void SetFilter(TextureFilter mode) { s_FilterMode = mode; }
	public:
		static uint8_t GetStrideFromFormat(TextureFormat format);

		static Texture* LoadFromFile(std::string path);
	};
}