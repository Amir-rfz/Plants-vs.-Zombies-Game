#include <vector>
#include "Plants.hpp"
#include "Zombie.h"

#ifndef cell_H
#define cell_H

class Cell {
private:

    bool empty;
    sf::Vector2f beginOfCell;
    sf::Vector2f endOfCell;
    Plant* plant;

public:

    Cell(sf::Vector2f beginOfCell , sf::Vector2f endOfCell);
    sf::Vector2f setPlant(Plant* plant);
    sf::Vector2f getCellMidPosition();
    bool isEmpty();
    bool isContainAddr(sf::Vector2f Addr);
    void getFull();
    void getEmpty();

};

#endif
