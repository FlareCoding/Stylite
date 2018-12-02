#pragma once
#include "../api_build.h"
#include "../Display/Display.h"
#include "Time/Time.h"
#include "Time/FpsCounter.h"
#include "Input/InputManager.h"
#include "Rendering/RenderingManager.h"
#include "Physics/PhysicsManager.h"
#include "Shaders/ShaderManager.h"
#include "Scene/Scene.h"
#include "Scene/EntityManager.h"
#include "Scene/SceneManager.h"
#include "Components/Components.h"
#include "MeshData/Shapes.h"

namespace Stylite
{
	
	class Application;
	class Engine
	{
	public:
		STYLITE_API void Initialize();
		STYLITE_API void Shutdown();

		STYLITE_API void RegisterApplication(Application* _application);
		STYLITE_API void SetFpsCounter(bool state);

		// Config Options
		STYLITE_API void SetAntiAliasing(bool state);
		STYLITE_API void SetMutlisamplingSamples(int samples);
		STYLITE_API void SetWireframe(bool state);

		STYLITE_API bool IsRunning();
		STYLITE_API void Start();

	private:
		bool m_running = false;
		Application*		m_application;

		Display*			m_Display;
		FpsCounter*			m_FpsCounter;
		InputManager*		m_InputManager;
		RenderingManager*	m_RenderingManager;
		ShaderManager*		m_ShaderManager;
		PhysicsManager*		m_PhysicsManager;

		void Update();
	};
}
