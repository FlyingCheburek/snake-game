#pragma once
#include "WindowsServices.h"
#include "ComplexPrinter.h"

namespace SnakeGame {
	class Game {
	private:
		static ComplexPrinter printer;
		static const short WIDTH = 75, HEIGHT = 40, WINDOW_WIDTH = 645, WINDOW_HEIGHT = 720;
		void drawBorder() const noexcept;
	public:
		void titleScreen() noexcept;
	};
}

