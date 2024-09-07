#pragma once
#include "WindowsServices.h"
#include <vector>

namespace Graphics {
	class Printer final {
	private:
		WindowsServices::TerminalGraphics::Color color;
		unsigned char brick;

	public:
		Printer(const unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept;

		void setBrick(const unsigned char&& brick) noexcept;
		unsigned char getBrick() const noexcept;
		void setColor(const WindowsServices::TerminalGraphics::Color&& color) noexcept;
		WindowsServices::TerminalGraphics::Color getColor() const noexcept;
		std::string toString() const noexcept;

		void printText(const std::string text) noexcept;
		void printText(const std::string text, const COORD cursor_pos) noexcept;
		void printText(const std::string text, const WindowsServices::TerminalGraphics::Color&& color) noexcept;
		void printText(const std::string text, const COORD cursor_pos, const WindowsServices::TerminalGraphics::Color&& color) noexcept;

		void printBrick(short&& num_prints = 1) noexcept;
		void printBrick(const COORD cursor_pos, short&& num_prints = 1) noexcept;
		void printBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) noexcept;
		void printBrick(const COORD cursor_pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) noexcept;

		void verticalPrintBrick(short&& num_prints = 1) noexcept;
		void verticalPrintBrick(const COORD cursor_pos, short&& num_prints = 1) noexcept;
		void verticalPrintBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) noexcept;
		void verticalPrintBrick(const COORD cursor_pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) noexcept;
	};
}
