#pragma once
#include "BulletScript.h"

class PlayerScript : public ScriptComponent
{
public:
	PlayerScript(Entity* firstAsteroid);

	void OnUpdate();
	std::vector<Entity*> asteroids;

	~PlayerScript();

private:
	void ProcessMovement();
	void SpawnBullet();
	Entity* CreateBullet();
	void CheckCollisionWithAsteroids();
	void CheckHealth();

	float playerSpeed = 500.0f;
	float playerTurnSpeed = 300.0f;
	Texture normalTexture;
	Texture acceleratingTexture;
	int health = 3;

	Mesh bulletMesh;
	int reloadTime = 20;
	float bulletSpeed = 700.0f;
	int timeUntilNextShot = reloadTime;
};

