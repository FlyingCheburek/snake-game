#pragma once
#include "WindowsServices.h"
#include <iostream>

using namespace WindowsServices;

class Printer {
protected:
	unsigned char icon; 
	unsigned short default_color;
	inline void ensureDefaultColor() const noexcept;

public:
	inline static TerminalGraphics console;

	Printer() noexcept;
	Printer(const unsigned char icon, const unsigned short default_color) noexcept;

	void setIcon(const unsigned char icon) noexcept;
	void setDefaultColor(const unsigned short default_color) noexcept;
	unsigned char getIcon() const noexcept;
	unsigned short getDefaultColor() const noexcept;

	void print(const char* text, unsigned short num_prints = 1) const noexcept;
	void printIcon(unsigned short num_prints = 1) const noexcept;
	void verticalPrint(const char* text, unsigned short num_prints = 1) const noexcept;
	void verticalPrintIcon(unsigned short num_prints = 1) const noexcept;

	friend std::ostream& operator<<(std::ostream& out, const Printer& printer);
};
