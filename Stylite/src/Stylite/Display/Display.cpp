#define GLEW_STATIC
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "Display.h"
#include "../Engine/Input/Mouse.h"
#include <thread>

namespace Stylite
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
	void scrollwheel_callback(GLFWwindow* window, double xoffset, double yoffset);

	void Display::CreateDisplay(int width, int height, const char* title, bool fullscreen, bool mouseGrabbed)
	{
		Display::width = width;
		Display::height = height;
		Display::aspectRatio = (float)width / (float)height;
		Display::fullscreen = fullscreen;
		Display::mouseGrabbed = mouseGrabbed;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Settings::OpenGL::MajorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Settings::OpenGL::MinorVersion);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		if (Settings::OpenGL::AntiAliasing)
			glfwWindowHint(GLFW_SAMPLES, Settings::OpenGL::MSAASamples);

		GLFWmonitor* monitorFlag = NULL;
		if (fullscreen) monitorFlag = glfwGetPrimaryMonitor();
		window = glfwCreateWindow(width, height, title, monitorFlag, NULL);

		if (window == NULL)
		{
			glfwTerminate();
			throw std::exception("Failed to Initialize GLFW\n");
			return;
		}

		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwSetScrollCallback(window, scrollwheel_callback);
		glfwSwapInterval(0);

		if (mouseGrabbed) glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}

	void Display::CreateDefaultDisplay()
	{
		CreateDisplay(
						Settings::Display::DisplayWidth,
						Settings::Display::DisplayHeight,
						Settings::Display::DisplayTitle,
						Settings::Display::Fullscreen,
						Settings::Display::MouseGrabbed
					 );
	}

	void Display::Destroy()
	{
		glfwTerminate();
	}

	void Display::CreateOpenglContext()
	{
		glfwMakeContextCurrent(window);
	}

	void Display::SetWindowTitle(const char* title)
	{
		glfwSetWindowTitle(window, title);
	}

	bool Display::IsOpened()
	{
		return !glfwWindowShouldClose(window);
	}

	void Display::Update()
	{
		glfwSwapBuffers(window);
	}

	void scrollwheel_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		Mouse::_Distances_Moved[2] = (float)yoffset;
	}
}