#include "SunFlowerPriceRectangle.h"

const int COOL_DOWN_TIME = 10;
const std::string PIC_PATH = "extrafile/1.png";
const std::string COOL_DOWN_PIC_PATH = "extrafile/1dark.png";
const float RECTANGLE_SCALE = .9f;
const int FIRST_RECTANGLE_X = 60;
const int FIRST_RECTANGLE_Y = 80;
const int RECTANGLE_NUM = 0;

SunFlowerPriceRectangle::SunFlowerPriceRectangle(){
    collDownTime = COOL_DOWN_TIME;
    picturePath = PIC_PATH;
    collDownPicPath = COOL_DOWN_PIC_PATH;
}


void SunFlowerPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture sunFlowerCost;
        sunFlowerCost.loadFromFile(picturePath);
        sf::Sprite sunFlowerCostSprite;
        sunFlowerCostSprite.setTexture(sunFlowerCost);
        sunFlowerCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        sunFlowerCostSprite.setOrigin(sunFlowerCost.getSize().x/2 , sunFlowerCost.getSize().y/2);
        sunFlowerCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y);
        this->sprit = sunFlowerCostSprite;
        target.draw(sunFlowerCostSprite);
    }
    else{
        sf::Texture sunFlowerCost;
        sunFlowerCost.loadFromFile(collDownPicPath);
        sf::Sprite sunFlowerCostSprite;
        sunFlowerCostSprite.setTexture(sunFlowerCost);
        sunFlowerCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        sunFlowerCostSprite.setOrigin(sunFlowerCost.getSize().x/2 , sunFlowerCost.getSize().y/2);
        sunFlowerCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y);
        target.draw(sunFlowerCostSprite);
    }
}

bool SunFlowerPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= collDownTime;
}

void SunFlowerPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool SunFlowerPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprit.getGlobalBounds().contains(addr);
}