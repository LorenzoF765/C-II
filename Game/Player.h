#pragma once
#include "Framework/Actor.h"
#include "Renderer/Model.h"
#include "Math/Transform.h"

class Player : public Solas::Actor
{
public:
	Player() = default;
	Player(const Solas::Model& model, const Solas::Transform& transform) : Actor(model, transform) {}

	void Update() override;

private:
	float speed_{ 0 };
	float maxSpeed_{ 100 };
};

