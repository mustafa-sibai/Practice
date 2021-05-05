#include "SpriteAnimator.h"
#include <kage2dutil/texture_manager.h>

#define SPRITE_WIDTH 80
#define SPRITE_HEIGHT 80

using namespace sf;

SpriteAnimator::SpriteAnimator() :
	spriteSheetTexture(nullptr)
{
}

SpriteAnimator::~SpriteAnimator()
{
}

void SpriteAnimator::Init()
{
}

void SpriteAnimator::Load(std::string filename)
{
	spriteSheetTexture = kage::TextureManager::getTexture(filename);
	spriteSheet.setTexture(*spriteSheetTexture);
	spriteSheet.setTextureRect(IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
}

void SpriteAnimator::Update()
{
	if (startAnimation) {
		Time timer = clock.getElapsedTime();

		if (timer.asMilliseconds() > speed)
		{
			int x = SPRITE_WIDTH * currentFrame.x;
			int y = SPRITE_HEIGHT * currentFrame.y;

			spriteSheet.setTextureRect(IntRect(x, y, SPRITE_WIDTH, SPRITE_HEIGHT));
			currentFrame.x++;

			if (currentFrame.x > endFrame.x) {
				currentFrame = startFrame;
			}
			clock.restart();
		}
	}
}

void SpriteAnimator::Render(RenderWindow& window)
{
	window.draw(spriteSheet);
}

void SpriteAnimator::StartAnimation(Vector2i startFrame, Vector2i endFrame, int speed)
{
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->speed = speed;

	startAnimation = true;
	currentFrame = startFrame;
}