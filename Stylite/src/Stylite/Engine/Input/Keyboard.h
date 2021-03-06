#pragma once
#include "../../api_build.h"

namespace Stylite
{
	namespace Keyboard
	{
		enum Key
		{
			NOKEY, KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
			KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
			KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,
			KEY_LSHIFT, KEY_RSHIFT, KEY_SPACE, KEY_ALT, KEY_LCTRL, KEY_RCTRL, KEY_CAPSLOCK, KEY_TAB, KEY_ENTER, KEY_BACKSPACE,
			KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12
		};

		extern bool _Key_States[62];

		STYLITE_API bool IsKeyDown(Key _key);
	}
}
