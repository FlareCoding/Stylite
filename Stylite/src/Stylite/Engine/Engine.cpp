#include "Engine.h"
#include "../Application.h"
#include "Math/Vector/Vector.h"
#include "Shaders/IShader.h"

namespace Stylite
{
	STYLITE_API void Engine::Initialize()
	{
		m_Display			=	new Display();
		m_FpsCounter		=	new FpsCounter();
		m_InputManager		=	new InputManager(m_Display);
		m_RenderingManager	=	new RenderingManager();
		m_ShaderManager		=	new ShaderManager();
		m_PhysicsManager	=	new PhysicsManager();

		m_Display->CreateDefaultDisplay();
		m_RenderingManager->Initialize(m_Display);
		m_ShaderManager->Initialize();
		m_PhysicsManager->Initialize();
	}

	STYLITE_API bool Engine::IsRunning()
	{
		return m_running;
	}

	STYLITE_API void Engine::Shutdown()
	{
		m_PhysicsManager->Shutdown();
		m_ShaderManager->Shutdown();
		m_RenderingManager->Shutdown();
		m_Display->Destroy();

		delete m_PhysicsManager;
		delete m_ShaderManager;
		delete m_RenderingManager;
		delete m_InputManager;
		delete m_FpsCounter;
		delete m_Display;
	}

	STYLITE_API void Engine::RegisterApplication(Application* _application)
	{
		this->m_application = _application;
	}

	STYLITE_API void Engine::SetFpsCounter(bool state)
	{
		this->m_FpsCounter->bEnabled = state;
	}

	STYLITE_API void Engine::SetAntiAliasing(bool state)
	{
		Settings::OpenGL::AntiAliasing = state;
	}

	STYLITE_API void Engine::SetMutlisamplingSamples(int samples)
	{
		Settings::OpenGL::MSAASamples = samples;
	}

	STYLITE_API void Engine::SetWireframe(bool state)
	{
		m_RenderingManager->SetWireframe(state);
	}
	
	void Engine::Start()
	{
		m_running = true;

		while (m_Display->IsOpened())
			Update();

		m_running = false;
	}

	void Engine::Update()
	{
		m_InputManager->Update();
		m_RenderingManager->Update();

		Scene* active_scene = GetActiveScene();
		if (active_scene)
		{
			for (Entity* e : active_scene->GetEntities())
			{
				// physics corrections / calculations
				m_PhysicsManager->NormalizeEntityRotation(e);
				auto* rigid_body_component = e->GetComponent<RigidBodyComponent>();
				if (rigid_body_component) m_PhysicsManager->ApplyRigidProperties(e, rigid_body_component);

				// scripts / behaviors
				auto* script_component = e->GetComponent<ScriptComponent>();
				if (script_component)
					script_component->OnUpdate();

				// rendering / graphics
				auto* render_component = e->GetComponent<RenderComponent>();
				if (render_component != nullptr)
				{
					ShaderComponent* shader_component = e->GetComponent<ShaderComponent>();
					m_RenderingManager->Render(render_component, (shader_component != nullptr) ? m_ShaderManager->GetShader(shader_component->shader_type) : m_ShaderManager->GetShader(_BasicShader));
				}
			}
		}

		m_Display->Update();
		Time::FrameUpdate();
		
		if (m_FpsCounter->bEnabled)
		{
			m_FpsCounter->Update();
			m_Display->SetWindowTitle((Settings::Display::DisplayTitle + std::string("   FPS: ") + std::to_string(m_FpsCounter->m_FramesPerSecond)).c_str());
		}

		// updating the application layer
		if (this->m_application)
			m_application->EngineUpdate();
	}
}