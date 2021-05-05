#include "Level1.h"

Level1::Level1()
{
}

Level1::~Level1()
{
}

void Level1::Init()
{
}

void Level1::Load()
{
	Scene::Load();
	std::cout << "leve 1 loading" << std::endl;
}

void Level1::Update()
{
	std::cout << "This is the first level update function" << std::endl;

	Scene::Update();
}

void Level1::Render(sf::RenderWindow& window)
{
	std::cout << "This is the first level render function" << std::endl;

	Scene::Render(window);
}