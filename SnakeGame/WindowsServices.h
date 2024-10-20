#pragma once
#include <Windows.h>
#include <string>

namespace WindowsServices {
	class AudioFile final {
	private:
		const std::string filename;
		static const wchar_t* getWC(const char* c) noexcept;
	public:
		AudioFile(const std::string&& filename, const std::string&& type = "") noexcept;
		void play(const bool&& wait) const noexcept;
		void replay(const bool&& wait) const noexcept;
		void loop() const noexcept;
		void pause() const noexcept;
		void resume() const noexcept;
		void forceStop() const noexcept;
		~AudioFile() noexcept;
	};

	class TerminalGraphics final {
	private:
		HANDLE handle;
		CONSOLE_SCREEN_BUFFER_INFO info;
	public:
		TerminalGraphics();
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
		void setCaretPosition(const COORD cursor_pos) noexcept;
		void setCaretPosition(const COORD *const cursor_pos) noexcept;
		COORD getCaretPosition() noexcept;
		WORD getTextColor() noexcept;
		void setTextColor(const unsigned short color) noexcept;
		void setTextColor(const unsigned short *const color) noexcept;
		void setDimensions(const unsigned short width, const unsigned short height) noexcept;
	}; 
}