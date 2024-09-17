#include "Cell.h"

const int WATERMELON_ORIGIN_POS_DISTANCE = 8;

Cell::Cell(sf::Vector2f _beginOfCell , sf::Vector2f _endOfCell){
    this->beginOfCell = _beginOfCell;
    this->endOfCell = _endOfCell;
    empty = true;
}

bool Cell::isContainAddr(sf::Vector2f Addr) {
    return (this->beginOfCell.x <= Addr.x && Addr.x < this->endOfCell.x &&
            this->beginOfCell.y <= Addr.y && Addr.y < this->endOfCell.y);
}

sf::Vector2f Cell::setPlant(Plant* plant){
    this->plant = plant;
    sf::Vector2f position;
    position.x = (this->endOfCell.x + this->beginOfCell.x)/2;
    position.y = (this->endOfCell.y + this->beginOfCell.y)/2;
    if(plant->itWatermelon){
        position.x -= WATERMELON_ORIGIN_POS_DISTANCE;
        position.y -= WATERMELON_ORIGIN_POS_DISTANCE;
    }
    plant->setPosition(position);
    return position;
    empty = false;
}

bool Cell::isEmpty(){
    return empty;
}

sf::Vector2f Cell::getCellMidPosition(){
    sf::Vector2f midpoint;
    midpoint.x = (endOfCell.x + beginOfCell.x)/2;
    midpoint.y = (endOfCell.y + beginOfCell.y)/2;
    return midpoint;
}

void Cell::getFull(){
    this->empty = false;
}

void Cell::getEmpty(){
    this->empty = true;
}
