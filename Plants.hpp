#ifndef PLANTS_H
#define PLANTS_H

#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Projectiles.hpp"

class Plant{
protected:

    int damage;
    int health;
    int activationTime;
    float scale;
    bool HaveRegularPea;
    bool HaveSnowPea;
    bool HaveSun;
    bool HaveWatermelon;
    Cell* cell;
    sf::Sprite sprite;
    sf::Texture texture;
    void initTexture(const std::string& texturePath);
    void initSprite();

public:

    Plant(int damage, int health, float activationTime, const std::string& texturePath ,float _scale,bool isWatermelon);
    virtual void update() = 0;
    void render(sf::RenderTarget& target);
    void setPosition(sf::Vector2f target);
    void getDamage(int damage);
    void assignCell(Cell* cell);
    void makeCellEmpty();
    bool isHaveRegularPea();
    bool isHaveSnowPea();
    bool isHaveSun();
    bool isHaveWatermelon();
    bool isDead();
    bool itWatermelon;
    sf::Vector2f getPeaAddr();
    sf::Vector2f getWatermelonAddr();
    sf::Vector2f getSunPos();
    sf::Sprite getSprite();
};

#endif
