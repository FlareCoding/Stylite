#include "Mouse.h"

namespace Stylite
{
	namespace Mouse
	{
		bool Mouse::_Button_States[6];
		float Mouse::_Distances_Moved[3];
		float Mouse::_Mouse_Pos[2];

		STYLITE_API bool Mouse::IsPressed(MouseButton _btn)
		{
			return _Button_States[_btn];
		}

		STYLITE_API float GetDX()
		{
			return _Distances_Moved[0];
		}

		STYLITE_API float GetDY()
		{
			return _Distances_Moved[1];
		}

		STYLITE_API float GetScrollDistance()
		{
			return _Distances_Moved[2];
		}
		STYLITE_API float GetPosX()
		{
			return _Mouse_Pos[0];
		}
		STYLITE_API float GetPosY()
		{
			return _Mouse_Pos[1];
		}
	}
}
