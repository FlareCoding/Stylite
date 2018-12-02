#include "Time.h"
#include <GLFW/glfw3.h>

namespace Stylite
{
	double Time::m_LastFrame	= 0.0;
	float  Time::m_DeltaTime	= 0.0f;
	float  Time::TimeScale		= 1.0f;

	void Time::FrameUpdate()
	{
		double _CurrentFrame = GetTime();
		m_DeltaTime = (float)(_CurrentFrame - m_LastFrame);
		m_LastFrame = _CurrentFrame;
	}
	double Time::GetDeltaTime()
	{
		return m_DeltaTime * (double)TimeScale;
	}

	double Time::GetTime()
	{
		return glfwGetTime();
	}
}
