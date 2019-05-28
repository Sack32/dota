#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "animation.h"

class Hero
{
public:
	Hero(sf::Texture* text, sf::Vector2u imgcunt, float speed , sf::Vector2f initPosi);
	 Hero(sf::Vector2f initPosi);
	~Hero();
protected:
	sf::Texture text;
	sf::RectangleShape body;
	animation anime;
	sf::Vector2f movement;
	sf::Vector2f diffVect;
	sf::Vector2f dest;
	sf::Vector2u imageCount;
	float totalTime;
	float st;
	float movespd;

public:
	void draw(sf::RenderWindow&);
	void update(float& deltatime,const sf::RenderWindow&);
};

