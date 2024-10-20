#include "ComplexPrinter.h"

ComplexPrinter::CanvasCell::CanvasCell(const unsigned char&& icon, const unsigned short&& color) noexcept : icon(icon), color(color) {  }
ComplexPrinter::ComplexPrinter() noexcept {  }
ComplexPrinter::ComplexPrinter(const unsigned char icon, const unsigned short default_color) noexcept : Printer(icon, default_color) {  }

void ComplexPrinter::printMatrix(const std::vector<std::vector<bool>>& matrix, COORD position, const unsigned char false_icon, unsigned short false_color) const noexcept{
	ensureDefaultColor();
	console.setCaretPosition(&position);
	for (const std::vector<bool>& row : matrix) {
		for (const bool& cell : row) {
			if (cell) {
				ensureDefaultColor();
				std::cout << icon;
			} 
			else {
				console.setTextColor(false_color);
				std::cout << false_icon;
			}
		}
		console.setCaretPosition({(short)(console.getCaretPosition().X - row.size()), position.Y++});
	}
	ensureDefaultColor();
}

void ComplexPrinter::printMatrix(const std::vector<std::vector<bool>>&& matrix, COORD position, const unsigned char false_icon, unsigned short false_color) const noexcept {
	ensureDefaultColor();
	console.setCaretPosition(&position);
	for (const std::vector<bool>& row : matrix) {
		for (const bool& cell : row) {
			if (cell) {
				ensureDefaultColor();
				std::cout << icon;
			}
			else {
				console.setTextColor(false_color);
				std::cout << false_icon;
			}
		}
		console.setCaretPosition({ (short)(console.getCaretPosition().X - row.size()), ++position.Y });
	}
	ensureDefaultColor();
}

void ComplexPrinter::printCanvas(const std::vector<std::vector<CanvasCell>>& canvas) const noexcept{
	for (const std::vector<CanvasCell>& row : canvas) {
		for (const CanvasCell& cell : row) {
			console.setTextColor(cell.color);
			std::cout << cell.icon;
		}
		std::cout << std::endl;
	}
	ensureDefaultColor();
}

void ComplexPrinter::printCanvas(const std::vector<std::vector<CanvasCell>>&& canvas) const noexcept {
	for (const std::vector<CanvasCell>& row : canvas) {
		for (const CanvasCell& cell : row) {
			console.setTextColor(cell.color);
			std::cout << cell.icon;
		}
		std::cout << std::endl;
	}
	ensureDefaultColor();
}
