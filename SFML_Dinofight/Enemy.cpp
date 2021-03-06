#include "stdafx.h"
#include "Enemy.h"

void Enemy::initEnemyTex()
{
	if (!this->enemyTex.loadFromFile("texTure/allenemy3.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Enemy::initEnemySprite()
{
	this->enemySprite.setTexture(this->enemyTex);
	this->currentFrame = sf::IntRect(0, 0, 144, 60);
	this->enemySprite.setTextureRect(this->currentFrame);
	this->enemySprite.setScale(2.f, 2.f);
	
}

void Enemy::initAnimation()
{
	this->enemyTimer.restart();
}

void Enemy::initVariables()
{
	this->type		= 0;
	this->hpMax		= 10;
	this->hp		= 0;
	this->damage	= 1;
	this->points	= 5;
}

void Enemy::initHitbox()
{
	this->hitboxEnemies.setOutlineColor(sf::Color::Blue);
	this->hitboxEnemies.setOutlineThickness(2.f);
	this->hitboxEnemies.setFillColor(sf::Color::Transparent);
	this->hitboxEnemies.setSize(sf::Vector2f(150.f, 90.f));
}

void Enemy::updateHitbox()
{
	this->hitboxEnemies.setPosition(enemySprite.getPosition().x + 50 , enemySprite.getPosition().y);
}

Enemy::Enemy()
{
	//printf("A");
	this->initEnemyTex();
	this->initVariables();
	
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initEnemyTex();
	this->initEnemySprite(); //forget
	this->initAnimation();
	this->initVariables();

	//hitbox
	this->initHitbox();
	this->updateHitbox();

	this->enemySprite.setPosition(pos_x, pos_y);
	this->enemiesX = pos_x;
}

Enemy::~Enemy()
{

}

const sf::FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds();
}

const sf::Vector2f Enemy::getPosition() const
{
	return this->enemySprite.getPosition();
}

const sf::Vector2f Enemy::setPosition(float x,float y) const
{
	return this->enemySprite,setPosition(x,y);
}

const sf::FloatRect Enemy::getBoundsHitbox() const
{
	return this->enemySprite.getGlobalBounds();
}

void Enemy::updateMovement()
{
	enemiesX -= 2;
	this->enemySprite.setPosition(enemiesX, enemySprite.getPosition().y);
	//this->enemySprite.setPosition(enemySprite.getPosition().y, enemiesX);
}

void Enemy::updateAnimation()
{
	if (this->enemyTimer.getElapsedTime().asSeconds() >= 0.5f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 144.f;
		if (this->currentFrame.left >= 576.f)
			this->currentFrame.left = 0;
		this->enemyTimer.restart();
		this->enemySprite.setTextureRect(this->currentFrame);
	}
}

void Enemy::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updateHitbox();
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemySprite);
	//target.draw(this->hitboxEnemies);
}
