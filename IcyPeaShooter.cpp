#include "IcyPeaShooter.hpp"

const int DAMAGE = 8;
const int HEALTH = 30;
const float ACTIVATION_TIME = 5;
const std::string PLANT_PIC_PATH = "extrafile/icypeashooter.png";
const float SCALE = .055f;
const bool IS_WATERMELON = false;

IcyPeaShooter::IcyPeaShooter()
    : Plant(DAMAGE , HEALTH , ACTIVATION_TIME , PLANT_PIC_PATH , SCALE , IS_WATERMELON){
        this->firstTime = true ;
    }

void IcyPeaShooter::update() {
    if (PeaShotClock.getElapsedTime().asSeconds() >= activationTime || this->firstTime ) {
        if(!this->HaveSnowPea){
            this->HaveSnowPea = true;
            PeaShotClock.restart();
            this->firstTime = false;
        }
    }
    else{
        this->HaveSnowPea = false;
    }
}