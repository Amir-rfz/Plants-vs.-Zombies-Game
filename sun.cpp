
#include "sun.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <string>

const float END_OF_WINDOW = 600.f;

void Sun::initTexture(){
    this->texture.loadFromFile("extrafile/sun.png");
}

bool Sun::hasArrivedToDown(){
    return this->sprite.getPosition().y > END_OF_WINDOW ;
}

void Sun::initSprite(){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(.15f, .15f);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

Sun::Sun(int _speed){
    speed = _speed;
    this->initTexture();
    this->initSprite();
}

void Sun::setPosition(float x, float y) {
        this->sprite.setPosition(x, y);
}


void Sun::move(const float dirX , const float dirY){
    this->sprite.move(this->speed * dirX ,this->speed * dirY);
}

void Sun::render(sf::RenderTarget& target){
    target.draw(this->sprite);
}

const sf::Sprite& Sun::getSprite() const{
    return sprite;
}
