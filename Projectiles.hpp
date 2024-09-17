#ifndef PROJECTILES_HPP
#define PROJECTILES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Projectile{
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float movementSpeed;
    float scale;
    bool hit;
    int damage;
    int snowTime;

public:
    Projectile(const std::string& texturePath, float _movementSpeed, float scale , int _damage ,int _snowTime);
    void initTexture(const std::string& texturePath);
    void initSprite(float scale);
    void move(const float dirX , const float dirY);
    void render(sf::RenderTarget& target);
    void setPosition(float x, float y);
    bool isOffScreen(int screenWidth);
    bool isHit();
    void getHit();
    int getDamage();
    int getSnowTime();
    sf::Sprite getSprite();
};

#endif