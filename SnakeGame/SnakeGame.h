#pragma once
#include "WindowsServices.h"
#include "ComplexPrinter.h"
#include <thread>
#include <atomic>
#include <conio.h>

namespace SnakeGame {
	class Keyboard {
	private:
		std::atomic<char> key_pressed;
		std::thread listener;

	public:
		Keyboard() noexcept;
		char getKeyPressed() const noexcept;
		void setKeyPressed(const char&& key) noexcept;
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

	class Game {
	private:
		static ComplexPrinter printer;
		static const short WIDTH = 75, HEIGHT = 40, WINDOW_WIDTH = 645, WINDOW_HEIGHT = 720;
		static Keyboard keyboard;
		static SoundFX sound_fx;
		std::atomic<unsigned> score = 0;
		void drawBorder() const noexcept; 

	public:
		bool titleScreen() const noexcept;
		bool pauseScreen() const noexcept;
	};
}

