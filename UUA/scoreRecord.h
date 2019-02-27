#pragma once
#include "pch.h"
//#include "Death.h"
#include "Game.h"


class scoreRecord :
	public Death
{
	int flag;
	sf::Texture nameTexture;
	sf::Sprite nameSprite;
	sf::Text nameEntered;
public:
	scoreRecord();
	~scoreRecord();
	std::string name;
	void Draw(sf::RenderWindow &);
	int Update();
};
