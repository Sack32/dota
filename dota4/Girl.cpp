#include "Girl.h"



Girl::Girl(sf::Vector2f initPosi):Hero(initPosi)
{
	imageCount = sf::Vector2u(8, 4);
	text.loadFromFile("girl.png");
	anime = animation(&text, imageCount);
	body.setTexture(&text);
	body.setSize(sf::Vector2f(text.getSize().x / imageCount.x, text.getSize().y / imageCount.y));
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setTextureRect(sf::IntRect(0, 0, body.getSize().x, body.getSize().y));
	totalTime = 0.0f;
	dest = sf::Vector2f(initPosi);
	movespd = 15.0f;
	st = 1.0f / movespd;
}


Girl::~Girl()
{
}
