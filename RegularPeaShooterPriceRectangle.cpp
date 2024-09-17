#include "RegularPeaShooterPriceRectangle.h"

const int COOL_DOWN_TIME = 5;
const std::string PIC_PATH = "extrafile/3.png";
const std::string COOL_DOWN_PIC_PATH = "extrafile/3dark.png";
const float RECTANGLE_SCALE = .9f;
const int FIRST_RECTANGLE_X = 60;
const int FIRST_RECTANGLE_Y = 80;
const int RECTANGLE_NUM = 2;

RegularPeaShooterPriceRectangle::RegularPeaShooterPriceRectangle(){
    coolDownTime = COOL_DOWN_TIME;
    picturePath = PIC_PATH;
    coolDownPicPath = COOL_DOWN_PIC_PATH;
}

void RegularPeaShooterPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= coolDownTime){
        sf::Texture RegularPeaShooterCost;
        RegularPeaShooterCost.loadFromFile(picturePath);
        sf::Sprite RegularPeaShooterCostSprite;
        RegularPeaShooterCostSprite.setTexture(RegularPeaShooterCost);
        RegularPeaShooterCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        RegularPeaShooterCostSprite.setOrigin(RegularPeaShooterCost.getSize().x/2 , RegularPeaShooterCost.getSize().y/2);
        RegularPeaShooterCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y  + RECTANGLE_NUM * RegularPeaShooterCost.getSize().y);
        this->sprite = RegularPeaShooterCostSprite;
        target.draw(RegularPeaShooterCostSprite);
    }
    else{
        sf::Texture RegularPeaShooterCost;
        RegularPeaShooterCost.loadFromFile(coolDownPicPath);
        sf::Sprite RegularPeaShooterCostSprite;
        RegularPeaShooterCostSprite.setTexture(RegularPeaShooterCost);
        RegularPeaShooterCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        RegularPeaShooterCostSprite.setOrigin(RegularPeaShooterCost.getSize().x/2 , RegularPeaShooterCost.getSize().y/2);
        RegularPeaShooterCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y + RECTANGLE_NUM * RegularPeaShooterCost.getSize().y);
        target.draw(RegularPeaShooterCostSprite);
    }
}

bool RegularPeaShooterPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= coolDownTime;
}

void RegularPeaShooterPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool RegularPeaShooterPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprite.getGlobalBounds().contains(addr);
}