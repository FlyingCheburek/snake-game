#include <iostream>
#include "WindowsServices.h"
using namespace WindowsServices;

COORD TerminalGraphics::getCursorPosition() noexcept {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(h, &csbi)) return csbi.dwCursorPosition;
	return { -1, -1 };
}

void TerminalGraphics::setCursorPosition(const COORD cursor_pos) noexcept {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleCursorPosition(h, cursor_pos);
}

void TerminalGraphics::setCursorPosition(const COORD *const cursor_pos) noexcept {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleCursorPosition(h, *cursor_pos);
}

void TerminalGraphics::setCursorXPosition(const short x) noexcept {
	COORD curr = getCursorPosition();
	curr.X = x;
	setCursorPosition(curr);
}

void TerminalGraphics::setCursorYPosition(const short y) noexcept {
	COORD curr = getCursorPosition();
	curr.Y = y;
	setCursorPosition(curr);
}

void TerminalGraphics::setTextColor(const Color color) noexcept {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(h, &csbi);
	wOldColorAttrs = csbi.wAttributes;
	SetConsoleTextAttribute(h, color);
}

void TerminalGraphics::setTextColor(const Color *const color) noexcept {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(h, &csbi);
	wOldColorAttrs = csbi.wAttributes;
	SetConsoleTextAttribute(h, *color);
}

