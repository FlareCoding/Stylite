#include "Keyboard.h"
#include <iostream>

namespace Stylite
{
	namespace Keyboard
	{
		bool Keyboard::_Key_States[62];

		STYLITE_API bool IsKeyDown(Key _key)
		{
			return _Key_States[_key];
		}
	}
}
