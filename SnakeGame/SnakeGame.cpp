#include "SnakeGame.h"

ComplexPrinter SnakeGame::Game::printer = ComplexPrinter(219, WindowsServices::TerminalGraphics::WHITE);

void SnakeGame::Game::drawBorder() const noexcept {
	printer.console.setDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
	printer.printIcon(WIDTH);
	printer.console.setCaretPosition({ 0, 1 });
	printer.verticalPrintIcon(HEIGHT);
	printer.console.setCaretPosition({ WIDTH - 1, 1 });
	printer.verticalPrintIcon(HEIGHT);
	printer.console.setCaretPosition({ 0, HEIGHT });
	printer.printIcon(WIDTH);
}

void SnakeGame::Game::titleScreen() noexcept {
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
	printer.console.setCaretPosition({10, 20});
	printer.setDefaultColor(0x2E);
	printer.print("The ASCII Game");
	while (true) {}
}