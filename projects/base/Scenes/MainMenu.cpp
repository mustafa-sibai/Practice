#include "MainMenu.h"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
}

void MainMenu::Load()
{
	Scene::Load();
	std::cout << "main 1 loading" << std::endl;
}

void MainMenu::Update()
{
	std::cout << "This is the main menu update function" << std::endl;

	Scene::Update();
}

void MainMenu::Render(sf::RenderWindow& window)
{
	std::cout << "This is the main menu render function" << std::endl;

	Scene::Render(window);
}