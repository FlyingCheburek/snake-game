#pragma once
#include <Windows.h>
#include <string>

namespace WindowsServices {
	class AudioFile final {
	private:
		const std::string filename;
		static const wchar_t* getWC(const char* c) noexcept;
	public:
		AudioFile(const std::string&& filename, const std::string&& type) noexcept;
		void play(const bool&& wait) const noexcept;
		void replay(const bool&& wait) const noexcept;
		void loop() const noexcept;
		void pause() const noexcept;
		void resume() const noexcept;
		void forceStop() const noexcept;
		~AudioFile() noexcept;
	};

	class TerminalGraphics final {
	public:
		enum Color : unsigned short {
			BLACK,
			DARKBLUE,
			DARKGREEN,
			DARKCYAN,
			DARKRED,
			DARKMAGENTA,
			DARKYELLOW,
			DARKGRAY,
			GRAY,
			BLUE,
			GREEN,
			CYAN,
			RED,
			MAGENTA,
			YELLOW,
			WHITE
		};
		static void setCursorPosition(const COORD cursor_pos) noexcept;
		static void setTextColor(const Color color) noexcept; 
	}; 
}