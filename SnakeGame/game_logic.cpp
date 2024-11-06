#include "SnakeGame.h"

void SnakeGame::Snake::draw_body() const noexcept {
	printer.setDefaultColor(color);
	for (const COORD& coord : body) {
		printer.console.setCaretPosition(coord);
		printer.printIcon();
	}
}

void SnakeGame::Snake::erase_tail() noexcept {
	printer.setDefaultColor(WindowsServices::TerminalGraphics::BLACK);
	printer.console.setCaretPosition(body.back());
	printer.printIcon();
	body.pop_back();
}

void SnakeGame::Snake::move(const COORD& location) {
	body.emplace_front(location);
	printer.setDefaultColor(color);
	printer.console.setCaretPosition(&location);
	printer.printIcon();
	erase_tail();
}

void SnakeGame::Game::reloadGameScreen(const Snake& snake) const noexcept {
	drawBorder();
	PRINTER.setIcon(219);
	PRINTER.console.setCaretPosition({ 32, 0 });
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::YELLOW);
	PRINTER.print(("SCORE: " + std::to_string(score.load())).c_str());
	snake.draw_body();
}

bool SnakeGame::Game::gameScreen() noexcept {
	char state = Keyboard::LEFT;
	COORD location = { 36, 20 };
	Snake snake(WindowsServices::TerminalGraphics::GREEN, PRINTER, 219);
	snake.body.emplace_front(location);
	WindowsServices::AudioFile click("click.mp3"), chomp("swipe.mp3");
	SOUND_FX.setSound(&chomp);
	reloadGameScreen(snake);
	while (true) {
		switch (KEYBOARD.getKeyPressed()) {
			case Keyboard::ESC:
				SOUND_FX.setSound(&click, true);
				if (pauseScreen()) {
					reloadGameScreen(snake);
					KEYBOARD.setKeyPressed(state);
					SOUND_FX.setSound(&chomp);
				}
				else return false;
			break;
			case Keyboard::UP:
				state = Keyboard::UP;
			break;
			case Keyboard::DOWN:
				state = Keyboard::DOWN;
			break;
			case Keyboard::LEFT:
				state = Keyboard::LEFT;
			break;
			case Keyboard::RIGHT:
				state = Keyboard::RIGHT;
			break;
		}
		location.X += state == Keyboard::LEFT ? -1 : state == Keyboard::RIGHT ? 1 : 0;
		location.Y += state == Keyboard::UP ? -1 : state == Keyboard::DOWN ? 1 : 0;
		snake.move(location);
		Sleep(200);
	}
	return true;
}