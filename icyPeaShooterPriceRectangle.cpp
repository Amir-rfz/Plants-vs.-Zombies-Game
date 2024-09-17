#include "icyPeaShooterPriceRectangle.h"

const int COOL_DOWN_TIME = 9;
const std::string PIC_PATH = "extrafile/4.png";
const std::string COOL_DOWN_PIC_PATH = "extrafile/4dark.png";
const float RECTANGLE_SCALE = .9f;
const int FIRST_RECTANGLE_X = 60;
const int FIRST_RECTANGLE_Y = 80;
const int RECTANGLE_NUM = 3;


IcyPeaShooterPriceRectangle::IcyPeaShooterPriceRectangle(){
    collDownTime = COOL_DOWN_TIME;
    picturePath = PIC_PATH;
    collDownPicPath = COOL_DOWN_PIC_PATH;
}

void IcyPeaShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture icyPeaShooterCost;
        icyPeaShooterCost.loadFromFile(picturePath);
        sf::Sprite icyPeaShooterCostSprite;
        icyPeaShooterCostSprite.setTexture(icyPeaShooterCost);
        icyPeaShooterCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        icyPeaShooterCostSprite.setOrigin(icyPeaShooterCost.getSize().x/2 , icyPeaShooterCost.getSize().y/2);
        icyPeaShooterCostSprite.setPosition(FIRST_RECTANGLE_X  ,FIRST_RECTANGLE_Y + RECTANGLE_NUM * icyPeaShooterCost.getSize().y);
        this->sprit = icyPeaShooterCostSprite;
        target.draw(icyPeaShooterCostSprite);
    }
    else{
        sf::Texture icyPeaShooterCost;
        icyPeaShooterCost.loadFromFile(collDownPicPath);
        sf::Sprite icyPeaShooterCostSprite;
        icyPeaShooterCostSprite.setTexture(icyPeaShooterCost);
        icyPeaShooterCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        icyPeaShooterCostSprite.setOrigin(icyPeaShooterCost.getSize().x/2 , icyPeaShooterCost.getSize().y/2);
        icyPeaShooterCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y + RECTANGLE_NUM * icyPeaShooterCost.getSize().y);
        target.draw(icyPeaShooterCostSprite);
    }
}

bool IcyPeaShooterPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= collDownTime;
}

void IcyPeaShooterPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool IcyPeaShooterPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprit.getGlobalBounds().contains(addr);
}