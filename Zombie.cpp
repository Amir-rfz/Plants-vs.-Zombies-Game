
#include "Zombie.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>

const float BEGIN_OF_BOARD = 150.f;
const float END_OF_BOARD = 800.f;

const int NUM_OF_ROW = 5;
const float CENTER_OF_ROW_1 = 125.f;
const float CENTER_OF_ROW_2 = 210.f;
const float CENTER_OF_ROW_3 = 310.f;
const float CENTER_OF_ROW_4 = 400.f; 
const float CENTER_OF_ROW_5 = 495.f;

const int CELL_HIGHT = 92;
const int DISTANCE_TO_CELL_ONE = 90;

void Zombie::initTexture(std::string textureFilePath){
    this->texture.loadFromFile(textureFilePath);
}

bool Zombie::hasArrivedHome(){
    return this->sprite.getPosition().x < BEGIN_OF_BOARD;
}

float Zombie::getRandomPosition(){
    int randomNumber = std::rand() % NUM_OF_ROW;
    this->row = randomNumber + 1;
    float possiblePosition[NUM_OF_ROW] = {CENTER_OF_ROW_1 , CENTER_OF_ROW_2 , CENTER_OF_ROW_3 , CENTER_OF_ROW_4 , CENTER_OF_ROW_5};
    return possiblePosition[randomNumber];
}

void Zombie::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    this->sprite.setPosition(END_OF_BOARD , getRandomPosition());
}

Zombie::Zombie(std::string textureFilePath, float scale , float _movementSpeed, int _maxHealth , int _damage , int _hitRate){
    movementSpeed = _movementSpeed;
    maxHealth = _maxHealth;
    damage = _damage;
    hitRate = _hitRate;
    health = _maxHealth;
    eating = false;
    freezing = false;
    freezing_time = 0;


    initTexture(textureFilePath);
    initSprite(scale);
}

void Zombie::setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
}

bool Zombie::isEating(){
    return this->eating;
}

void Zombie::move(const float dirX , const float dirY){
    if(freezing){
        this->sprite.move((this->movementSpeed/2) * dirX ,(this->movementSpeed/2) * dirY);
    }
    else{
        this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
    }
}

void Zombie::render(sf::RenderTarget& target){
    target.draw(this->sprite);
}

sf::Sprite Zombie::getSprite(){
    return this->sprite;
}

void Zombie::startEating(Plant* plant){
    this->eating = true;
    if(hitRateClock.getElapsedTime().asSeconds() >= hitRate){
        plant->getDamage(damage);
        hitRateClock.restart();
    }

    if(plant->isDead())
        this->eating = false;

}

void Zombie::isNotEating(){
    this->eating = false;
}

void Zombie::hitByPea(Projectile* pea){
    this->freezing_time += pea->getSnowTime();
    this->health -= pea->getDamage();
}

void Zombie::upDate(){
    if (freezeTimer.getElapsedTime().asSeconds() < freezing_time) {
        this->freezing = true;
    }
    else {
        this->freezing = false;
        freezing_time = 0;
        freezeTimer.restart();
    }
}

bool Zombie::isDead(){
    return this->health <= 0;
}

bool Zombie::isInSameLine(sf::Vector2f addr){
    int beginOfCell = DISTANCE_TO_CELL_ONE + ((row-1) * CELL_HIGHT);
    int endOfCell = DISTANCE_TO_CELL_ONE + (row * CELL_HIGHT);
    return (addr.y > beginOfCell) && (addr.y < endOfCell);
}

void Zombie::getDamage(int damage){
    this->health -= damage;
}