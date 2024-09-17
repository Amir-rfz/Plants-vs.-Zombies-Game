#include "Plants.hpp"

#ifndef SUNFLOWER_H
#define SUNFLOWER_H

class SunFlower : public Plant {
    float scale;
    int coolDownTime;
    sf::Clock coolDownClock;

public:
    SunFlower();
    void update();
};

#endif