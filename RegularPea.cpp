#include "RegularPea.hpp"

const int SNOW_TIME = 0;
const int DAMAGE = 5;
const float SCALE = 0.05;
const float SPEED = 7;
const std::string PEA_PIC_PATH = "extrafile/pea.png";

RegularPea::RegularPea() : Projectile(PEA_PIC_PATH , SPEED , SCALE , DAMAGE , SNOW_TIME){}