#include "example.h"
#include "SaveLoad.h"
#include "Scenes/MainMenu.h"
#include "Scenes/Level1.h"

using namespace sf;
using namespace std;

Example::Example() : App()//, grid()
{
}

Example::~Example()
{
}

Example& Example::inst()
{
	static Example s_instance;
	return s_instance;
}

bool Example::start()
{
	/*m_backgroundSprite = kage::TextureManager::getSprite("data/sky.jpg");
	Vector2u resolution = m_backgroundSprite->getTexture()->getSize();
	m_backgroundSprite->setScale(float(m_window.getSize().x) / resolution.x, float(m_window.getSize().y) / resolution.y);

	normalCatTexture = kage::TextureManager::getTexture("data/cat.png");
	blueCatTexture = kage::TextureManager::getTexture("data/cat1.png");
	redCatTexture = kage::TextureManager::getTexture("data/cat2.png");

	SetTilesFromMap();

	spriteAnimator.Init();
	spriteAnimator.Load("data/SpriteSheet.png");
	spriteAnimator.StartAnimation(sf::Vector2i(0, 3), sf::Vector2i(11, 3), 500);
	*/

	sceneManager.AddScene(new MainMenu());
	sceneManager.AddScene(new Level1());

	sceneManager.Load();

	return true;
}

/*void Example::SetTilesFromMap()
{
	for (size_t y = 0; y < 4; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			int i = x + y * 5;

			tiles[i].setPosition(sf::Vector2f(
				GRID_OFFSET_X + x * CELL_WIDTH,
				GRID_OFFSET_Y + y * CELL_HEIGHT));

			if (map[i] == 1)
			{
				tiles[i].setTexture(*normalCatTexture);
			}

			if (map[i] == 2)
			{
				tiles[i].setTexture(*blueCatTexture);
			}

			if (map[i] == 3)
			{
				tiles[i].setTexture(*redCatTexture);
			}
		}

		std::cout << "\n";
	}
}*/

//char stringggg[24] = { 0 };

void Example::update(float deltaT)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && m_window.hasFocus())
	{
		m_running = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		sceneManager.LoadScene(0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		sceneManager.LoadScene(1);
	}

	sceneManager.Update();

	/*ImGui::Begin("Kage2D");

	ImGui::InputText("FileName", stringggg, IM_ARRAYSIZE(stringggg));

	if (ImGui::Button("Exit"))
	{
		m_running = false;
	}
	if (ImGui::ImageButton(*normalCatTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 1;
	}
	if (ImGui::ImageButton(*blueCatTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 2;
	}
	if (ImGui::ImageButton(*redCatTexture, sf::Vector2f(56, 56)))
	{
		chosenTileId = 3;
	}
	if (ImGui::Button("Save"))
	{
		SaveLoad::Save("map.txt", map, 5, 4);
	}
	if (ImGui::Button("Load"))
	{
		SaveLoad::Load("map.txt", map, 20, *this);
		SetTilesFromMap();
	}
	ImGui::End();

	sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
		mousePosition.x >= 0 && mousePosition.x <= 280 &&
		mousePosition.y >= 0 && mousePosition.y <= 224)
	{
		int mouseOnCellX = mousePosition.x / CELL_WIDTH;
		int mouseOnCellY = mousePosition.y / CELL_HEIGHT;

		int i = mouseOnCellX + mouseOnCellY * 5;

		if (chosenTileId == 1)
		{
			tiles[i].setTexture(*normalCatTexture);
			map[i] = 1;
		}

		if (chosenTileId == 2)
		{
			tiles[i].setTexture(*blueCatTexture);
			map[i] = 2;
		}

		if (chosenTileId == 3)
		{
			tiles[i].setTexture(*redCatTexture);
			map[i] = 3;
		}
	}

	spriteAnimator.Update();*/
}

void Example::render()
{
	/*m_window.draw(*m_backgroundSprite);

	for (size_t i = 0; i < 20; i++)
		m_window.draw(tiles[i]);

	grid.Draw(m_window);

	spriteAnimator.Render(m_window);*/

	sceneManager.Render(m_window);
}

void Example::cleanup()
{
	//delete m_backgroundSprite;
}