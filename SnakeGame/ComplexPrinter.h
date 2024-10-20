#pragma once
#include "Printer.h"
#include <vector>

class ComplexPrinter final : public Printer {
public:

	struct CanvasCell {
		const unsigned char icon;
		const unsigned short color;
		CanvasCell(const unsigned char&& icon, const unsigned short&& color) noexcept;
	};

	ComplexPrinter() noexcept;
	ComplexPrinter(const unsigned char icon, const unsigned short default_color) noexcept;

	void printMatrix(const std::vector<std::vector<bool>>& matrix, COORD position = { 0,0 }, const unsigned char false_icon = ' ', unsigned short false_color = console.BLACK) const noexcept;
	void printMatrix(const std::vector<std::vector<bool>>&& matrix, COORD position = { 0,0 }, const unsigned char false_icon = ' ', unsigned short false_color = console.BLACK) const noexcept;
	void printCanvas(const std::vector<std::vector<CanvasCell>>& canvas) const noexcept;
	void printCanvas(const std::vector<std::vector<CanvasCell>>&& canvas) const noexcept;
};
