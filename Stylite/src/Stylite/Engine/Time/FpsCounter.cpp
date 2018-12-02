#include "FpsCounter.h"
#include "Time.h"

namespace Stylite
{
	FpsCounter::FpsCounter()
	{
		m_PreviousTime = Time::GetTime();
	}

	FpsCounter::~FpsCounter()
	{
	}

	void FpsCounter::Update()
	{
		if (i == 100000) i = 0;
		i++;

		double _CurrentTime = Time::GetTime();
		frameCount++;

		if (_CurrentTime - m_PreviousTime >= 1.0)
		{
			m_FramesPerSecond = frameCount;
			frameCount = 0;
			m_PreviousTime = _CurrentTime;
		}

	}
}
