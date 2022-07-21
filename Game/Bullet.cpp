#include "Bullet.h"
#include "Engine.h"

void Bullet::Update()
{
	// Calculate Velocity

	Solas::Vector2 direction{ 1,0 };
	direction = Solas::Vector2::Rotate(direction, transform_.rotation);

	Solas::Vector2 velocity = direction * (speed_ * Solas::timer_g.deltaTime);

	transform_.position += velocity;

}
