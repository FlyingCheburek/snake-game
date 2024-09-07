#include "Graphics.h"
#include <iostream>

using namespace Graphics;

Printer::Printer(const unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept {
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

std::string Printer::toString() const noexcept {
	return "{ brick: " + std::to_string(brick) + ", color: " + std::to_string(color) + " }";
}

void Printer::printText(std::string text) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	std::cout << text;
}

void Printer::printText(std::string text, const COORD cursor_pos) noexcept {
	WindowsServices::TerminalGraphics::setCursorPosition(cursor_pos);
	std::cout << text;
}

void Printer::printText(std::string text, const WindowsServices::TerminalGraphics::Color&& color) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	std::cout << text;
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}

void Printer::printText(std::string text, const COORD cursor_pos, const WindowsServices::TerminalGraphics::Color&& color) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	WindowsServices::TerminalGraphics::setCursorPosition(cursor_pos);
	std::cout << text;
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}

void Printer::printBrick(short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
}

void Printer::printBrick(const COORD cursor_pos, short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setCursorPosition(cursor_pos);
	WindowsServices::TerminalGraphics::setTextColor(color);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
}

void Printer::printBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}

void Printer::printBrick(const COORD cursor_pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	WindowsServices::TerminalGraphics::setCursorPosition(cursor_pos);
	while (num_prints-- > 0) {
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}

void Printer::verticalPrintBrick(short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	if (num_prints-- > 0) std::cout << brick;
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	pos.X--;
	while (num_prints-- >= 0) {
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(pos);
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setCursorPosition(pos);
}

void Printer::verticalPrintBrick(const COORD cursor_pos, short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setCursorPosition(cursor_pos);
	WindowsServices::TerminalGraphics::setTextColor(color);
	if (num_prints-- > 0) std::cout << brick;
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	pos.X--;
	while (num_prints-- >= 0) {
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(pos);
		std::cout << brick;
	}
}

void Printer::verticalPrintBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	if (num_prints-- > 0) std::cout << brick;
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	pos.X--;
	while (num_prints-- >= 0) {
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(pos);
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}

void Printer::verticalPrintBrick(const COORD cursor_pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	WindowsServices::TerminalGraphics::setCursorPosition(cursor_pos);
	if (num_prints-- > 0) std::cout << brick;
	COORD pos = WindowsServices::TerminalGraphics::getCursorPosition();
	pos.X--;
	while (num_prints-- >= 0) {
		pos.Y++;
		WindowsServices::TerminalGraphics::setCursorPosition(pos);
		std::cout << brick;
	}
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}
