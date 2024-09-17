#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>
#include"Plants.hpp"
#include "Projectiles.hpp"

#ifndef ZOMBIE_H
#define ZOMBIE_H

class Plant;

class Zombie{

private:

    int damage;
    int maxHealth;
    int health;
    int hitRate;
    int row;
    float movementSpeed;
    bool eating;
    bool freezing;
	int freezing_time;
    void initTexture(std::string textureFilePath);
    void initSprite(float scale);
    void setPosition(float x, float y);
    float getRandomPosition();
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock hitRateClock;
    sf::Clock freezeTimer;

public:

    Zombie(std::string textureFilePath, float scale ,float _movementSpeed, int maxHealth , int damage , int hiRate);
    bool hasArrivedHome();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
    bool isEating();
    void startEating(Plant* plant);
    void isNotEating();
    void hitByPea(Projectile* pea);
    void upDate();
    bool isDead();
    bool isInSameLine(sf::Vector2f addr);
    void getDamage(int damage);
    sf::Sprite getSprite();
    
};

#endif