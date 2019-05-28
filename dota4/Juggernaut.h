#pragma once
#include "Hero.h"
class Juggernaut :
	public Hero
{
public:
	Juggernaut(sf::Texture* text, sf::Vector2u imgcunt, float speed, sf::Vector2f initPosi);
	Juggernaut(sf::Vector2f initPosi);
	
	~Juggernaut();
};

