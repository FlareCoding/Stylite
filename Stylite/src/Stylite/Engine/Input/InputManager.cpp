#include "InputManager.h"
#include "../../Display/Display.h"
#include <GLFW/glfw3.h>

namespace Stylite
{
	InputManager::InputManager(Display* _display) : m_Display(_display)
	{
	}

	InputManager::~InputManager()
	{
	}

	void InputManager::Update()
	{
		QueryMouseMovement(); // needs to be before glfwPollEvents() because the latter will activate a scroll wheel callback
		glfwPollEvents();
		QueryKeyStates();
		QueryMouseKeyStates();
	}

	void InputManager::QueryKeyStates()
	{
		GLFWwindow* window = m_Display->GetWindowPtr();
		// a-z
		size_t _StartIndex = 65;
		for (size_t i = _StartIndex; i < 91; i++)
		{
			Keyboard::_Key_States[1 + i - _StartIndex] = (glfwGetKey(window, i) == GLFW_PRESS);
		}

		// 0-9
		_StartIndex = 48;
		for (size_t i = _StartIndex; i < 58; i++)
			Keyboard::_Key_States[Keyboard::KEY_0 + (i - _StartIndex)] = (glfwGetKey(window, i) == GLFW_PRESS);

		// f1-f12
		_StartIndex = 290;
		for (size_t i = _StartIndex; i < 302; i++)
			Keyboard::_Key_States[Keyboard::KEY_F1 + (i - _StartIndex)] = (glfwGetKey(window, i) == GLFW_PRESS);

		Keyboard::_Key_States[Keyboard::KEY_LEFT] = (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_RIGHT] = (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_UP] = (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_DOWN] = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);

		Keyboard::_Key_States[Keyboard::KEY_LSHIFT] = (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_RSHIFT] = (glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_SPACE] = (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_ALT] = (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_LCTRL] = (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_RCTRL] = (glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_CAPSLOCK] = (glfwGetKey(window, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_TAB] = (glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_ENTER] = (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS);
		Keyboard::_Key_States[Keyboard::KEY_BACKSPACE] = (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS);
	}

	void InputManager::QueryMouseKeyStates()
	{
		GLFWwindow* window = m_Display->GetWindowPtr();

		// mouse1 - mouse8
		size_t _StartIndex = 0;
		for (size_t i = _StartIndex; i < 9; i++)
			Mouse::_Button_States[i] = (glfwGetMouseButton(window, i) == GLFW_PRESS);
	}

	void InputManager::QueryMouseMovement()
	{
		GLFWwindow* window = m_Display->GetWindowPtr();

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		// intial correction
		if (first_time)
		{
			lastMousePosX = (float)xpos;
			lastMousePosY = (float)ypos;
			first_time = false;
		}

		xoffset = (float)xpos - lastMousePosX;
		yoffset = lastMousePosY - (float)ypos; // reversed since y-coordinates go from bottom to top

		lastMousePosX = (float)xpos;
		lastMousePosY = (float)ypos;

		// updating mouse information
		Mouse::_Distances_Moved[0] = xoffset;
		Mouse::_Distances_Moved[1] = yoffset;
		Mouse::_Distances_Moved[2] = 0.0f; // glfw scroll wheel callback will assign a value
		Mouse::_Mouse_Pos[0] = lastMousePosX;
		Mouse::_Mouse_Pos[1] = lastMousePosY;
	}
}
