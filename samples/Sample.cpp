#include <iostream>
#include "Polinom.h"

int main()
{
	int list[][2] = 
	{ 
		{2, 000},
		{2, 000}, 
		{5, 000},
		{8, 000} 
	};
	
	int list_len = sizeof(list) / (2 * sizeof(int));

	TPolinom poly_1(list, list_len);
	
	std::cout << "POLY_1 = " << poly_1;

	TPolinom poly_2(poly_1);
	
	std::cout << "POLY_2 = " << poly_2;

	std::cout << "POLY_1 + POLY_2 = " << poly_1 + poly_2;

	TPolinom poly_3;
	
	std::cout << "Input Polynom: " << std::endl;
	
	std::cin >> poly_3;
	
	std::cout << "POLY_3 = " << poly_3;

	std::cout << "CALCULATED POLY_1(3, 5, 2) = " << poly_1.CalculatePolynom(3, 5, 2);

	return 0;
}