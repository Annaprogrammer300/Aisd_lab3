#ifndef SORT_INCLUDE_RANDOM_H
#define SORT_INCLUDE_RANDOM_H

#include <random>
#include <vector>

// —татическое случайное устройство дл€ повышени€ эффективности
static std::random_device rd;
static std::mt19937 mt(rd());

int generate_rand_num(int min, int max) {
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}

std::vector<int> generate_random_vect(int min, int max, size_t length) {
	std::vector<int> vect;
	vect.reserve(length); // –езервирование пам€ти дл€ увеличени€ производительности
	for (size_t i = 0; i < length; ++i)
		vect.push_back(generate_rand_num(min, max));
	return vect;
}

std::vector<int> generate_sort_vect(size_t length) {
	std::vector<int> vect;
	vect.reserve(length); // –езервирование пам€ти дл€ увеличени€ производительности
	for (size_t i = 1; i <= length; ++i)
		vect.push_back(static_cast<int>(i));
	return vect;
}

std::vector<int> generate_reverse_sort_vect(size_t length) {
	std::vector<int> vect;
	vect.reserve(length); // –езервирование пам€ти дл€ увеличени€ производительности
	for (size_t i = length; i > 0; --i)
		vect.push_back(static_cast<int>(i));
	return vect;
}

#endif