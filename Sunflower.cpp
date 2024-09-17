#include "Sunflower.hpp"

const int DAMAGE = 0;
const int HEALTH = 30;
const float ACTIVATION_TIME = 5.0f;
const std::string PLANT_PIC_PATH = "extrafile/Sunflower.png";
const float SCALE = .05f;
const bool IS_WATERMELON = false;
const int COOL_DOWN_TIME = 12;

SunFlower::SunFlower()
    : Plant(DAMAGE , HEALTH , ACTIVATION_TIME , PLANT_PIC_PATH , SCALE ,false), coolDownTime(12){
    }

void SunFlower::update(){
    if (coolDownClock.getElapsedTime().asSeconds() >= coolDownTime) {
        if(!this->HaveSun){
            this->HaveSun = true;
            coolDownClock.restart();
        }
    }
    else{
        this->HaveSun = false;
    }

}

