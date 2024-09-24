#include "Printer.h"

Printer::Printer() noexcept {
	icon = 219; /* █ */
	default_color = TerminalGraphics::WHITE;
}

Printer::Printer(const unsigned char icon, const TerminalGraphics::Color default_color) noexcept {
	this->icon = icon;
	this->default_color = default_color;
}

void Printer::setIcon(const unsigned char icon) noexcept {
	this->icon = icon;
}

void Printer::setDefaultColor(const TerminalGraphics::Color default_color) noexcept {
	this->default_color = default_color;
}

unsigned char Printer::getIcon() const noexcept {
	return icon;
}

TerminalGraphics::Color Printer::getDefaultColor() const noexcept {
	return default_color;
}

std::ostream& operator<<(std::ostream& out, const Printer& printer) {
	return out << "{\"icon\": \"" << printer.icon << "\", \"default color\": " << printer.default_color << ", \"console\": \"" << &printer.console << "\"}";
}