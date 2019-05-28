#include "Hero.h"


Hero::Hero(sf::Texture* text, sf::Vector2u imgcunt, float speed, sf::Vector2f initPosi) :anime(text, imgcunt),movespd(speed)
{
	body.setTexture(text);
	body.setSize(sf::Vector2f(text->getSize().x / imgcunt.x, text->getSize().y / imgcunt.y));
	body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	body.setPosition(initPosi);
	body.setTextureRect(sf::IntRect(0, 0, body.getSize().x, body.getSize().y));
	totalTime = 0.0f;
	dest = initPosi;
	st = 4.0f/(movespd*imgcunt.x);
}

Hero::Hero(sf::Vector2f initPosi)
{
	body.setPosition(initPosi);
} 

Hero::~Hero() = default;


void Hero::draw(sf::RenderWindow& win)
{
	win.draw(body);
}

void Hero::update(float& deltatime, const sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		dest.x = static_cast<float>(sf::Mouse::getPosition(window).x);
		dest.y = static_cast<float>(sf::Mouse::getPosition(window).y);
	}
	totalTime += deltatime;

	if (totalTime > st) {
		totalTime -= st;

		diffVect = dest - body.getPosition();

		if (!((diffVect.x == diffVect.y) && (diffVect.y == 0)))
			movement = movespd * diffVect / std::sqrt(diffVect.x * diffVect.x + diffVect.y * diffVect.y);

		if ((abs(diffVect.x) < movespd) && (abs(diffVect.y) < movespd)) 
			movement = sf::Vector2f(0.0f, 0.0f);
		

		std::cout << movement.x << ", " << movement.y << '\n';




		if (body.getPosition().x < -30)
			body.setPosition(1080 + 30, body.getPosition().y);
		if (body.getPosition().x > (1080 + 30))
			body.setPosition(-30, body.getPosition().y);
		if (body.getPosition().y < -30)
			body.setPosition(body.getPosition().x, 720 + 30);
		if (body.getPosition().y > 720 + 30)
			body.setPosition(body.getPosition().x, -30);

		if (abs(movement.x) > abs(movement.y))
		{
			if (movement.x > 0)
				anime.Update(2);
			else
				anime.Update(1);
		}

		else if (abs(movement.x) < abs(movement.y)) {
			if (movement.y > 0)
				anime.Update(0);
			else
				anime.Update(3);
		}
		else
			anime.Update();



		body.move(movement);
		body.setTextureRect(anime.uvRect);
	}
}

