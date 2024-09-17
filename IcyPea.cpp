#include "IcyPea.hpp"

const int SNOW_TIME = 5;
const int DAMAGE = 8;
const float SCALE = 0.09;
const float SPEED = 5;
const std::string PEA_PIC_PATH = "extrafile/snowpea.png";

IcyPea::IcyPea() : Projectile(PEA_PIC_PATH , SPEED , SCALE , DAMAGE , SNOW_TIME){}