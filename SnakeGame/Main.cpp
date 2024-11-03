#include "SnakeGame.h"

int main() {
	SnakeGame::Game game;
	while (true) {
		if (game.titleScreen()) {
restart:
			if (game.gameScreen()) 
				if (game.gameOverScreen()) goto restart;
			break;
		}
		else break;
	}
	return 0;
}