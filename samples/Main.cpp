#include <iostream>
#include "Polinom.h"

int main()
{
	int list[][2] = { {2, 000}, {2, 000}, {5, 000}, {8, 000} };
	int list_len = sizeof(list) / (2 * sizeof(int));

	TPolinom poly_1(list, list_len);
	std::cout << "POLY_01 = " << poly_1;

	TPolinom poly_2(poly_1);
	std::cout << "POLY_02 = " << poly_2;

	std::cout << "POLY_01 + POLY_02 = " << poly_1 + poly_2;

	TPolinom poly_3;
	std::cout << "Enter Polynom: " << std::endl;
	std::cin >> poly_3;
	std::cout << "POLY_03 = " << poly_3;

	std::cout << "CALCULATED POLY_01(4, 6, 9) = " << poly_1.CalculatePolynom(4, 6, 9);

	return 0;
}