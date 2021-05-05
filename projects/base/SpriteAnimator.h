#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class SpriteAnimator
{
private:
	sf::Texture* spriteSheetTexture;
	sf::Sprite spriteSheet;
	sf::Clock clock;

	sf::Vector2i currentFrame;
	sf::Vector2i startFrame;
	sf::Vector2i endFrame;
	int speed;
	bool startAnimation = false;

public:
	SpriteAnimator();
	~SpriteAnimator();

	void Init();
	void Load(std::string filename);
	void Update();
	void Render(sf::RenderWindow& window);

	void StartAnimation(sf::Vector2i startFrame, sf::Vector2i endFrame, int speed);
};