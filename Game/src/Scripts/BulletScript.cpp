#include "BulletScript.h"

BulletScript::BulletScript()
{
	startTime = Time::GetTime();
}

BulletScript::~BulletScript()
{
}

void BulletScript::OnUpdate()
{
	currentTime = Time::GetTime();
	owner->transform->rotation += 1;

	if (currentTime - startTime > lifeTime)
	{
		RemoveEntityFromScene(owner);
		DeleteEntity(owner);
		return;
	}
}
