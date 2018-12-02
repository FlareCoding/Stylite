#pragma once
#include "../../api_build.h"

namespace Stylite
{
	namespace Mouse
	{
		enum MouseButton
		{
			Button1, Button2, Button3, Button4, Button5, Button6, Button7, Button8
		};

		extern bool _Button_States[6];
		extern float _Distances_Moved[3];
		extern float _Mouse_Pos[2];

		STYLITE_API bool IsPressed(MouseButton _btn);
		STYLITE_API float GetDX();
		STYLITE_API float GetDY();
		STYLITE_API float GetScrollDistance();
		STYLITE_API float GetPosX();
		STYLITE_API float GetPosY();
	}
}
