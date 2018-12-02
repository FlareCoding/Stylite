#pragma once

namespace Stylite
{
	namespace Settings
	{
		namespace OpenGL
		{
			extern int MajorVersion, MinorVersion;
			extern bool AntiAliasing;
			extern int MSAASamples;
		}

		namespace Display
		{
			extern int DisplayWidth, DisplayHeight;
			extern const char* DisplayTitle;
			extern bool Fullscreen, MouseGrabbed;
		}

		namespace Engine
		{
			namespace Shaders
			{
				extern const char* SRC_PATH;
			}
		}
	}
}