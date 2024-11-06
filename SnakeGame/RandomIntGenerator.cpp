#include "RandomIntGenerator.h"

RandomIntGenerator::RandomIntGenerator(const int64_t&& min, const int64_t&& max) noexcept {
	this->min = min < max ? min : max;
	this->max = max > min ? max : min;
}

RandomIntGenerator::RandomIntGenerator(const int64_t& min, const int64_t& max) noexcept {
	this->min = min < max ? min : max;
	this->max = max > min ? max : min;
}

void RandomIntGenerator::set_max(const int64_t&& max) noexcept{
	this->max = max;
	if (max < min) {
		this->max ^= min;
		min ^= this->max;
		this->max ^= min;
	}
}

void RandomIntGenerator::set_min(const int64_t&& min) noexcept{
	this->min = min;
	if (min > max) {
		this->min ^= max;
		max ^= this->min;
		this->min ^= max;
	}
}

int64_t RandomIntGenerator::get_max() const noexcept{
	return max;
}

int64_t RandomIntGenerator::get_min() const noexcept{
	return min;
}

int64_t RandomIntGenerator::get_random() const noexcept {
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution<int64_t> gen(min, max);
	return gen(rng);
}
