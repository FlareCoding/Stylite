#pragma once
#include "../../api_build.h"
#include <string>
#include "../MeshData/Texture.h"

#define CONSOLE_COLOR_DEFAULT 15
#define CONSOLE_COLOR_RED 4
#define CONSOLE_COLOR_GREEN 2
#define CONSOLE_COLOR_BLUE 1

namespace Stylite
{
	enum TextureWrappingOption
	{
		TiledRepeat,
		MirroredRepeat,
		ClampToEdge,
		ClampToBorder
	};

	STYLITE_API Texture CreateTexture(const char* path, TextureWrappingOption wrapping_option, bool vertical_flip = false);

	void SetConsoleColor(int color);
	void PrintMessageSuccess(std::string message);
	void PrintMessageError(std::string message);
	void PrintMessageWithColor(std::string message, int color);
}
