#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include "Hero.h"
#include "Juggernaut.h"
#include "Girl.h"


int main()
{
	std::cout<<"Right click to move to that position";
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Dota4", sf::Style::Close | sf::Style::Titlebar);
	
	//window.setFramerateLimit(60);

	//sf::Texture juggTex;
	//juggTex.loadFromFile("jugg.png");
	//Hero Juggernaut(&juggTex, sf::Vector2u(4, 4),10.0f, sf::Vector2f(100.0f,100.0f));
	
	Juggernaut juggernaut(sf::Vector2f(100.0f,100.0f));
	Girl hero2(sf::Vector2f(200.0f, 100.0f));
	std::cout <<sf::Texture::getMaximumSize();
	
	
	
	sf::Clock clock;

	sf::Font font;
	if (!font.loadFromFile("consola.ttf"))
	{
		std::cout << "error loading font";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Right click to move to that position");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Cyan);
	text.setStyle(sf::Text::Bold);


	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event vent{};

		while (window.pollEvent(vent))
		{
			switch (vent.type)
			{

			case sf::Event::Closed:
				window.close();//todo: sure u want to quit?
				break;
			default: ;
			}
		}


	
		

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
		window.clear(sf::Color(10,155,50));
		window.draw(text);
		juggernaut.update(deltaTime, window);
		juggernaut.draw(window);
		hero2.update(deltaTime,window);
		hero2.draw(window);
	
		
		window.display();


	}
	return 0;
}
