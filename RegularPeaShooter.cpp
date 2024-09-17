#include "RegularPeaShooter.hpp"

const int DAMAGE = 5;
const int HEALTH = 40;
const float ACTIVATION_TIME = 5;
const std::string PLANT_PIC_PATH = "extrafile/peashooter.png";
const float SCALE = .12f;
const bool IS_WATERMELON = false;

RegularPeaShooter::RegularPeaShooter()
    : Plant(DAMAGE , HEALTH , ACTIVATION_TIME , PLANT_PIC_PATH , SCALE , IS_WATERMELON){
        this->firstTime = true ;
}

void RegularPeaShooter::update() {
    if (PeaShotClock.getElapsedTime().asSeconds() >= activationTime || this->firstTime ) {
        if(!this->HaveRegularPea){
            this->HaveRegularPea = true;
            PeaShotClock.restart();
            this->firstTime = false;
        }
    }
    else{
        this->HaveRegularPea = false;
    }
}