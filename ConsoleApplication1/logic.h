#pragma once

double calculateY(double x, int n) {
	double y;
	if (x < 0) {
		y = 1;
		for (double i = 1; i <= n + 1; i++) y *= (double)(x + 3) / (i - x);
	}
	else {
		y = (double)1 / (3 * x + 1);
		double sum = 0;
		for (double j = 0; j <= n + 1; j++) {
			double mult = 1.0;
			for (double i = 1; i <= n; i++) mult *= (i + (double)(j * j) / (i + x));
			sum += mult;
		}
		y -= sum;
	}
	return y;
}