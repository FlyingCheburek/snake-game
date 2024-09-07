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

void Printer::printText(std::string text) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	std::cout << text;
}

void Printer::printText(std::string text, const WindowsServices::TerminalGraphics::Color&& color) noexcept {
	WindowsServices::TerminalGraphics::setTextColor(color);
	std::cout << text;
	WindowsServices::TerminalGraphics::setTextColor(this->color);
}
