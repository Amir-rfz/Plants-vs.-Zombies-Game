#include "WatermelonShooter.hpp"

const int DAMAGE = 15;
const int HEALTH = 20;
const float ACTIVATION_TIME = 8;
const std::string PLANT_PIC_PATH = "extrafile/Melonpult.png";
const float SCALE = .25f;
const bool IS_WATERMELON = true;

WatermelonShooter::WatermelonShooter()
    : Plant(DAMAGE , HEALTH , ACTIVATION_TIME , PLANT_PIC_PATH , SCALE , IS_WATERMELON){
        this->firstTime = true ;
}

void WatermelonShooter::update() {
    if (WatermelonShotClock.getElapsedTime().asSeconds() >= activationTime || this->firstTime ) {
        if(!this->HaveWatermelon){
            this->HaveWatermelon = true;
            WatermelonShotClock.restart();
            this->firstTime = false;
        }
    }
    else{
        this->HaveWatermelon = false;
    }
}