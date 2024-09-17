#include "WatermelonShooterPriceRectangle.h"

const int COOL_DOWN_TIME = 10;
const std::string PIC_PATH = "extrafile/5.png";
const std::string COOL_DOWN_PIC_PATH = "extrafile/5dark.png";
const float RECTANGLE_SCALE = .9f;
const int FIRST_RECTANGLE_X = 60;
const int FIRST_RECTANGLE_Y = 80;
const int RECTANGLE_NUM = 4;

WatermelonShooterPriceRectangle::WatermelonShooterPriceRectangle(){
    coolDownTime = COOL_DOWN_TIME;
    picturePath = PIC_PATH;
    coolDownPicPath = COOL_DOWN_PIC_PATH;
}

void WatermelonShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= coolDownTime){
        sf::Texture watermelonShooterCost;
        watermelonShooterCost.loadFromFile(picturePath);
        sf::Sprite watermelonShooterCostSprite;
        watermelonShooterCostSprite.setTexture(watermelonShooterCost);
        watermelonShooterCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        watermelonShooterCostSprite.setOrigin(watermelonShooterCost.getSize().x/2 , watermelonShooterCost.getSize().y/2);
        watermelonShooterCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y + RECTANGLE_NUM * watermelonShooterCost.getSize().y);
        this->sprite = watermelonShooterCostSprite;
        target.draw(watermelonShooterCostSprite);
    }
    else{
        sf::Texture watermelonShooterCost;
        watermelonShooterCost.loadFromFile(coolDownPicPath);
        sf::Sprite watermelonShooterCostSprite;
        watermelonShooterCostSprite.setTexture(watermelonShooterCost);
        watermelonShooterCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        watermelonShooterCostSprite.setOrigin(watermelonShooterCost.getSize().x/2 , watermelonShooterCost.getSize().y/2);
        watermelonShooterCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y + RECTANGLE_NUM * watermelonShooterCost.getSize().y);
        target.draw(watermelonShooterCostSprite);
    }
}

bool WatermelonShooterPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= coolDownTime;
}

void WatermelonShooterPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool WatermelonShooterPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprite.getGlobalBounds().contains(addr);
}