#pragma once
#include "Printer.h"
#include <vector>

class ComplexPrinter final : public Printer {
public:

	struct CanvasCell {
		const unsigned char icon;
		const TerminalGraphics::Color color;
		CanvasCell(const unsigned char&& icon, const TerminalGraphics::Color&& color) noexcept;
	};

	ComplexPrinter() noexcept;
	ComplexPrinter(const unsigned char icon, const TerminalGraphics::Color default_color) noexcept;

	void printMatrix(const std::vector<std::vector<bool>>& matrix, const unsigned char false_icon = ' ', TerminalGraphics::Color false_color = console.BLACK) const noexcept;
	void printMatrix(const std::vector<std::vector<bool>>&& matrix, const unsigned char false_icon = ' ', TerminalGraphics::Color false_color = console.BLACK) const noexcept;
	void printCanvas(std::vector<std::vector<CanvasCell>>& canvas) const noexcept;
	void printCanvas(std::vector<std::vector<CanvasCell>>&& canvas) const noexcept;
};
