#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Scene
{
private:
	bool isRunning;
	bool isLoaded;

public:
	Scene();
	~Scene();

	virtual void Init();
	virtual void Load();
	virtual void Update();
	virtual void Render(sf::RenderWindow& window);

	inline bool IsLoaded() { return isLoaded; }
};