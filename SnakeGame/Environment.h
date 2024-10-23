#pragma once
#include <atomic>
#include <thread>
#include <iostream>

namespace System {
	class Environment {
	private:
		std::atomic<char> key_pressed;
		std::thread key_listener;

	public:
		Environment() noexcept;
		char getKeyPressed() const noexcept;
	};
}
