#include "Watermelon.hpp"

const std::string WATERMELON_PIC_PATH = "extrafile/watermelon.png";
const float SCALE = .3f;
const int SPEED = 1;
const int DAMAGE = 15; 

Watermelon::Watermelon(){
    initTexture(WATERMELON_PIC_PATH);
    initSprite(SCALE);
    movementSpeed = SPEED;
    damage = DAMAGE;
}

void Watermelon::initTexture(const std::string& texturePath){
    this->texture.loadFromFile(texturePath);
}

void Watermelon::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void Watermelon::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Watermelon::render(sf::RenderTarget& target) {
    target.draw(this->sprite);
}

void Watermelon::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

sf::Sprite Watermelon::getSprite(){
    return this->sprite;
}

void Watermelon::addStartPos(sf::Vector2f _startPos){
    this->startPos = _startPos;
}
void Watermelon::addEndPos(float _EndPos){
    this->endPos = _EndPos;
}

float Watermelon::middleOfDistance(){
    return (endPos + startPos.x)/2 ;
}

sf::Vector2f Watermelon::position(){
    return this->sprite.getPosition();
}

sf::Vector2f Watermelon::getStartPos(){
    return this->startPos;
}

float Watermelon::getEndPos(){
    return this->endPos;
}

void Watermelon::assignZombi(Zombie* _zombie){
    this->zombie = _zombie;
}

void Watermelon::giveDamage(){
    this->zombie->getDamage(this->damage);
}