#include "PlayerScript.h"

PlayerScript::PlayerScript()
{
	normalTexture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\spaceship.png", ClampToBorder);
	normalTexture.transparent = true;

	acceleratingTexture = CreateTexture("C:\\Users\\FlareFlax\\Desktop\\spaceshipAccelerating.png", ClampToBorder);
	acceleratingTexture.transparent = true;
}

PlayerScript::~PlayerScript()
{
}

void PlayerScript::ProcessMovement()
{
	if (Keyboard::IsKeyDown(Keyboard::KEY_W))
	{
		owner->GetComponent<RenderComponent>()->texture = acceleratingTexture;
		Physics::ApplyForce(owner->GetComponent<RigidBodyComponent>(), owner->transform->GetDirectionVector(), playerSpeed * (float)Time::GetDeltaTime());
	}
	else
		owner->GetComponent<RenderComponent>()->texture = normalTexture;

	if (Keyboard::IsKeyDown(Keyboard::KEY_S)) Physics::ApplyForce(owner->GetComponent<RigidBodyComponent>(), owner->transform->GetDirectionVector() * -1, (playerSpeed / 2) * (float)Time::GetDeltaTime());

	// rotation
	if (Keyboard::IsKeyDown(Keyboard::KEY_LEFT))
		owner->transform->rotation += (float)Time::GetDeltaTime() * playerTurnSpeed;

	if (Keyboard::IsKeyDown(Keyboard::KEY_RIGHT))
		owner->transform->rotation -= (float)Time::GetDeltaTime() * playerTurnSpeed;
}

void PlayerScript::SpawnBullet()
{
	Entity* bullet = CreateBullet();
	vec2 direction = owner->transform->GetDirectionVector();
	
	Physics::ApplyForce(bullet->GetComponent<RigidBodyComponent>(), direction, bulletSpeed);

	AddEntityToScene(bullet);
}

Entity* PlayerScript::CreateBullet()
{
	bulletMesh = Shapes::Circle(10, 3);
	Entity* bullet = CreateEntity(new RenderComponent(bulletMesh, nullptr), owner->transform->position, owner->transform->rotation);

	bullet->AddComponent<RigidBodyComponent>(new RigidBodyComponent());
	bullet->AddComponent<ScriptComponent>(new BulletScript());

	return bullet;
}

void PlayerScript::OnUpdate()
{
	ProcessMovement();

	if (timeUntilNextShot > 0) timeUntilNextShot--;

	if (Keyboard::IsKeyDown(Keyboard::KEY_SPACE))
	{
		if (timeUntilNextShot == 0) 
		{
			SpawnBullet();
			timeUntilNextShot = reloadTime;
		}
	}
}
