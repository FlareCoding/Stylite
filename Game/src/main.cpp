#include <Stylite.h>
#include <string>

// Scripts
#include "Scripts/PlayerScript.h"
#include "Scripts/AsteroidScript.h"

using namespace Stylite;

class Game : public Stylite::Application
{
public:
	Game() {}

	void Initialize()
	{
		engine = new Engine();
		engine->SetAntiAliasing(true);
		engine->SetMutlisamplingSamples(16);
		engine->Initialize();
		engine->SetFpsCounter(true);

		SetupScene();
	}

	void Shutdown()
	{
		DeleteAllScenes();
		DeleteAllEntities();
		engine->Shutdown();
		delete engine;
	}

	void Update()
	{
		std::string input;
		getline(std::cin, input);
		if (input._Equal("remove"))
			msg = 1;
		else if (input._Equal("add"))
			msg = 2;
		else if (input._Equal("wireframe 1"))
			msg = 3;
		else if (input._Equal("wireframe 0"))
			msg = 4;
	}

	void EngineUpdate()
	{
		if (msg == 3) engine->SetWireframe(true);
		if (msg == 4) engine->SetWireframe(false);

		if (msg != 0) msg = 0;

		std::cout << m_MainScene->GetEntities().size() << " entities in the scene\n";
	}

	~Game() {}

private:
	Scene* m_MainScene;
	Entity* entity;
	Mesh mesh;
	Texture spaceship_texture;
	int msg = 0;

	void SpawnAsteroid()
	{
		Mesh asteroidMesh = Shapes::Circle(120, 9);
		Texture asteroidTexture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\asteroid.png", ClampToBorder);
		asteroidTexture.transparent = true;

		Entity* asteroid = CreateEntity(new RenderComponent(asteroidMesh, &asteroidTexture), vec3(600, 600, 0), 0);
		asteroid->AddComponent<ShaderComponent>(new ShaderComponent(_TextureShader));
		asteroid->AddComponent<ScriptComponent>(new AsteroidScript());
		asteroid->AddComponent<RigidBodyComponent>(new RigidBodyComponent());
		AddEntityToScene(asteroid);

		Physics::ApplyForce(asteroid->GetComponent<RigidBodyComponent>(), vec2(0.2f, 0.2f), 40.0f);
	}

	void SetupScene()
	{
		m_MainScene = CreateScene();

		mesh = Shapes::Rectangle(160, 156);
		spaceship_texture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\spaceship.png", ClampToBorder);
		spaceship_texture.transparent = true;

		entity = CreateEntity();
		entity->AddComponent<RenderComponent>(new RenderComponent(mesh, &spaceship_texture));
		entity->AddComponent<ShaderComponent>(new ShaderComponent(_TextureShader));
		entity->AddComponent<ScriptComponent>(new PlayerScript());
		entity->AddComponent<RigidBodyComponent>(new RigidBodyComponent());
		entity->transform->position = vec3(400, 300, 0);

		AddEntityToScene(entity, m_MainScene);
		SetActiveScene(m_MainScene);

		SpawnAsteroid();
	}
};

int main()
{
	Game* game = new Game();
	game->Initialize();
	game->Run();
	delete game;

	return 0;
}
