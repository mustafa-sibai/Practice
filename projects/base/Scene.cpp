#include "Scene.h"

Scene::Scene() : 
	isRunning(false), isLoaded(false)
{
}

Scene::~Scene()
{
}

void Scene::Init()
{
}

void Scene::Load()
{
	isLoaded = true;
	isRunning = true;
	std::cout << "Scene was loaded" << std::endl;
}

void Scene::Update()
{
	std::cout << "I am a scnee updating" << std::endl;
}

void Scene::Render(sf::RenderWindow& window)
{
	std::cout << "I am a scnee" << std::endl;
}