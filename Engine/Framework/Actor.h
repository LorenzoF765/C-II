#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace Solas
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : GameObject{ transform }, model_{ model }  {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		Scene* scene_ = nullptr;
	private:

	protected:
		Model model_;

	};
}
