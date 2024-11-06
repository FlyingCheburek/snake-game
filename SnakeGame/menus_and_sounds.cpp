#include "SnakeGame.h"

void SnakeGame::Game::drawBorder() const noexcept {
	PRINTER.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
	system("cls");
	PRINTER.setIcon(219);
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	PRINTER.console.setDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
	PRINTER.printIcon(WIDTH);
	PRINTER.console.setCaretPosition({ 0, 1 });
	PRINTER.verticalPrintIcon(HEIGHT);
	PRINTER.console.setCaretPosition({ WIDTH - 1, 1 });
	PRINTER.verticalPrintIcon(HEIGHT);
	PRINTER.console.setCaretPosition({ 0, HEIGHT });
	PRINTER.printIcon(WIDTH);
}

bool SnakeGame::Game::titleScreen() const noexcept {
	drawBorder();
	PRINTER.setIcon(219);
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::DARKRED);
	short y = 1;
	for (short i = 0; i < 5; i++, y++) {
		PRINTER.console.setCaretPosition({1, y});
		PRINTER.printIcon(WIDTH - 2);
	}
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GREEN);
	for (short i = 0; i < 5; i++, y++) {
		PRINTER.console.setCaretPosition({ 1, y });
		PRINTER.printIcon(WIDTH - 2);
	}
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::DARKGREEN);
	for (short i = 0; i < 19; i++, y++) {
		PRINTER.console.setCaretPosition({ 1, y });
		PRINTER.printIcon(WIDTH - 2);
	}
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GREEN);
	for (short i = 0; i < 5; i++, y++) {
		PRINTER.console.setCaretPosition({ 1, y });
		PRINTER.printIcon(WIDTH - 2);
	}
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::DARKRED);
	for (short i = 0; i < 5; i++, y++) {
		PRINTER.console.setCaretPosition({ 1, y });
		PRINTER.printIcon(WIDTH - 2);
	}
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, {22, 14}, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	PRINTER.printMatrix({
		{1, 0, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1},
	}, { 28, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	PRINTER.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 34, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	PRINTER.printMatrix({
		{1, 0, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 1, 1},
	}, { 40, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	}, { 46, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	PRINTER.console.setCaretPosition({29, 20});
	PRINTER.setDefaultColor(0x2E);
	PRINTER.print("The ASCII Game");
	PRINTER.setDefaultColor(0x2A);
	PRINTER.console.setCaretPosition({ 25, 27 });
	PRINTER.print("Flying Cheburek © 2024");
	PRINTER.setDefaultColor(0x2F);
	PRINTER.console.setCaretPosition({31, 23});
	PRINTER.print("< PLAY >");
	PRINTER.setDefaultColor(0x20);
	PRINTER.console.setCaretPosition({ 31, 24 });
	PRINTER.print("< QUIT >");
	WindowsServices::AudioFile main_theme("giga_chad.mp3"), click("click.mp3"), swipe("swipe.mp3");
	main_theme.loop();
	char state = Keyboard::UP;
	KEYBOARD.setKeyPressed((char)Keyboard::UP);
	while (true) {
		switch (KEYBOARD.getKeyPressed()) {
			case Keyboard::DOWN:
				if (state == Keyboard::UP) {
					SOUND_FX.setSound(&swipe, true);
					state = Keyboard::DOWN;
					PRINTER.setDefaultColor(0x20);
					PRINTER.console.setCaretPosition({ 31, 23 });
					PRINTER.print("< PLAY >");
					PRINTER.setDefaultColor(0x2F);
					PRINTER.console.setCaretPosition({ 31, 24 });
					PRINTER.print("< QUIT >");
				}
			break;
			case Keyboard::UP:
				if (state == Keyboard::DOWN) {
					SOUND_FX.setSound(&swipe, true);
					state = Keyboard::UP;
					PRINTER.setDefaultColor(0x2F);
					PRINTER.console.setCaretPosition({ 31, 23 });
					PRINTER.print("< PLAY >");
					PRINTER.setDefaultColor(0x20);
					PRINTER.console.setCaretPosition({ 31, 24 });
					PRINTER.print("< QUIT >");
				}
			break;
			case Keyboard::ENTER:
				SOUND_FX.setSound(&click, true);
				PRINTER.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
				system("cls");
				if (state == Keyboard::UP) return true;
				else return false;
			break;
			case Keyboard::ESC:
				SOUND_FX.setSound(&click, true);
				PRINTER.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
				system("cls");
				return false;
			break;
		}
	}
}

bool SnakeGame::Game::pauseScreen() const noexcept {
	drawBorder();
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
	}, {21, 16});
	PRINTER.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 27, 16 });
	PRINTER.printMatrix({
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, { 33, 16 });
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, { 39, 16 });
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	}, { 45, 16 });
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::YELLOW);
	PRINTER.console.setCaretPosition({ 32, 23 });
	PRINTER.print((std::string("SCORE: ") + std::to_string(score.load())).c_str());
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	PRINTER.console.setCaretPosition({ 30, 26 });
	PRINTER.print("< CONTINUE >");
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
	PRINTER.console.setCaretPosition({ 32, 27 });
	PRINTER.print("< QUIT >");
	char state = Keyboard::UP;
	KEYBOARD.setKeyPressed((char)Keyboard::UP);
	WindowsServices::AudioFile click("click.mp3"), swipe("swipe.mp3");
	while (true) {
		switch (KEYBOARD.getKeyPressed()) {
		case Keyboard::DOWN:
			if (state == Keyboard::UP) {
				SOUND_FX.setSound(&swipe, true);
				state = Keyboard::DOWN;
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
				PRINTER.console.setCaretPosition({ 30, 26 });
				PRINTER.print("< CONTINUE >");
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
				PRINTER.console.setCaretPosition({ 32, 27 });
				PRINTER.print("< QUIT >");
			}
		break;
		case Keyboard::UP:
			if (state == Keyboard::DOWN) {
				SOUND_FX.setSound(&swipe, true);
				state = Keyboard::UP;
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
				PRINTER.console.setCaretPosition({ 30, 26 });
				PRINTER.print("< CONTINUE >");
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
				PRINTER.console.setCaretPosition({ 32, 27 });
				PRINTER.print("< QUIT >");
			}
		break;
		case Keyboard::ENTER:
			SOUND_FX.setSound(&click, true);
			PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::BLACK);
			system("cls");
			if (state == Keyboard::UP) return true;
			else return false;
		break;
		case Keyboard::ESC:
			SOUND_FX.setSound(&click, true);
			PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::BLACK);
			system("cls");
			return true;
		break;
		}
	}
}

