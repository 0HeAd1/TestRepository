#pragma once
#include <stdexcept>

void ValidateRange(double a, double b) {
	if (a > b) throw std::invalid_argument("a must be less than or equal to b!");
}