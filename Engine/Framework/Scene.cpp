#include "Scene.h"

namespace Solas
{
	void Scene::Update()
	{
		for (auto& actor : actors_)
		{
			actor->Update();
		}
	}
	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : actors_)
		{
			actor->Draw(renderer);
		}
	}
	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->scene_ = this;
		actors_.push_back(std::move(actor));
	}
}