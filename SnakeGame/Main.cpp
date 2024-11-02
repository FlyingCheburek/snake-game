#include "SnakeGame.h"

int main() {
	SnakeGame::Game game;
	if (game.titleScreen()) {
		game.pauseScreen();
		game.gameOverScreen();
	} 
	return 0;
}