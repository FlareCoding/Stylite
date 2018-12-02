#include "Configuration.h"

namespace Stylite
{
	namespace Settings
	{
		namespace OpenGL
		{
			int OpenGL::MajorVersion = 4;
			int OpenGL::MinorVersion = 5;
			bool OpenGL::AntiAliasing = true;
			int OpenGL::MSAASamples = 4;
		}

		namespace Display
		{
			int Display::DisplayWidth = 1660;
			int Display::DisplayHeight = 1200;
			const char* Display::DisplayTitle = "Stylite Engine";
			bool Display::Fullscreen = false;
			bool Display::MouseGrabbed = false;
		}

		namespace Engine
		{
			const char* Shaders::SRC_PATH = "C:\\Users\\FlareFlax\\Desktop\\Programming\\Stylite\\Stylite\\src\\Stylite\\Engine\\Shaders\\glsl\\";
		}
	}
}
