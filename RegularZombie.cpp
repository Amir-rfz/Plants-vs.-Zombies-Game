#include "RegularZombie.h"

const int MAX_HEALTH = 50;
const int DAMAGE = 10;
const int HIT_RATE = 5;
const float SPEED = .2f;
const float SCALE = 0.1;
const std::string ZOMBIE_PIC_PATH = "extrafile/Zombi.png";

RegularZombie::RegularZombie() : Zombie(ZOMBIE_PIC_PATH, SCALE , SPEED , MAX_HEALTH , DAMAGE , HIT_RATE){}
