#include <iostream>
#include "WindowsServices.h"
using namespace WindowsServices;

void TerminalGraphics::setCursorPosition(const int&& x, const int&& y) noexcept {
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void TerminalGraphics::setTextColor(const Color color) noexcept {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	SetConsoleTextAttribute(h, color);
}
