#include "SnakeGame.h"

int main() {
	SnakeGame::Game game;
	if (game.titleScreen()) {
		while (true) {
			game.gameScreen();
			if (!game.gameOverScreen()) break;
		}
	}

	return 0;
}