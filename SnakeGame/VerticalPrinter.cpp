#include "Graphics.h"
#include <iostream>
using namespace Graphics;

VerticalPrinter::VerticalPrinter(unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept : Printer(std::move(brick), std::move(color)) {  }

void VerticalPrinter::printText(const std::string text) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	if (text.empty()) return;
	if (text.size() == 1) {
		std::cout << text;
		return;
	}
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	for (size_t x = 0; x < text.size(); x++) {
		std::cout << text[x];
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
}

void VerticalPrinter::printText(const std::string text, COORD pos) const noexcept {
	if (text.empty()) return;
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	if (text.size() == 1) {
		std::cout << text;
		return;
	}
	for (size_t x = 0; x < text.size(); x++) {
		std::cout << text[x];
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
}

void VerticalPrinter::printText(const std::string text, const WindowsServices::TerminalGraphics::Color&& color) const noexcept {
	if (text.empty()) return;
	WindowsServices::TerminalGraphics::setTextColor(&color);
	if (text.size() == 1) {
		std::cout << text;
		WindowsServices::TerminalGraphics::setTextColor(&this->color);
		return;
	}
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	for (size_t x = 0; x < text.size(); x++) {
		std::cout << text[x];
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}

void VerticalPrinter::printText(const std::string text, COORD pos, const WindowsServices::TerminalGraphics::Color&& color) const noexcept {
	if (text.empty()) return;
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	WindowsServices::TerminalGraphics::setTextColor(&color);
	if (text.size() == 1) {
		std::cout << text;
		WindowsServices::TerminalGraphics::setTextColor(&this->color);
		return;
	}
	for (size_t x = 0; x < text.size(); x++) {
		std::cout << text[x];
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
}

void VerticalPrinter::printBrick(short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	if (num_prints <= 0) return;
	if (num_prints == 1) {
		std::cout << brick;
		return;
	}
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	while (num_prints-- > 0) {
		std::cout << brick;
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
}

void VerticalPrinter::printBrick(COORD pos, short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	while (num_prints-- > 0) {
		std::cout << brick;
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
}

void VerticalPrinter::printBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	if (num_prints <= 0) return;
	if (num_prints == 1) {
		std::cout << brick;
		WindowsServices::TerminalGraphics::setTextColor(&this->color);
		return;
	}
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	while (num_prints-- > 0) {
		std::cout << brick;
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}

void VerticalPrinter::printBrick(COORD pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	if (num_prints <= 0) return;
	if (num_prints == 1) {
		std::cout << brick;
		WindowsServices::TerminalGraphics::setTextColor(&this->color);
		return;
	}
	while (num_prints-- > 0) {
		std::cout << brick;
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	}
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}