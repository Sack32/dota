#include "animation.h"


animation::animation(sf::Texture* texture, sf::Vector2u imagecunt):
	imageCount(imagecunt)
{
	curImage.x = 0;

	uvRect.width = texture->getSize().x / (imageCount.x);
	uvRect.height = texture->getSize().y / (imageCount.y);
}

animation::animation()
{
	curImage.x = 0;
}




void animation::Update(int row)
{
	curImage.y = row;
	curImage.x++;
	if (!(curImage.x < imageCount.x))
		curImage.x = 0;


	uvRect.left = uvRect.width*curImage.x;
	uvRect.top = uvRect.height*curImage.y;
}

void animation::Update()
{
	curImage.x = 0;
	//if (!(curImage.x < imageCount.x))
	//	curImage.x = 0;


	uvRect.left = uvRect.width*curImage.x;
	uvRect.top = uvRect.height*curImage.y;
}