bool SnakeGame::Game::gameOverScreen() const noexcept {
	drawBorder();
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, { 25, 7 });
	PRINTER.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 31, 7 });
	PRINTER.printMatrix({
		{1, 0, 0, 0, 1},
		{1, 1, 0, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 37, 7 });
	PRINTER.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	}, { 43, 7 });
	PRINTER.setDefaultColor(score.load() == MAX_SCORE ? WindowsServices::TerminalGraphics::GREEN : WindowsServices::TerminalGraphics::RED);
	PRINTER.printMatrix({
		{0, 0, 1, 1, 0},
		{0, 1, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 1, 0},
		{0, 1, 1, 0, 0},
	}, { 25, 13 });
	PRINTER.printMatrix({
		{1, 0, 0, 0, 1},
		{0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0},
		{0, 0, 1, 0, 0},
	}, { 31, 13 });
	PRINTER.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 0, 0},
		{1, 0, 0, 0, 1},
		{0, 1, 1, 1, 0},
	}, { 37, 13 });
	PRINTER.printMatrix({
		{0, 1, 1, 0},
		{1, 0, 0, 1},
		{1, 1, 1, 0},
		{1, 0, 1, 0},
		{1, 0, 0, 1},
	}, { 43, 13 });
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::YELLOW);
	PRINTER.console.setCaretPosition({ 32, 22 });
	PRINTER.print((std::string("SCORE: ") + std::to_string(score.load())).c_str());
	if (score.load() == MAX_SCORE) {
		PRINTER.setDefaultColor(0xF0);
		PRINTER.console.setCaretPosition({ 23, 19 });
		PRINTER.print("Congratulations for winning!");
	}
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	PRINTER.console.setCaretPosition({ 31, 26 });
	PRINTER.print("< RESTART >");
	PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
	PRINTER.console.setCaretPosition({ 32, 27 });
	PRINTER.print("< QUIT >");
	WindowsServices::AudioFile game_over(score.load() == MAX_SCORE ? "master_system.mp3" : "ylimd.mp3"), click("click.mp3"), swipe("swipe.mp3");
	game_over.loop();
	char state = Keyboard::UP;
	KEYBOARD.setKeyPressed((char)Keyboard::UP);
	while (true) {
		switch (KEYBOARD.getKeyPressed()) {
		case Keyboard::DOWN:
			if (state == Keyboard::UP) {
				SOUND_FX.setSound(&swipe, true);
				state = Keyboard::DOWN;
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
				PRINTER.console.setCaretPosition({ 31, 26 });
				PRINTER.print("< RESTART >");
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
				PRINTER.console.setCaretPosition({ 32, 27 });
				PRINTER.print("< QUIT >");
			}
		break;
		case Keyboard::UP:
			if (state == Keyboard::DOWN) {
				SOUND_FX.setSound(&swipe, true);
				state = Keyboard::UP;
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
				PRINTER.console.setCaretPosition({ 31, 26 });
				PRINTER.print("< RESTART >");
				PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
				PRINTER.console.setCaretPosition({ 32, 27 });
				PRINTER.print("< QUIT >");
			}
		break;
		case Keyboard::ENTER:
			SOUND_FX.setSound(&click, true);
			PRINTER.setDefaultColor(WindowsServices::TerminalGraphics::BLACK);
			system("cls");
			if (state == Keyboard::UP) return true;
			else return false;
		break;
		}
	}
	return false;
}

SnakeGame::Keyboard::Keyboard() noexcept {
	listener = std::thread([&](){
		while (true) {
			key_pressed.store(_getch());
		}
	});
}

char SnakeGame::Keyboard::getKeyPressed() const noexcept {
	return key_pressed.load();
}

void SnakeGame::Keyboard::setKeyPressed(const char&& key) noexcept {
	key_pressed.store(key);
}
void SnakeGame::Keyboard::setKeyPressed(const char& key) noexcept {
	key_pressed.store(key);
}

SnakeGame::Keyboard::~Keyboard() noexcept {
	listener.detach();
}

SnakeGame::SoundFX::SoundFX(WindowsServices::AudioFile* sound) noexcept : sound(sound) {
	listener = std::thread([&](){
		while (true) {
			if (play.load()) {
				if (this->sound.load()) this->sound.load()->play();
				play.store(false);
			}
		}
	});
}

void SnakeGame::SoundFX::setSound(WindowsServices::AudioFile* sound, const bool&& play) noexcept {
	this->sound.store(sound);
	this->play.store(play);
}

void SnakeGame::SoundFX::setPlay(const bool&& play) noexcept {
	this->play.store(play);
}
	
SnakeGame::SoundFX::~SoundFX() noexcept {
	listener.detach();
}
