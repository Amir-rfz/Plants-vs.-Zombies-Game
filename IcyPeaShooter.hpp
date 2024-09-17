#include "Plants.hpp"
#include <vector>
#include "IcyPea.hpp"
#include <SFML/Graphics.hpp>

#ifndef ICY_PEASHOOTER_HPP
#define ICY_PEASHOOTER_HPP

class IcyPeaShooter : public Plant{
private:
    sf::Clock PeaShotClock;
    bool firstTime;

public:
    IcyPeaShooter();
    void update();
};

#endif