#include "Printer.h"

inline void Printer::ensureDefaultColor() const noexcept {
	if (console.getTextColor() != default_color) console.setTextColor(default_color);
}

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

void Printer::print(const char* text, unsigned short num_prints) const noexcept {
	ensureDefaultColor();
	while (num_prints--) std::cout << text;
}

void Printer::printIcon(unsigned short num_prints) const noexcept {
	ensureDefaultColor();
	while (num_prints--) std::cout << icon;
}

void Printer::verticalPrint(const char* text, unsigned short num_prints) const noexcept{
	ensureDefaultColor();
	COORD position = console.getCaretPosition();
	const char* head = text;
	while (num_prints--) {
		while (*text) {
			std::cout << *text;
			position.Y++;
			console.setCaretPosition(position);
			text++;
		}
		text = head;
	}
}

void Printer::verticalPrintIcon(unsigned short num_prints) const noexcept{
	ensureDefaultColor();
	COORD position = console.getCaretPosition();
	while (num_prints--) {
		std::cout << icon;
		position.Y++;
		console.setCaretPosition(position);
	}
}

std::ostream& operator<<(std::ostream& out, const Printer& printer) {
	return out << "{\"icon\": \"" << printer.icon << "\", \"default color\": " << printer.default_color << "}";
}