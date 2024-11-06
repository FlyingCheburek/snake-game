#pragma once
#include <random>

class RandomIntGenerator {
private:
	int64_t min, max;

public:
	RandomIntGenerator(const int64_t&& min, const int64_t&& max) noexcept;
	RandomIntGenerator(const int64_t& min, const int64_t& max) noexcept;
	void set_max(const int64_t&& max) noexcept;
	void set_min(const int64_t&& min) noexcept;
	int64_t get_max() const noexcept;
	int64_t get_min() const noexcept;
	int64_t get_random() const noexcept;
};
