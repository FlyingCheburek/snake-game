#include "ComplexPrinter.h"

ComplexPrinter::ComplexPrinter() noexcept {  }
ComplexPrinter::ComplexPrinter(const unsigned char icon, const TerminalGraphics::Color default_color) noexcept : Printer(icon, default_color) {  }

void ComplexPrinter::printMatrix(const std::vector<std::vector<bool>>& matrix) const noexcept {
	ensureDefaultColor();
	for (const std::vector<bool>& row : matrix) {
		for (const bool& cell : row) {
			std::cout << (unsigned char)(cell ? icon : ' ');
		}
		std::cout << std::endl;
	}
}

void ComplexPrinter::printMatrix(const std::vector<std::vector<bool>>&& matrix) const noexcept{
	ensureDefaultColor();
	for (const std::vector<bool>& row : matrix) {
		for (const bool& cell : row) {
			std::cout << (unsigned char)(cell ? icon : ' ');
		}
		std::cout << std::endl;
	}
}
