#pragma once
#include "api_build.h"
#include "Engine/Engine.h"

namespace Stylite
{
	class STYLITE_API Application
	{
	public:
		Application();

		virtual void Initialize() {}
		virtual void Shutdown() {}
		virtual void Update() {}
		virtual void EngineUpdate() {}

		void Run();
		virtual ~Application();

	protected:
		Engine* engine = nullptr;

	private:
		void Close();
		bool m_running = false;
	};
}
