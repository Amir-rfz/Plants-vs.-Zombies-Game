#include <SFML/Graphics.hpp>
#include <string>

#ifndef WatermelonShooterPriceRectangle_H
#define WatermelonShooterPriceRectangle_H

class WatermelonShooterPriceRectangle{
private:

    int coolDownTime;
    sf::Sprite sprite;
    sf::Clock clock;
    std::string picturePath;
    std::string coolDownPicPath;
    
public:

    WatermelonShooterPriceRectangle();
    bool isContains(sf::Vector2f addr);
    void render(sf::RenderTarget& target);
    void startCoolDown();
    bool isAbleToAdd();
    
};



#endif