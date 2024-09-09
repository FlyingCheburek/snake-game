#include "Graphics.h"
#include <iostream>

using namespace Graphics;

Printer::Printer(unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept {
	this->brick = brick;
	this->color = color;
}

void Printer::setBrick(const unsigned char&& brick) noexcept {
	this->brick = brick;
}

unsigned char Printer::getBrick() const noexcept {
	return brick;
}

void Printer::setColor(const WindowsServices::TerminalGraphics::Color&& color) noexcept {
	this->color = color;
}

WindowsServices::TerminalGraphics::Color Printer::getColor() const noexcept {
	return color;
}

void Printer::printText(const std::string text) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	std::cout << text;
}

void Printer::printText(const std::string text, const COORD pos) const noexcept {
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	std::cout << text;
}

void Printer::printText(const std::string text, const WindowsServices::TerminalGraphics::Color&& color) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	std::cout << text;
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}

void Printer::printText(const std::string text, const COORD pos, const WindowsServices::TerminalGraphics::Color&& color) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	std::cout << text;
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}

void Printer::printBrick(short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
}

void Printer::printBrick(const COORD pos, short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	WindowsServices::TerminalGraphics::setTextColor(&color);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
}

void Printer::printBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}

void Printer::printBrick(const COORD pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) const noexcept {
	WindowsServices::TerminalGraphics::setTextColor(&color);
	WindowsServices::TerminalGraphics::setCursorPosition(&pos);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setTextColor(&this->color);
}

