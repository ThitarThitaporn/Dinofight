#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"stdafx.h"
#include"score.h"

class score
{

private:
	sf::Font font;
	sf::Text main, scoretext[5];
	sf::Sprite scoreBorder;
	FILE* fp;
	sf::Text top[5];
	int i;
	char temp[255];
	size_t Score[6];
	std::string name[6];
	std::vector<std::pair<int, std::string>> userScore;
	
	size_t getscore;
	std::string getName;


public:

	score();
	~score();
	void ReadFile();
	void wFile();
	std::string Pname;
	int scoreplayer;
	void setscoretext();
	void Drawscore(sf::RenderWindow& window);

};
