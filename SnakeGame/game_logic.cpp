#include "SnakeGame.h"
#include <algorithm>

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

void SnakeGame::Snake::move(const COORD& location, const bool&& eat) {
	body.emplace_front(location);
	printer.setDefaultColor(color);
	printer.setIcon(219);
	printer.console.setCaretPosition(&location);
	printer.printIcon();
	if (!eat) erase_tail();
}

void SnakeGame::Game::drawScoreboard() const noexcept {
	PRINTER.console.setCaretPosition({ 32, 0 });
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::YELLOW);
	PRINTER.print(("SCORE: " + std::to_string(score)).c_str());
}

void SnakeGame::Game::reloadGameScreen(const Snake& snake) const noexcept {
	drawBorder();
	PRINTER.setIcon(219);
	drawScoreboard();
	snake.draw_body();
	drawFruits();
}

void SnakeGame::Game::drawFruits() const noexcept {
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::RED);
	PRINTER.setIcon('@');
	for (const auto x : fruits) {
		PRINTER.console.setCaretPosition(x);
		PRINTER.printIcon();
	}
	PRINTER.setIcon(219);
}

COORD* SnakeGame::Game::haveFruit(const SnakeGame::Snake& snake, const COORD& location) const noexcept {
	for (const auto f : fruits) {
		if (location.X == f->X && location.Y == f->Y) return f;
	}
	return nullptr;
}

bool SnakeGame::Game::gameScreen() noexcept {
	RandomIntGenerator rand(0, board.size()-1);
	char state = Keyboard::LEFT;
	COORD location = { 36, 20 };
	fruits.clear();
	score = 0;
	for (short x = 0; x < 50; x++) {
		fruits.push_back(&board[rand.get_random()]);
	}
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
		if (location.X == 0 || location.Y == 0 || location.X == WIDTH-1 || location.Y == HEIGHT) return false;
		for (const COORD& c : snake.body) if (c.X == location.X && c.Y == location.Y) return false;
		COORD* fruit = haveFruit(snake, location);
		if (fruit) {
			SOUND_FX.setSound(&chomp, true);
			score++;
			drawScoreboard();
			snake.move(location, true);
			fruits.erase(std::remove(fruits.begin(), fruits.end(), fruit), fruits.end());
			if (fruits.size() < MAX_SCORE - snake.body.size()) {
				fruits.push_back(&board[rand.get_random()]);
			}
		}
		else if (score == MAX_SCORE) break;
		else snake.move(location);
		drawFruits();
		Sleep(100);
	}
	return true;
}