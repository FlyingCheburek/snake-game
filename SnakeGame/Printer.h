#pragma once
#include "WindowsServices.h"
#include <iostream>

using namespace WindowsServices;

class Printer {
protected:
	unsigned char icon; 
	TerminalGraphics::Color default_color;
	inline void ensureDefaultColor() const noexcept;

public:
	inline static TerminalGraphics console;

	Printer() noexcept;
	Printer(const unsigned char icon, const TerminalGraphics::Color default_color) noexcept;

	void setIcon(const unsigned char icon) noexcept;
	void setDefaultColor(const TerminalGraphics::Color default_color) noexcept;
	unsigned char getIcon() const noexcept;
	TerminalGraphics::Color getDefaultColor() const noexcept;

	void print(const char* text, unsigned short num_prints = 1) const noexcept;
	void printIcon(unsigned short num_prints = 1) const noexcept;
	void verticalPrint(const char* text, unsigned short num_prints = 1) const noexcept;
	void verticalPrintIcon(unsigned short num_prints = 1) const noexcept;

	friend std::ostream& operator<<(std::ostream& out, const Printer& printer);
};
