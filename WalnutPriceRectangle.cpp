#include "WalnutPriceRectangle.h"

const int COOL_DOWN_TIME = 10;
const std::string PIC_PATH = "extrafile/2.png";
const std::string COOL_DOWN_PIC_PATH = "extrafile/2dark.png";
const float RECTANGLE_SCALE = .9f;
const int FIRST_RECTANGLE_X = 60;
const int FIRST_RECTANGLE_Y = 80;
const int RECTANGLE_NUM = 1;

WalnutPriceRectangle::WalnutPriceRectangle(){
    collDownTime = COOL_DOWN_TIME;
    picturePath = PIC_PATH;
    collDownPicPath = COOL_DOWN_PIC_PATH;
}

void WalnutPriceRectangle::render(sf::RenderTarget& target){
    if(clock.getElapsedTime().asSeconds() >= collDownTime){
        sf::Texture WalnutCost;
        WalnutCost.loadFromFile(picturePath);
        sf::Sprite WalnutCostSprite;
        WalnutCostSprite.setTexture(WalnutCost);
        WalnutCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        WalnutCostSprite.setOrigin(WalnutCost.getSize().x/2 , WalnutCost.getSize().y/2);
        WalnutCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y + WalnutCost.getSize().y);
        this->sprit = WalnutCostSprite;
        target.draw(WalnutCostSprite);
    }
    else{
        sf::Texture WalnutCost;
        WalnutCost.loadFromFile(collDownPicPath);
        sf::Sprite WalnutCostSprite;
        WalnutCostSprite.setTexture(WalnutCost);
        WalnutCostSprite.setScale(RECTANGLE_SCALE , RECTANGLE_SCALE);
        WalnutCostSprite.setOrigin(WalnutCost.getSize().x/2 , WalnutCost.getSize().y/2);
        WalnutCostSprite.setPosition(FIRST_RECTANGLE_X ,FIRST_RECTANGLE_Y + WalnutCost.getSize().y);
        target.draw(WalnutCostSprite);
    }
}

bool WalnutPriceRectangle::isAbleToAdd(){
    return clock.getElapsedTime().asSeconds() >= collDownTime;
}

void WalnutPriceRectangle::startCoolDown(){
    this->clock.restart();
}

bool WalnutPriceRectangle::isContains(sf::Vector2f addr){
    return this->sprit.getGlobalBounds().contains(addr);
}