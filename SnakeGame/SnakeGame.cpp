#include "SnakeGame.h"

ComplexPrinter SnakeGame::Game::printer = ComplexPrinter(219, WindowsServices::TerminalGraphics::WHITE);

SnakeGame::Keyboard SnakeGame::Game::keyboard = SnakeGame::Keyboard();

void SnakeGame::Game::drawBorder() const noexcept {
	printer.setIcon(219);
	printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	printer.console.setDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
	printer.printIcon(WIDTH);
	printer.console.setCaretPosition({ 0, 1 });
	printer.verticalPrintIcon(HEIGHT);
	printer.console.setCaretPosition({ WIDTH - 1, 1 });
	printer.verticalPrintIcon(HEIGHT);
	printer.console.setCaretPosition({ 0, HEIGHT });
	printer.printIcon(WIDTH);
}

bool SnakeGame::Game::titleScreen() const noexcept {
	drawBorder();
	printer.setIcon(219);
	printer.setDefaultColor(WindowsServices::TerminalGraphics::DARKRED);
	short y = 1;
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({1, y});
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::GREEN);
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::DARKGREEN);
	for (short i = 0; i < 19; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::GREEN);
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::DARKRED);
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, {22, 14}, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{1, 0, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1},
	}, { 28, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 34, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{1, 0, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 1, 1},
	}, { 40, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	}, { 46, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.console.setCaretPosition({29, 20});
	printer.setDefaultColor(0x2E);
	printer.print("The ASCII Game");
	WindowsServices::AudioFile main_theme("giga_chad.mp3");
	printer.setDefaultColor(0x2F);
	printer.console.setCaretPosition({31, 23});
	printer.print("< PLAY >");
	printer.setDefaultColor(0x20);
	printer.console.setCaretPosition({ 31, 24 });
	printer.print("< QUIT >");
	main_theme.loop();
	char state = Keyboard::UP;
	while (true) {
		switch (keyboard.getKeyPressed()) {
			case Keyboard::DOWN:
				if (state == Keyboard::UP) {
					state = Keyboard::DOWN;
					printer.setDefaultColor(0x20);
					printer.console.setCaretPosition({ 31, 23 });
					printer.print("< PLAY >");
					printer.setDefaultColor(0x2F);
					printer.console.setCaretPosition({ 31, 24 });
					printer.print("< QUIT >");
				}
			break;
			case Keyboard::UP:
				if (state == Keyboard::DOWN) {
					state = Keyboard::UP;
					printer.setDefaultColor(0x2F);
					printer.console.setCaretPosition({ 31, 23 });
					printer.print("< PLAY >");
					printer.setDefaultColor(0x20);
					printer.console.setCaretPosition({ 31, 24 });
					printer.print("< QUIT >");
				}
			break;
			case Keyboard::ENTER:
				printer.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
				system("cls");
				if (state == Keyboard::UP) return true;
				else return false;
			break;
			case Keyboard::ESC:
				printer.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
				system("cls");
				return false;
			break;
		}
	}
}

bool SnakeGame::Game::pauseScreen() const noexcept {
	// TODO!
	drawBorder();
	while (true);
}

SnakeGame::Keyboard::Keyboard() noexcept {
	listener = std::thread([&](){
		while (true) {
			key_pressed.store(_getch());
		}
	});
}

char SnakeGame::Keyboard::getKeyPressed() const noexcept {
	return key_pressed.load();
}

SnakeGame::Keyboard::~Keyboard() noexcept {
	listener.detach();
}
