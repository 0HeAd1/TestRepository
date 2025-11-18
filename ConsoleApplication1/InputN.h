#pragma once
#include <stdexcept>

int ValidateN(double n) {
	if (n != (int)n) throw std::invalid_argument("n must be an integer!");
	if ((int)n <= 1) throw std::invalid_argument("n must be greater than 1!");
	return (int)n;
}