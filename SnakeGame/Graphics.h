#pragma once
#include "WindowsServices.h"

namespace Graphics {
	class Printer {
	private:
		WindowsServices::TerminalGraphics::Color color;
		unsigned char brick;

	public:
		Printer(const unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept;

		void setBrick(const unsigned char&& brick) noexcept;
		unsigned char getBrick() const noexcept;
		void setColor(const WindowsServices::TerminalGraphics::Color&& color) noexcept;
		WindowsServices::TerminalGraphics::Color getColor() const noexcept;

		void printText(const std::string text) noexcept;
		void printText(const std::string text, const WindowsServices::TerminalGraphics::Color&& color) noexcept;
	};
}
