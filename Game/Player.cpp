#include "Player.h"
#include "Engine.h"

void Player::Update()
{

	// Rotate Left/Right
	if (Solas::inputSystem_g.GetKeyState(Solas::key_left) == Solas::InputSystem::KeyState::Held)
	{
		transform_.rotation -= (0.05f * Solas::timer_g.deltaTime);
	}

	if (Solas::inputSystem_g.GetKeyState(Solas::key_right) == Solas::InputSystem::KeyState::Held)
	{
		transform_.rotation += (0.05f * Solas::timer_g.deltaTime);
	}

	// Move Forward
	float thrust = 0;
	if (Solas::inputSystem_g.GetKeyState(Solas::key_up) == Solas::InputSystem::KeyState::Held)
	{
		speed_ = maxSpeed_;
	}

	// Mouse

	//if (Engine::inputSystem_g.GetButtonState(Engine::button_left) == Engine::InputSystem::KeyState::Pressed)
	//{
	//	std::cout << "Left Mouse Click!" << endl;
	//}

	//if (Engine::inputSystem_g.GetButtonState(Engine::button_right) == Engine::InputSystem::KeyState::Pressed)
	//{
	//	std::cout << "Mouse Position: (" << Engine::inputSystem_g.GetMousePosition().x << ", " << inputSystem.GetMousePosition().y << ")" << endl;
	//}

	// Face Target
	Solas::Vector2 target = Solas::inputSystem_g.GetMousePosition();
	target = target - transform_.position; // Direction Vector Towards
	transform_.rotation = target.GetAngle();

	// Thrust Code
	Solas::Vector2 direction{ 1,0 };
	direction = Solas::Vector2::Rotate(direction, transform_.rotation);

	Solas::Vector2 velocity = direction * (speed_ * Solas::timer_g.deltaTime);

	transform_.position += velocity;
}
