#include "SnakeGame.h"

int main() {
	SnakeGame::Game game;
	if (game.titleScreen()) {
		game.pauseScreen();
	} 
	return 0;
}