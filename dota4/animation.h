#pragma once
#include <SFML/Graphics.hpp>

class animation
{
public:
	animation(sf::Texture* texture, sf::Vector2u imagecunt);
	animation();
	
	~animation()=default;

	void Update(int row);
	void Update();




private:
	sf::Vector2u imageCount;
	sf::Vector2u curImage;



public:
	sf::IntRect uvRect;
};

