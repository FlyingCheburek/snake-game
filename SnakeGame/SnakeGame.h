#pragma once
#include "WindowsServices.h"
#include "ComplexPrinter.h"
#include "RandomIntGenerator.h"
#include <thread>
#include <atomic>
#include <conio.h>
#include <list>

namespace SnakeGame {
	class Keyboard {
	private:
		std::atomic<char> key_pressed;
		std::thread listener;

	public:
		Keyboard() noexcept;
		char getKeyPressed() const noexcept;
		void setKeyPressed(const char&& key) noexcept;
		void setKeyPressed(const char& key) noexcept;
		~Keyboard() noexcept;
		inline static const char ENTER = 13, ESC = 27, UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80;
	};

	class SoundFX {
	private:
		std::atomic<WindowsServices::AudioFile*> sound;
		std::atomic<bool> play = false;
		std::thread listener;

	public:
		SoundFX(WindowsServices::AudioFile* sound = nullptr) noexcept;
		void setSound(WindowsServices::AudioFile* sound, const bool&& play = false) noexcept;
		void setPlay(const bool&& play) noexcept;
		~SoundFX() noexcept;
	};

	struct Snake {
		std::list<COORD> body;
		const WindowsServices::TerminalGraphics::Color color;
		const unsigned char icon;
		Printer& printer;
		Snake(const WindowsServices::TerminalGraphics::Color color, Printer& printer, unsigned char&& icon) noexcept : color(color), body(std::list<COORD>()), printer(printer), icon(icon) {  }
		void draw_body() const noexcept;
		void erase_tail() noexcept;
		void move(const COORD& location, const bool&& eat = false);
	};

	class Game {
	private:
		static const short WIDTH = 75, HEIGHT = 40, WINDOW_WIDTH = 645, WINDOW_HEIGHT = 720, MAX_SCORE = 2773;
		inline static ComplexPrinter PRINTER = ComplexPrinter(219, WindowsServices::TerminalGraphics::WHITE);
		inline static Keyboard KEYBOARD = Keyboard();
		inline static SoundFX SOUND_FX = SoundFX();
		std::atomic<short> score = 0;
		void drawBorder() const noexcept; 
		void drawScoreboard() const noexcept;
		std::vector<COORD> board;

	public:
		bool titleScreen() const noexcept;
		bool pauseScreen() const noexcept;
		bool gameScreen() noexcept;
		bool gameOverScreen() const noexcept;
		void reloadGameScreen(const Snake& snake) const noexcept;
		void drawFruits() const noexcept;
		COORD* haveFruit(const Snake& snake, const COORD& location) const noexcept;
		std::vector<COORD*> fruits = std::vector<COORD*>();
		Game() noexcept {
			for (short y = 1; y < HEIGHT - 1; y++) {
				for (short x = 1; x < WIDTH - 1; x++) {
					board.push_back({x, y});
				}
			}
		}
	};
}

