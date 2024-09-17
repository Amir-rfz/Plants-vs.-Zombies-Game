#include <SFML/Graphics.hpp>
#include <string>

#ifndef WalnutPriceRectangle_H
#define WalnutPriceRectangle_H

class WalnutPriceRectangle{
private:

    int collDownTime;
    sf::Sprite sprit;
    sf::Clock clock;
    std::string picturePath;
    std::string collDownPicPath;
    
public:

    WalnutPriceRectangle();
    bool isContains(sf::Vector2f addr);
    void render(sf::RenderTarget& target);
    void startCoolDown();
    bool isAbleToAdd();
    
};



#endif