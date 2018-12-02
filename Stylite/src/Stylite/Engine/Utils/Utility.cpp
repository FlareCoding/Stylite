#include "Utility.h"
#define GLEW_STATIC
#include <GLEW/glew.h>
#include <stb_image.h>
#include <Windows.h>
#include <iostream>

namespace Stylite
{
	STYLITE_API Texture CreateTexture(const char* path, TextureWrappingOption wrapping_option, bool vertical_flip)
	{
		unsigned int textureID;
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		int width, height, nrChannels;
		if (vertical_flip) stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load(path, &width, &height, &nrChannels, STBI_rgb_alpha);
		if (data)
		{
			unsigned int gl_wrapping_option;
			if (wrapping_option == TiledRepeat)			gl_wrapping_option = GL_REPEAT;
			if (wrapping_option == MirroredRepeat)		gl_wrapping_option = GL_MIRRORED_REPEAT;
			if (wrapping_option == ClampToEdge)			gl_wrapping_option = GL_CLAMP_TO_EDGE;
			if (wrapping_option == ClampToBorder)			gl_wrapping_option = GL_CLAMP_TO_BORDER;

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, gl_wrapping_option);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, gl_wrapping_option);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -0.2f);
		}
		else
		{
			textureID = 0;
			PrintMessageError("Failed to load texture: " + std::string(path));
		}

		stbi_image_free(data);
		glBindTexture(GL_TEXTURE_2D, 0);
		
		Texture tex;
		tex.id = textureID;
		return tex;
	}

	void SetConsoleColor(int color)
	{
		HANDLE  hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		FlushConsoleInputBuffer(hConsole);
		SetConsoleTextAttribute(hConsole, color);
	}

	void PrintMessageSuccess(std::string message)
	{
		SetConsoleColor(CONSOLE_COLOR_GREEN);
		std::cout << message << "\n";
		SetConsoleColor(CONSOLE_COLOR_DEFAULT);
	}

	void PrintMessageError(std::string message)
	{
		SetConsoleColor(CONSOLE_COLOR_RED);
		std::cout << message << "\n";
		SetConsoleColor(CONSOLE_COLOR_DEFAULT);
	}

	void PrintMessageWithColor(std::string message, int color)
	{
		SetConsoleColor(color);
		std::cout << message << "\n";
		SetConsoleColor(CONSOLE_COLOR_DEFAULT);
	}
}
