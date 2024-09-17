#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"

int main(){
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Game game;
	while (game.running()){
		game.update();
		game.render();	
	}
    return 0;
}