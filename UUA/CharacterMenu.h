#pragma once
#include "pch.h"
#include "Marshmellow.h"
#include "Game.h"
class CharacterMenu
{
	sf::Texture t;
	sf::Sprite menuBar;
	sf::Texture tx;
	sf::Sprite txt;
	sf::Texture opts[2];
	sf::Sprite options;
	sf::Texture arr[2];
	sf::Sprite arrows[2];
	sf::Texture dem[4];
	sf::Sprite demo[4];
	float offsetX, offsetY;
public:
	static int pos;
	CharacterMenu();
	void Draw(sf::RenderWindow&);
	void Update();
	~CharacterMenu();
};

