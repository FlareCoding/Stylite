#pragma once
#include "Keyboard.h"
#include "Mouse.h"

namespace Stylite
{
	class Display;
	class InputManager
	{
	public:
		InputManager(Display* _display);

		void Update();

		~InputManager();

	private:
		Display* m_Display;
		void QueryKeyStates();
		void QueryMouseKeyStates();
		void QueryMouseMovement();

		float lastMousePosX = 0.0f;
		float lastMousePosY = 0.0f;
		bool first_time = true;
		float xoffset = 0, yoffset = 0;
	};
}
