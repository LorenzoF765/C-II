#include "Enemy.h"
#include "Engine.h"

void Enemy::Update()
{
	// Calculate Velocity

	Solas::Vector2 direction{ 1,0 };
	direction = Solas::Vector2::Rotate(direction, transform_.rotation);

	Solas::Vector2 velocity = direction * (speed_ * Solas::timer_g.deltaTime);

	transform_.position += velocity;

	// Screen Wrapping
	if (transform_.position.x > Solas::renderer_g.GetWidth_()) transform_.position.x = 0;
	if (transform_.position.x < 0) transform_.position.x = Solas::renderer_g.GetWidth_();

	if (transform_.position.y > Solas::renderer_g.GetHeight_()) transform_.position.y = 0;
	if (transform_.position.y < 0) transform_.position.y = Solas::renderer_g.GetHeight_();
}
