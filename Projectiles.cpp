#include "Projectiles.hpp"

Projectile::Projectile(const std::string& texturePath, float _movementSpeed, float scale , int _damage ,int _snowTime){
    initTexture(texturePath);
    initSprite(scale);
    movementSpeed = _movementSpeed;
    hit = false;
    damage = _damage;
    snowTime = _snowTime;
}

void Projectile::initTexture(const std::string& texturePath){
    this->texture.loadFromFile(texturePath);
}

void Projectile::initSprite(float scale){
    this->sprite.setTexture(this->texture);
    this->sprite.scale(scale, scale);
    this->sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void Projectile::move(const float dirX , const float dirY){
    this->sprite.move(this->movementSpeed * dirX ,this->movementSpeed * dirY);
}

void Projectile::render(sf::RenderTarget& target){
    target.draw(this->sprite);
}

void Projectile::setPosition(float x, float y){
    this->sprite.setPosition(x, y);
}

bool Projectile::isOffScreen(int screenWidth){
    return sprite.getPosition().x > screenWidth || sprite.getPosition().x < 0;
}

sf::Sprite Projectile::getSprite(){
    return this->sprite;
}

bool Projectile::isHit(){
    return hit;
}

void Projectile::getHit(){
    this->hit = true;
}

int Projectile::getDamage(){
    return this->damage;
}

int Projectile::getSnowTime(){
    return this->snowTime;
}