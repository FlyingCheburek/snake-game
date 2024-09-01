#pragma once
#include <Windows.h>
#include <string>

namespace WindowsServices {
	class AudioFile final {
	private:
		const std::string filename;
		static const wchar_t* GetWC(const char* c) noexcept;
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

	class TerminalGraphics final {  }; //to-be added
}