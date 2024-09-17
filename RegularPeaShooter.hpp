#include "Plants.hpp"
#include "RegularPea.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class RegularPeaShooter : public Plant{
private:
    sf::Clock PeaShotClock;
    bool firstTime;

public:
    RegularPeaShooter();
    void update();
};
