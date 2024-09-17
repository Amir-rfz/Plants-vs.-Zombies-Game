#include <SFML/Graphics.hpp>
#include <string>

#ifndef SunFlowerPriceRectangle_H
#define SunFlowerPriceRectangle_H

class SunFlowerPriceRectangle{
private:

    int collDownTime;
    sf::Sprite sprit;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:

    SunFlowerPriceRectangle();
    bool isContains(sf::Vector2f addr);
    void render(sf::RenderTarget& target);
    void startCoolDown();
    bool isAbleToAdd();
    
};

#endif