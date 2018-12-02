#pragma once
#include "../../api_build.h"

namespace Stylite
{
	class STYLITE_API Time
	{
	public:
		static void		FrameUpdate();

		static double	GetDeltaTime();
		static float	TimeScale;

		static double	GetTime();

	private:
		static double	m_LastFrame;
		static float	m_DeltaTime;
	};
}

