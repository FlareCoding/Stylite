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

		SetupScene();
		StartTime = Time::GetTime();
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

		double CurrentTime = Time::GetTime();
		if (CurrentTime - StartTime > 2)
		{
			StartTime = CurrentTime;
			if (Time::TimeScale > 0) SpawnAsteroid();
		}
	}

	~Game() {}

private:
	Scene* m_MainScene;
	Entity* player;
	Entity* asteroid;
	Mesh mesh;
	Texture spaceship_texture;
	int msg = 0;
	double StartTime;

	void SpawnAsteroid()
	{
		Mesh asteroidMesh = Shapes::Circle(120, 9);
		Texture asteroidTexture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\asteroid.png", ClampToBorder);
		asteroidTexture.transparent = true;

		asteroid = CreateEntity(new RenderComponent(asteroidMesh, &asteroidTexture), vec3(RandomFloat(200, 1000), RandomFloat(100, 1000), -1), 0);
		asteroid->name = "Asteroid";
		asteroid->AddComponent<ShaderComponent>(new ShaderComponent(_TextureShader));
		asteroid->AddComponent<ScriptComponent>(new AsteroidScript());
		asteroid->AddComponent<RigidBodyComponent>(new RigidBodyComponent());
		AddEntityToScene(asteroid, m_MainScene);
		if (player) static_cast<PlayerScript*>(player->GetComponent<ScriptComponent>())->asteroids.push_back(asteroid);

		Physics::ApplyForce(asteroid->GetComponent<RigidBodyComponent>(), vec2(0.2f, 0.2f), 160.0f);
	}

	void SetupScene()
	{
		m_MainScene = CreateScene();
		SpawnAsteroid();

		mesh = Shapes::Rectangle(160, 156);
		spaceship_texture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\spaceship.png", ClampToBorder);
		spaceship_texture.transparent = true;

		player = CreateEntity();
		player->name = "Player";
		player->AddComponent<RenderComponent>(new RenderComponent(mesh, &spaceship_texture));
		player->AddComponent<ShaderComponent>(new ShaderComponent(_TextureShader));
		player->AddComponent<ScriptComponent>(new PlayerScript(asteroid));
		player->AddComponent<RigidBodyComponent>(new RigidBodyComponent());
		player->transform->position = vec3(400, 300, 0);

		AddEntityToScene(player, m_MainScene);
		SetActiveScene(m_MainScene);
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
