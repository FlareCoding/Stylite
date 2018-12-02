#pragma once
#include "BulletScript.h"

class PlayerScript : public ScriptComponent
{
public:
	PlayerScript();

	void OnUpdate();

	~PlayerScript();

private:
	void ProcessMovement();
	void SpawnBullet();
	Entity* CreateBullet();
	float playerSpeed = 500.0f;
	float playerTurnSpeed = 300.0f;
	Texture normalTexture;
	Texture acceleratingTexture;

	Mesh bulletMesh;
	int reloadTime = 20;
	float bulletSpeed = 700.0f;
	int timeUntilNextShot = reloadTime;
};

