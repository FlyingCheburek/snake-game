#include "WindowsServices.h"
#include <iostream>

int main() {
	WindowsServices::TerminalGraphics console;
	console.setTextColor(console.YELLOW);
	console.setCaretPosition({10, 5});
	std::cout << "teste";
	WindowsServices::AudioFile audio("giga_chad.mp3");
	audio.play(true);
	return 0;
}