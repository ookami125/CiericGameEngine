#include "TextureManager.h"
#include "..\lodepng\lodepng.h"
namespace GameEngine::Graphics
{
	/*
	TextureManager::TextureManager()
	{
	//textures = new map<string, GLint>();
	}

	TextureManager::~TextureManager()
	{
	//delete textures;
	}
	*/
	std::vector<Texture*> TextureManager::m_Textures;

	Texture* TextureManager::Add(Texture* texture)
	{
		m_Textures.push_back(texture);
		return texture;
	}

	Texture* TextureManager::Get(const std::string& name)
	{
		for (Texture* texture : m_Textures)
		{
			if (texture->GetName() == name)
				return texture;
		}
		return nullptr;
	}

	void TextureManager::Clean()
	{
		for (uint32_t i = 0; i < m_Textures.size(); i++)
			delete m_Textures[i];
	}
}

/*
namespace GameEngine::Graphics
{
	TextureManager::TextureManager()
	{
		//textures = new map<string, GLint>();
	}

	TextureManager::~TextureManager()
	{
		//delete textures;
	}

	void image_flip_y(unsigned* &pixels, unsigned width, unsigned height)
	{
		unsigned* buffer = (unsigned*)malloc(width * sizeof(unsigned));
		for (unsigned int y = 0; y < height / 2; ++y)
		{
			memcpy_s(buffer, width * sizeof(unsigned), &pixels[y*width], width * sizeof(unsigned));
			memcpy_s(&pixels[y*width], width*sizeof(unsigned), &pixels[(height-1 - y)*width], width * sizeof(unsigned));
			memcpy_s(&pixels[(height-1 - y)*width], width * sizeof(unsigned), buffer, width * sizeof(unsigned));
		}
		free(buffer);
	}

	Texture* TextureManager::LoadTexture(string path)
	{
		if (texturesID.find(path) == texturesID.end())
		{
			cout << "Texture " << path.c_str() << " loading!" << endl;
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
			glBindTexture(GL_TEXTURE_2D, 0);
			if (idx == -1)
			{
				cout << "Texture " << path.c_str() << " failed to load!" << endl;
				return &NULL_TEXTURE;
			}

			return texturesID[path] = new Texture(idx, width, height);
		}
		else
		{
			cout << "Texture " << path.c_str() << " already exists!" << endl;
			//printf("Texture %s already exists!", name.c_str());
			return &NULL_TEXTURE;
		}
		return &NULL_TEXTURE;
	}
	
	Texture* TextureManager::GetLoadTexture(string path)
	{
		if (texturesID.find(path) == texturesID.end())
		{
			cout << "Texture " << path.c_str() << " loading!" << endl;
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
			glBindTexture(GL_TEXTURE_2D, 0);
			if (idx == -1)
			{
				cout << "Texture " << path.c_str() << " failed to load!" << endl;
				return &NULL_TEXTURE;
			}

			return texturesID[path] = new Texture(idx, width, height);
		}
		else
		{
			cout << "Texture " << path.c_str() << " already exists!" << endl;
			return texturesID[path];
		}
		return &NULL_TEXTURE;
	}

	void TextureManager::UnloadTexture(string name)
	{
		Texture* idx = texturesID[name];
		//Unload Texture from opengl
		texturesID.erase(name);
	}

	Texture* TextureManager::GetTexture(string name)
	{
		return texturesID[name];
	}
}*/