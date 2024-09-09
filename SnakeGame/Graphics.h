#pragma once
#include "WindowsServices.h"
#include <vector>

namespace Graphics {
	class Printer {
	protected:
		WindowsServices::TerminalGraphics::Color color;
		unsigned char brick;

	public:
		Printer(unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept;

		void setBrick(const unsigned char&& brick) noexcept;
		unsigned char getBrick() const noexcept;
		void setColor(const WindowsServices::TerminalGraphics::Color&& color) noexcept;
		WindowsServices::TerminalGraphics::Color getColor() const noexcept;

		virtual void printText(const std::string text) const noexcept;
		virtual void printText(const std::string text, const COORD cursor_pos) const noexcept;
		virtual void printText(const std::string text, const WindowsServices::TerminalGraphics::Color&& color) const noexcept;
		virtual void printText(const std::string text, const COORD cursor_pos, const WindowsServices::TerminalGraphics::Color&& color) const noexcept;

		virtual void printBrick(short&& num_prints = 1) const noexcept;
		virtual void printBrick(const COORD cursor_pos, short&& num_prints = 1) const noexcept;
		virtual void printBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) const noexcept;
		virtual void printBrick(const COORD cursor_pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) const noexcept;
	};

	class VerticalPrinter final : public Printer {
	public:
		VerticalPrinter(unsigned char&& brick, WindowsServices::TerminalGraphics::Color&& color) noexcept;
		void printText(const std::string text) const noexcept override;
		void printText(const std::string text, COORD cursor_pos) const noexcept override;
		void printText(const std::string text, const WindowsServices::TerminalGraphics::Color&& color) const noexcept override;
		void printText(const std::string text, const COORD cursor_pos, const WindowsServices::TerminalGraphics::Color&& color) const noexcept override;

		void printBrick(short&& num_prints = 1) const noexcept override;
		void printBrick(COORD cursor_pos, short&& num_prints = 1) const noexcept override;
		void printBrick(const WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) const noexcept override;
		void printBrick(COORD cursor_pos, WindowsServices::TerminalGraphics::Color&& color, short&& num_prints = 1) const noexcept override; 
	};
}
