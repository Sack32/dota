#include "Juggernaut.h"



Juggernaut::Juggernaut(sf::Vector2f initPosi):Hero(initPosi)
{
	imageCount = sf::Vector2u(4, 4);
	text.loadFromFile("jugg.png");
	anime = animation(&text, imageCount);
	body.setTexture(&text);
	body.setSize(sf::Vector2f(text.getSize().x / imageCount.x, text.getSize().y / imageCount.y));
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setTextureRect(sf::IntRect(0, 0, body.getSize().x, body.getSize().y));
	totalTime = 0.0f;
	dest = sf::Vector2f(initPosi);
	movespd = 10.0f;
	st = 1.0f / movespd;

}


Juggernaut::Juggernaut(sf::Texture * text, sf::Vector2u imgcunt, float speed, sf::Vector2f initPosi): Hero(initPosi)
{
}

Juggernaut::~Juggernaut()
{
}
