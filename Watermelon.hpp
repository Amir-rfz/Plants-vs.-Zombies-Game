#ifndef Watermelon_HPP
#define Watermelon_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Zombie.h"

class Watermelon{
protected:

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f startPos;
    float movementSpeed;
    float scale;
    int damage;
    float endPos;
    Zombie* zombie;

public:

    Watermelon();
    void initTexture(const std::string& texturePath);
    void initSprite(float scale);
    void move(const float dirX , const float dirY);
    void render(sf::RenderTarget& target);
    void setPosition(float x, float y);
    void addStartPos(sf::Vector2f startPos);
    void addEndPos(float EndPos);
    float middleOfDistance();
    float getEndPos();
    void assignZombi(Zombie* zombie);
    void giveDamage();
    sf::Vector2f position();
    sf::Vector2f getStartPos();
    sf::Sprite getSprite();
    
};

#endif