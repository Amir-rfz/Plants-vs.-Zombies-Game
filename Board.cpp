#include "Board.h"

const int NUMBER_OF_ROW = 5;
const int NUMBER_OF_COL = 9;

Board::~Board(){
    for (auto& row : cells){
        for (auto cell : row){
            delete cell;
        }
    }
}

float calculateHeight(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard){
    return (endOfBoard.y - beginOfBoard.y)/NUMBER_OF_ROW;
}

float calculateWeight(sf::Vector2f beginOfBoard , sf::Vector2f endOfBoard){
    return (endOfBoard.x - beginOfBoard.x)/NUMBER_OF_COL;
}

Board::Board(sf::Vector2f _beginOfBoard , sf::Vector2f _endOfBoard){
    this->beginOfBoard = _beginOfBoard;
    this->endOfBoard = _endOfBoard;
    float cellHeight = calculateHeight(this->beginOfBoard ,this->endOfBoard);
    float cellWeight = calculateWeight(this->beginOfBoard ,this->endOfBoard);
    for(int i = 0 ; i < NUMBER_OF_ROW ; i++){
        std::vector<Cell*> rowCell;
        for(int j = 0 ; j < NUMBER_OF_COL ; j++){
            sf::Vector2f beginOfCell;
            beginOfCell.x = beginOfBoard.x + j*cellWeight;
            beginOfCell.y = beginOfBoard.y + i*cellHeight;
            sf::Vector2f endOfCell;
            endOfCell.x = beginOfCell.x + cellWeight;
            endOfCell.y = beginOfCell.y + cellHeight;
            rowCell.push_back(new Cell(beginOfCell , endOfCell));
        }
        cells.push_back(rowCell);
    }
}

sf::Vector2f Board::plantAt(sf::Vector2f mouseAddr ,Plant* plant) {
    for(auto rowCell : this->cells){
        for(Cell* cell : rowCell){
            if(cell->isEmpty() && cell->isContainAddr(mouseAddr)){
                cell->getFull();
                plant->assignCell(cell);
                return cell->setPlant(plant);
            }
        }
    }
} 

bool Board::isContain(sf::Vector2f mousePositionFloat){
    return ((mousePositionFloat.x > this->beginOfBoard.x) && 
            (mousePositionFloat.x < this->endOfBoard.x) && 
            (mousePositionFloat.y > this->beginOfBoard.y) && 
            (mousePositionFloat.y < this->endOfBoard.y));}

bool Board::isCellEmpty(sf::Vector2f addr){
    for(auto cellRow : cells){
        for(auto cell : cellRow){
            if(cell->isContainAddr(addr)){
                if(cell->isEmpty())
                    return true;
            }
        }
    }
    return false;
}