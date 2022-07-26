#include "Player.h"
#include "Enemy.h"
#include "Engine.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <Framework/Scene.h>

using namespace std;
// DEPENDENCIES

int main()
{
	//Memory Init
	Solas::initializeMemory();

	// Set File Path to Pull Models
	Solas::setFilePath("../Assets");

	Solas::Scene scene;

	// Create Actor
	// Transform
	Solas::Transform transform;
	transform.position = { 400, 300 };
	transform.rotation = 0;
	transform.scale = 5;

	// Model
	vector<Solas::Vector2> points
	{
		{ 7.00f, 0.00f },
		{ -3.00f, -5.00f },
		{ 0.00f, 0.00f },
		{ -3.00f, 5.00f },
		{ 7.00f, 0.00f }

	};
	//Engine::Model model(points, Engine::Color{ 255, 255, 255, 255 });


	std::unique_ptr<Player> player = std::make_unique<Player>(Solas::Model{ "Player.txt" }, transform);
	scene.Add(std::move(player));
/*
	for (size_t i = 0; i < 5; i++)
	{
		transform.position.x = Solas::Randomf(800);
		transform.position.y = Solas::Randomf(600);
		std::unique_ptr<Enemy> player = std::make_unique<Enemy>(Solas::Model{ "Enemy.txt" }, transform);
		scene.Add(std::move(player));

	}
*/
	// Player player{ model, transform };


	// Initialize Our Major Systems
	Solas::renderer_g.Initialize();
	Solas::inputSystem_g.Initialize();

	// Create A Window And Set Background Color
	Solas::renderer_g.CreateWindow("Solas", 800, 600); // Creates the window with parameters
	Solas::renderer_g.SetClearColor(Solas::Color{ 50, 50, 50, 255 });

	bool quit = false;
	while (!quit)
	{
		// Update
		Solas::inputSystem_g.Update();
		Solas::timer_g.Tick();

		//Keys
		if (Solas::inputSystem_g.GetKeyState(Solas::key_esc) == Solas::InputSystem::KeyState::Pressed)
		{
			quit = true;
		}

		//Update Game Objects
		scene.Update();

		// Render
		Solas::renderer_g.BeginFrame();

		scene.Draw(Solas::renderer_g);
		//player.Draw(Engine::renderer_g);

		Solas::renderer_g.EndFrame();
	}

	Solas::renderer_g.ShutDown();
}
