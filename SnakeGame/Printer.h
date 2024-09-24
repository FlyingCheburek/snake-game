#pragma once
#include "WindowsServices.h"
#include <iostream>

using namespace WindowsServices;

class Printer {
protected:
	unsigned char icon; 
	TerminalGraphics::Color default_color;

public:
	TerminalGraphics console;

	Printer() noexcept;
	Printer(const unsigned char icon, const TerminalGraphics::Color default_color) noexcept;

	void setIcon(const unsigned char icon) noexcept;
	void setDefaultColor(const TerminalGraphics::Color default_color) noexcept;
	unsigned char getIcon() const noexcept;
	TerminalGraphics::Color getDefaultColor() const noexcept;

	friend std::ostream& operator<<(std::ostream& out, const Printer& printer);
};
