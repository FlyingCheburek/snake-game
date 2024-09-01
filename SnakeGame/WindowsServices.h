#pragma once
#include <Windows.h>
#include <string>

namespace WindowsServices {
	class AudioFile final {
	private:
		const std::string filename;
		static const wchar_t* GetWC(const char* c);
	public:
		AudioFile(const std::string&& filename, const std::string&& type);
		void play(bool wait);
		void replay(bool wait);
		void loop();
		void pause();
		void resume();
		void forceStop();
		~AudioFile();
	};

	class TerminalGraphics final {
		 
	};
}