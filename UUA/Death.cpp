#include "pch.h"
#include "Death.h"
#include "Game.h"

Death::Death()
{
	text1.setFont(Game::font);
	text1.setScale(sf::Vector2f(2.0f, 2.0f));
	text2.setFont(Game::font);
	text2.setScale(sf::Vector2f(2.0f, 2.0f));
	offsetX = 60.0f; offsetY = 10.0f;
	t.loadFromFile("Images/x.png");
	over.loadFromFile("Images/gameover.png");
	gOver.setTexture(over);
	opts[0].loadFromFile("Images/Button.png");
	opts[1].loadFromFile("Images/Button2.png");
	options[0].setTexture(opts[0]);
	options[1].setTexture(opts[0]);
	options[2].setTexture(opts[0]);
	deathBar.setTexture(t);
	deathBar.setPosition(0.5f*(WIDTH - deathBar.getTextureRect().width), 0.5f*(HEIGHT - deathBar.getTextureRect().height));
	text1.setPosition(sf::Vector2f(deathBar.getPosition()+sf::Vector2f(offsetX,offsetY)));
	text2.setPosition(sf::Vector2f(deathBar.getPosition() + sf::Vector2f(offsetX, offsetY+70.0f)));
	tx.loadFromFile("Images/text3.png");
	txt.setTexture(tx);
	txt.setPosition(deathBar.getPosition());
	for(int i=0;i<3;i++)
	options[i].setPosition(deathBar.getPosition() + sf::Vector2f(offsetX, offsetY + 200.0f + 100.0f*i));
	gOver.setPosition(deathBar.getPosition() + sf::Vector2f(25.0f, -110.0f));
}

void Death::Draw(sf::RenderWindow& window)
{
	window.draw(deathBar);
	for (int i = 0; i < 3; i++)
		window.draw(options[i]);
	window.draw(txt);
	window.draw(gOver);
	window.draw(text1);
	window.draw(text2);
}
void Death::Update()
{
	text1.setString(("Score: " + Marshmellow::numToString(Game::score)).c_str());
	text2.setString((" Coin: " + Marshmellow::numToString(Game::coinCount)).c_str());
	static int mouseFlag = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseFlag == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			if (Mouse::Intersect(options[i].getPosition().x, options[i].getPosition().y,(float)options[i].getTextureRect().width,(float)options[i].getTextureRect().height) )
			{
				options[i].setTexture(opts[1]);
				mouseFlag = i + 1;
				break;
			}
			
		}
	}

	if (Game::event.type == sf::Event::MouseButtonReleased && mouseFlag!=0 )
	{
		if (Mouse::Intersect(options[mouseFlag - 1].getPosition().x, options[mouseFlag - 1].getPosition().y, (float)options[mouseFlag - 1].getTextureRect().width, (float)options[mouseFlag - 1].getTextureRect().height))
		{
			if (mouseFlag == 1)
			{
				Game::gameState = Game::Playing;

			}
			else if (mouseFlag == 2) {Game::gameState = Game::Menu;}
			else if (mouseFlag == 3)
			{
				Game::gameState = Game::Exiting;
			}
		}
		options[mouseFlag-1].setTexture(opts[0]);
		mouseFlag = 0;
	}
}

bool Mouse::Intersect(float x,float y,float w,float h)
{
	sf::Vector2i mouse = sf::Vector2i(int(sf::Mouse::getPosition(Game::window).x*float(WIDTH)/Game::window.getSize().x), int(sf::Mouse::getPosition(Game::window).y*float(HEIGHT) / Game::window.getSize().y));
	if (mouse.x < x && mouse.x < x + w) return false;
	if (mouse.x > x && mouse.x > x + w) return false;
	if (mouse.y < y && mouse.y < y + h) return false;
	if (mouse.y > y && mouse.y > y + h) return false;
	return true;
}

