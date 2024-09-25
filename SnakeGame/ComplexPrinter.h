#pragma once
#include "Printer.h"
#include <vector>

class ComplexPrinter : public Printer {
public:
	ComplexPrinter() noexcept;
	ComplexPrinter(const unsigned char icon, const TerminalGraphics::Color default_color) noexcept;

	void printMatrix(const std::vector<std::vector<bool>>& matrix) const noexcept;
	void printMatrix(const std::vector<std::vector<bool>>&& matrix) const noexcept;
};
