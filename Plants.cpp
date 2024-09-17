#include "Plants.hpp"

const int X_SUN_RELATIVE_TO_SUNFLOWER = 15;
const int Y_SUN_RELATIVE_TO_SUNFLOWER = 30;

const int X_PEA_RELATIVE_TO_PEASHOOTER = 20;
const int Y_PEA_RELATIVE_TO_PEASHOOTER = 14;

const int X_WATERMELON_RELATIVE_TO_CELL = 15;

const int WATERMELON_RELATIVE_TO_POSITION = 17;

Plant::Plant(int _damage, int _health, float _activationTime,const std::string& texturePath ,float _scale ,bool isWatermelon) 
    : damage(_damage), health(_health), activationTime(_activationTime),scale(_scale){
    initTexture(texturePath);
    initSprite();
    HaveRegularPea = false;
    HaveSnowPea = false;
    HaveSun = false;
    HaveWatermelon = false;
    this->itWatermelon = isWatermelon;

}

void Plant::initTexture(const std::string& texturePath) {
    this->texture.loadFromFile(texturePath);
}

void Plant::initSprite() {
    this->sprite.setTexture(texture);
    this->sprite.scale(scale , scale);
    this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}

void Plant::render(sf::RenderTarget& target) {
    target.draw(sprite);
}

void Plant::setPosition(sf::Vector2f addr){
    if(this->itWatermelon){
        addr.x -= X_WATERMELON_RELATIVE_TO_CELL;
    }
    this->sprite.setPosition(addr);
}

sf::Sprite Plant::getSprite(){
    return this->sprite;
}

bool Plant::isDead(){
    return this->health <= 0;
}

void Plant::getDamage(int damage){
    this->health -= damage;
}

bool Plant::isHaveRegularPea(){
    return HaveRegularPea;
}

bool Plant::isHaveSnowPea(){
    return HaveSnowPea;
}

bool Plant::isHaveSun(){
    return HaveSun;
}

sf::Vector2f Plant::getPeaAddr(){
    sf::Vector2f addr;
    addr = this->sprite.getPosition();
    addr.x += X_PEA_RELATIVE_TO_PEASHOOTER;
    addr.y -= Y_PEA_RELATIVE_TO_PEASHOOTER;
    return addr;
}

sf::Vector2f Plant::getSunPos(){
    sf::Vector2f addr;
    addr = this->sprite.getPosition();
    addr.x += X_SUN_RELATIVE_TO_SUNFLOWER;
    addr.y += Y_SUN_RELATIVE_TO_SUNFLOWER;
    return addr;
}

void Plant::assignCell(Cell* cell){
    this->cell = cell;
}

void Plant::makeCellEmpty(){
    this->cell->getEmpty();
}

bool Plant::isHaveWatermelon(){
    return HaveWatermelon;
}

sf::Vector2f Plant::getWatermelonAddr(){
    sf::Vector2f addr;
    addr = this->sprite.getPosition();
    addr.x -= WATERMELON_RELATIVE_TO_POSITION;
    addr.y -= WATERMELON_RELATIVE_TO_POSITION;
    return addr;
}