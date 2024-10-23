#include "Environment.h"

System::Environment::Environment() noexcept {
	char key;

	key_listener = std::thread([&](){
		while (true) {
			std::cin >> key;
		}
	});
}

char System::Environment::getKeyPressed() const noexcept{
	return key_pressed.load();
}
