#include <iostream>
#include "WindowsServices.h"
using namespace WindowsServices;

TerminalGraphics::TerminalGraphics() { 
	handle = nullptr;
	info = CONSOLE_SCREEN_BUFFER_INFO();
}

COORD TerminalGraphics::getCaretPosition() noexcept {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (GetConsoleScreenBufferInfo(handle, &info)) return info.dwCursorPosition;
	return { -1, -1 };
}

void TerminalGraphics::setCaretPosition(const COORD position) noexcept {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleCursorPosition(handle, position);
}

void TerminalGraphics::setCaretPosition(const COORD *const position) noexcept {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleCursorPosition(handle, *position);
}

WORD TerminalGraphics::getTextColor() noexcept {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &info);
	return info.wAttributes;
}

void TerminalGraphics::setTextColor(const Color color) noexcept {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

void TerminalGraphics::setTextColor(const Color *const color) noexcept {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, *color);
}

