#pragma once
#include "Scene.h"

class MainMenu : public Scene
{
public:
	MainMenu();
	~MainMenu();

	void Init() override;
	void Load() override;
	void Update() override;
	void Render(sf::RenderWindow& window);
};