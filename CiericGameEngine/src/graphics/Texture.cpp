#include "Texture.h"

namespace GameEngine::Graphics
{
	TextureWrap Texture::s_WrapMode = TextureWrap::CLAMP;
	TextureFilter Texture::s_FilterMode = TextureFilter::LINEAR;

	void Texture::Bind(uint32_t slot) const
	{
		glActiveTexture(GL_TEXTURE0+slot);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
	void Texture::Unbind(uint32_t slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	const std::string & Texture::GetName() const
	{
		return name;
	}
	const std::string & Texture::GetFilepath() const
	{
		return path;
	}
	uint8_t Texture::GetStrideFromFormat(TextureFormat format)
	{
		switch (format)
		{
		case TextureFormat::RGB:				return 3;
		case TextureFormat::RGBA:				return 4;
		case TextureFormat::LUMINANCE:			return 3;
		case TextureFormat::LUMINANCE_ALPHA:	return 4;
		}
		return 0;
	}

	void image_flip_y(unsigned* &pixels, unsigned width, unsigned height)
	{
		unsigned* buffer = (unsigned*)malloc(width * sizeof(unsigned));
		for (unsigned int y = 0; y < height / 2; ++y)
		{
			memcpy_s(buffer, width * sizeof(unsigned), &pixels[y*width], width * sizeof(unsigned));
			memcpy_s(&pixels[y*width], width * sizeof(unsigned), &pixels[(height - 1 - y)*width], width * sizeof(unsigned));
			memcpy_s(&pixels[(height - 1 - y)*width], width * sizeof(unsigned), buffer, width * sizeof(unsigned));
		}
		free(buffer);
	}

	Texture* Texture::LoadFromFile(std::string fullpath)
	{
		Texture* tex = new Texture();
		char drive[_MAX_DRIVE], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
		_splitpath_s(fullpath.c_str(), drive, dir, fname, ext);
		std::string path(drive); path += dir;
		std::string name(fname); name += ext;
		tex->path = path;
		tex->name = name;
		
		GLuint idx = -1;
		glGenTextures(1, &idx);
		glBindTexture(GL_TEXTURE_2D, idx);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		unsigned* pixels, width, height;
		lodepng_decode32_file((unsigned char**)&pixels, &width, &height, path.c_str());
		image_flip_y(pixels, width, height);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		free(pixels);
		tex->ID = idx;
		tex->width = width;
		tex->height = height;
		return tex;
	}
}