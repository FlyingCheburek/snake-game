#include "SnakeGame.h"

int main() {
	SnakeGame::Game game;
		if (game.titleScreen()) {
			while (true) {
				if (game.gameScreen())
					if (!game.gameOverScreen()) 
						break;
			}
		}
	return 0;
}