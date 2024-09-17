#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<string>

#ifndef Sun_H
#define Sun_H

class Sun{
private:

    int speed;
    sf::Texture texture;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();

public:

    Sun(int speed);
    void setPosition(float x, float y);
    bool hasArrivedToDown();
    void render(sf::RenderTarget& target);
    void move(const float dirX , const float dirY);
    const sf::Sprite& getSprite() const;
    
};

#endif
