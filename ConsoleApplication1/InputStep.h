#pragma once
#include <stdexcept>

void ValidateStep(double step) {
	if (step <= 0) throw std::invalid_argument("step must be greater than 0!");
}