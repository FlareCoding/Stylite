#pragma once

namespace Stylite
{
	class FpsCounter
	{
	public:
		FpsCounter();

		bool bEnabled = false;
		int m_FramesPerSecond;

		void Update();

		~FpsCounter();

	private:
		int i = 0;
		int frameCount = 0;
		double m_PreviousTime = 0;
	};
}

