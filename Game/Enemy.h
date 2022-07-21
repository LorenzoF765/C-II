#pragma once
#include "Framework/Actor.h"

class Enemy : public Solas::Actor
{
public:
	Enemy() = default;
	Enemy(const Solas::Model& model, const Solas::Transform& transform) : Actor{ model, transform } {}

	void Update() override;

private:

	float speed_ = 50;

};