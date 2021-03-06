#pragma once
#include<map>
#include"stdafx.h"
#include"player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"PlayerGUI.h"
#include"Menu.h"
#include"HeartItem.h"
#include"Chest.h"
#include"Endgame.h"
#include"Stone.h"
#include"Endgame.h"
#include"score.h"
#include"Shield.h"
#include"Monster.h"
#include"Foeman.h"

class Game
{
private:
	int end;
	sf::RenderWindow window;
	sf::Event ev;

	sf::Clock bulletTime;
	sf::Clock enemiesTime;
	sf::Clock monsterTime;
	sf::Clock foemanTime;

	
	//Username
	sf::Texture nameboardTex;
	sf::Sprite nameboardSprite;
	std::string player_name = "";
	std::vector<char> username;
	bool namestate = false;


	//word bg
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	
	float backgroundX = 0;

	//Resources
	std::map<std::string,sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//enemy
	Enemy* enemy;
	int enemiseCount = 0 ;
	std::vector<Enemy*> enemys;

	//Player
	Player* player;

	//Bullet
	Bullet* bullet;

	//monster
	Monster* monster;
	int monsterCount = 0;
	std::vector<Monster*> monsterP;
	float MonsterX = 0;
	
	//monster
	Foeman* foeman;
	int foemanCount = 0;
	std::vector<Foeman*> foemans;
	float FoemanX = 0;
	
	//GUI
	PlayerGUI* playerGUI;
	PlayerGUI* hpBar;

	//endgame
	Endgame* endGame;

	//heartItem
	std::vector<HeartItem*> heartItem;
	sf::Clock randHeart;
	sf::Clock timeHeart;
	float heartX = 0;
	float heartY = 0;

	//Chest
	std::vector<Chest*> chest;
	sf::Clock randChest;
	sf::Clock timeChest;
	float ChestX = 0;
	float ChestY = 0;

	//Stone
	std::vector<Stone*> stone;
	sf::Clock delayStone;
	sf::Clock randStone;
	sf::Clock timeStone;
	int countStone = 0;
	float StoneX = 0;

	/*Shield*/
	std::vector<Shield*> shield;
	Shield* aura;
	sf::Clock randomShield;
	sf::Clock delayShield;
	sf::Clock delayAura;
	bool IsStart = false;
	bool IsAura = false;
	float shieldX = 0;
	float shieldY = 0;
	int countShield = 0;

	//Score
	sf::Clock timeText;
	float timeUS;
	score scoreboard;
	std::string name;
	std::string user_name;
	sf::Text US_name;
	bool scoreCheck = false;

	bool over();
	void reset();

	//game over
	Endgame* gameOver;


	//menu
	Menu* menu;
	bool GameRun = false;
	bool menuPlay = true;
	bool Gameovercheck = false;
	

	sf::Texture nameBackgroundTex;
	sf::Sprite nameBackground;

	//Sound
	sf::SoundBuffer buffer[5];
	sf::Sound sound[5];
	bool ThemeSongOn = false;
	bool GameOverSong = false;



	void initWindow();
	void initSound();
	void initplayer();
	void initBullet();
	void initEnemy();
	void initMonster();
	void initAura();
	void initFoeman();
	void initHpBar();
	void initGUI();
	void initUsername();
	void initGameover();

	void initWorld();



public:

	


	//Functions
	Game();
	virtual ~Game();

	void run();
	void getName(std::string name);

	//Functions

	void collision();
	void updateSong();
	void updateHeartItem();
	void updateShield();
	void updateChest();
	void updateStone();
	void updateHpBar();
	void updateBullets();
	void updateEnemy();
	void updateMonster();
	void updateFoeman();
	void updateplayer();
	void updateWorld();
	

	void update();

	void renderUsername();
	void renderNamebg();
	void renderGUI();
	void renderHeartItem();
	void renderShield();
	void renderChest();
	void renderStone();
	void renderPlayer();
	void renderBullet();
	void renderEnemy();
	void renderMonster();
	void renderFoeman();
	void renderSavescore();
	void renderEndgame();
	void renderWorld();
	void renderGameover();
	void render();
	const sf::RenderWindow& getWindow() const;
};