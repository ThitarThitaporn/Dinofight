#pragma once
enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::Clock animationTimer;
	sf::Clock timeJumping;

	//Animation
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;

	//time
	float delayJump;
	bool changeJump = true;

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocitMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	//core

	void initVariable();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initPhysics();


public:
	Player();
	virtual ~Player();
	//Accessors
	const bool& getAnimSwitch();
	const sf::FloatRect getGlobalBouds() const;
	const sf::Vector2f getPosition() const;

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();
	void resetVelocityX();

	//function
	void resetAnimationTimer();
	void Move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updatAnimations();
	void update();

	//jumping
	bool jumping = false;
	bool jumpingup = false;
	bool gravityBool = false;
	

	void render(sf::RenderTarget& target);

};