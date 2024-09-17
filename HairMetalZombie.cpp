#include "HairMetalZombie.h"

const int MAX_HEALTH = 80;
const int DAMAGE = 20;
const int HIT_RATE = 6;
const float SPEED = .15f;
const float SCALE = 0.2;
const std::string ZOMBIE_PIC_PATH = "extrafile/hairmetal.png";

HairMetalZombie::HairMetalZombie() : Zombie(ZOMBIE_PIC_PATH , SCALE , SPEED ,  MAX_HEALTH , DAMAGE , HIT_RATE){}
