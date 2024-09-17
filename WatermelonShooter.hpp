#include "Plants.hpp"
#include "Watermelon.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class WatermelonShooter : public Plant{
private:
    sf::Clock WatermelonShotClock;
    bool firstTime;

public:
    WatermelonShooter();
    void update();
};