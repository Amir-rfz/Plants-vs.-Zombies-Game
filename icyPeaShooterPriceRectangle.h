#include <SFML/Graphics.hpp>
#include <string>

#ifndef icyPeaShooterPriceRectangle_H
#define icyPeaShooterPriceRectangle_H

class IcyPeaShooterPriceRectangle{

private:

    int collDownTime;
    sf::Sprite sprit;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:

    IcyPeaShooterPriceRectangle();
    bool isContains(sf::Vector2f addr);
    void render(sf::RenderTarget& target);
    void startCoolDown();
    bool isAbleToAdd();
    
};



#endif