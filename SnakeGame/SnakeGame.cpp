#include "SnakeGame.h"

ComplexPrinter SnakeGame::Game::printer = ComplexPrinter(219, WindowsServices::TerminalGraphics::WHITE);

SnakeGame::Keyboard SnakeGame::Game::keyboard = SnakeGame::Keyboard();
SnakeGame::SoundFX SnakeGame::Game::sound_fx = SnakeGame::SoundFX();

void SnakeGame::Game::drawBorder() const noexcept {
	printer.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
	system("cls");
	printer.setIcon(219);
	printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	printer.console.setDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
	printer.printIcon(WIDTH);
	printer.console.setCaretPosition({ 0, 1 });
	printer.verticalPrintIcon(HEIGHT);
	printer.console.setCaretPosition({ WIDTH - 1, 1 });
	printer.verticalPrintIcon(HEIGHT);
	printer.console.setCaretPosition({ 0, HEIGHT });
	printer.printIcon(WIDTH);
}

bool SnakeGame::Game::titleScreen() const noexcept {
	drawBorder();
	printer.setIcon(219);
	printer.setDefaultColor(WindowsServices::TerminalGraphics::DARKRED);
	short y = 1;
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({1, y});
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::GREEN);
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::DARKGREEN);
	for (short i = 0; i < 19; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::GREEN);
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::DARKRED);
	for (short i = 0; i < 5; i++, y++) {
		printer.console.setCaretPosition({ 1, y });
		printer.printIcon(WIDTH - 2);
	}
	printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, {22, 14}, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{1, 0, 0, 0, 1},
		{1, 1, 0, 0, 1},
		{1, 0, 1, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 0, 0, 0, 1},
	}, { 28, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 34, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{1, 0, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 0, 0, 1, 1},
	}, { 40, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	}, { 46, 14 }, 219, WindowsServices::TerminalGraphics::DARKGREEN);
	printer.console.setCaretPosition({29, 20});
	printer.setDefaultColor(0x2E);
	printer.print("The ASCII Game");
	printer.setDefaultColor(0x2A);
	printer.console.setCaretPosition({ 25, 27 });
	printer.print("Flying Cheburek © 2024");
	printer.setDefaultColor(0x2F);
	printer.console.setCaretPosition({31, 23});
	printer.print("< PLAY >");
	printer.setDefaultColor(0x20);
	printer.console.setCaretPosition({ 31, 24 });
	printer.print("< QUIT >");
	WindowsServices::AudioFile main_theme("giga_chad.mp3"), click("click.mp3"), swipe("swipe.mp3");
	main_theme.loop();
	char state = Keyboard::UP;
	while (true) {
		switch (keyboard.getKeyPressed()) {
			case Keyboard::DOWN:
				if (state == Keyboard::UP) {
					sound_fx.setSound(&swipe, true);
					state = Keyboard::DOWN;
					printer.setDefaultColor(0x20);
					printer.console.setCaretPosition({ 31, 23 });
					printer.print("< PLAY >");
					printer.setDefaultColor(0x2F);
					printer.console.setCaretPosition({ 31, 24 });
					printer.print("< QUIT >");
				}
			break;
			case Keyboard::UP:
				if (state == Keyboard::DOWN) {
					sound_fx.setSound(&swipe, true);
					state = Keyboard::UP;
					printer.setDefaultColor(0x2F);
					printer.console.setCaretPosition({ 31, 23 });
					printer.print("< PLAY >");
					printer.setDefaultColor(0x20);
					printer.console.setCaretPosition({ 31, 24 });
					printer.print("< QUIT >");
				}
			break;
			case Keyboard::ENTER:
				sound_fx.setSound(&click, true);
				printer.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
				system("cls");
				if (state == Keyboard::UP) return true;
				else return false;
			break;
			case Keyboard::ESC:
				sound_fx.setSound(&click, true);
				printer.console.setTextColor(WindowsServices::TerminalGraphics::BLACK);
				system("cls");
				return false;
			break;
		}
	}
}

bool SnakeGame::Game::pauseScreen() const noexcept {
	drawBorder();
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
	}, {21, 16});
	printer.printMatrix({
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	}, { 27, 16 });
	printer.printMatrix({
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, { 33, 16 });
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}, { 39, 16 });
	printer.printMatrix({
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1},
	}, { 45, 16 });
	printer.setDefaultColor(WindowsServices::TerminalGraphics::YELLOW);
	printer.console.setCaretPosition({ 32, 23 });
	printer.print((std::string("SCORE: ") + std::to_string(score.load())).c_str());
	printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
	printer.console.setCaretPosition({ 30, 26 });
	printer.print("< CONTINUE >");
	printer.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
	printer.console.setCaretPosition({ 32, 27 });
	printer.print("< QUIT >");
	char state = Keyboard::UP;
	keyboard.setKeyPressed((char)Keyboard::UP);
	WindowsServices::AudioFile click("click.mp3"), swipe("swipe.mp3");
	while (true) {
		switch (keyboard.getKeyPressed()) {
		case Keyboard::DOWN:
			if (state == Keyboard::UP) {
				sound_fx.setSound(&swipe, true);
				state = Keyboard::DOWN;
				printer.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
				printer.console.setCaretPosition({ 30, 26 });
				printer.print("< CONTINUE >");
				printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
				printer.console.setCaretPosition({ 32, 27 });
				printer.print("< QUIT >");
			}
			break;
		case Keyboard::UP:
			if (state == Keyboard::DOWN) {
				sound_fx.setSound(&swipe, true);
				state = Keyboard::UP;
				printer.setDefaultColor(WindowsServices::TerminalGraphics::WHITE);
				printer.console.setCaretPosition({ 30, 26 });
				printer.print("< CONTINUE >");
				printer.setDefaultColor(WindowsServices::TerminalGraphics::GRAY);
				printer.console.setCaretPosition({ 32, 27 });
				printer.print("< QUIT >");
			}
			break;
		case Keyboard::ENTER:
			sound_fx.setSound(&click, true);
			printer.setDefaultColor(WindowsServices::TerminalGraphics::BLACK);
			system("cls");
			if (state == Keyboard::UP) return true;
			else return false;
			break;
		case Keyboard::ESC:
			sound_fx.setSound(&click, true);
			printer.setDefaultColor(WindowsServices::TerminalGraphics::BLACK);
			system("cls");
			return true;
			break;
		}
	}
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
