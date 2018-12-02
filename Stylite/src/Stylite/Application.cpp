#include "Application.h"
#include "Display/Display.h"
#include <thread>

namespace Stylite
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		m_running = true;
		std::thread application_thread([this]
		{
			while (m_running)
			{
				Update();
			}
		});
		application_thread.detach();

		if (engine)
		{
			engine->RegisterApplication(this);
			engine->Start();
		}

		Close();
		Shutdown();
	}

	void Application::Close()
	{
		m_running = false;
	}
}