#pragma once
#include"pch.h"
#include "GameObject.h"
#include "Point.h"
#include "Death.h"
#include "Menu.h"
#include "Leaderboard.h"
#include "CharacterMenu.h"
#include "scoreRecord.h"
#include <SFML/Audio.hpp>
#include <time.h>

#define WIDTH 1366
#define HEIGHT 768

class GameObjectManager;
class GameObject;
class Death;
class Menu;
class CharacterMenu;
class Leaderboard;
class scoreRecord;


class Game
{
private:
	static void GameLoop();
	static sf::Clock clock;
	static GameObjectManager gameObjectManager;
	static Death d;
	static Menu m;
	static CharacterMenu cm;
	static Leaderboard leadBoard;
	static scoreRecord scrRecord;
	static sf::Texture lgo;
	static sf::Sprite logo;
public:
	Game();
	enum GameState {
		Uninitialized,  Paused,
		Menu, Playing, HighScore, Exiting, Dead,Character,RecordScore
	};
	static float spawnTime;
	static bool IsExiting();
	static int Random(int a,int b);
	static int level;
	static float yLevel;
	static GameState gameState;
	static sf::RenderWindow window;
	static sf::Clock clockTotal;
	static sf::Clock scoreClock;
	static sf::Event event;
	static sf::Sound coin;
	static sf::Sound death;
	static int coinCount;
	static sf::Font font;
	static int score;
	static void Start();
	static sf::RenderWindow& GetWindow() { return window; }
	~Game();
};

