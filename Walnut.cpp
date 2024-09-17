#include "Walnut.hpp"

const int DAMAGE = 0;
const int HEALTH = 200;
const float ACTIVATION_TIME = 0;
const std::string PLANT_PIC_PATH = "extrafile/Wallnut.png";
const float SCALE = .08f;
const bool IS_WATERMELON = false;

Walnut::Walnut()
    : Plant(DAMAGE , HEALTH , ACTIVATION_TIME , PLANT_PIC_PATH , SCALE , IS_WATERMELON){
    }
