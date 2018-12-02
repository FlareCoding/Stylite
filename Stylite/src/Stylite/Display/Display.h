#pragma once
#define GLEW_STATIC
#include "../Config/Configuration.h"
#pragma warning(disable: 4099)

class GLFWwindow;

namespace Stylite
{
	class Display
	{
	public:
		void CreateDisplay(int width, int height, const char* title, bool fullscreen = false, bool mouseGrabbed = false);
		void Destroy();
		void CreateDefaultDisplay();

		void CreateOpenglContext();
		GLFWwindow* GetWindowPtr() { return window; }
		void SetWindowTitle(const char* title);

		bool IsOpened();
		void Update();

		int GetWidth() { return width; }
		int GetHeight() { return height; }
		float GetAspectRatio() { return aspectRatio; }
		bool IsFullscreen() { return fullscreen; }
		bool IsMouseGrabbed() { return mouseGrabbed; }

	private:
		GLFWwindow* window;
		int width, height;
		float aspectRatio;
		bool fullscreen, mouseGrabbed;
	};
}