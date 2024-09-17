#include "Plants.hpp"
#include "Cell.h"
#include <vector>

#ifndef Board_H
#define Board_H

class Board {
public:

    Board(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard);
    ~Board();
    bool isCellEmpty(sf::Vector2f addr);
    bool isContain(sf::Vector2f mousePositionFloat);
    sf::Vector2f plantAt(sf::Vector2f mouseAddr, Plant* plant);

private:

    sf::Vector2f beginOfBoard;
    sf::Vector2f endOfBoard;
    std::vector<std::vector<Cell*>> cells;
};

#endif
