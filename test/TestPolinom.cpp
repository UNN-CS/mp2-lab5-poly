#include "Polinom.h"
#include <gtest.h>


TEST(TPolinom, can_create_poly_without_start_values)
{
	ASSERT_NO_THROW(TPolinom poly);
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_create_poly_with_values)
{
	int monom_arr[][2] = { {2, 123}, {331, 452}, {21, 525}, {3, 55} };
	int monom_size = sizeof(monom_arr) / (2 * sizeof(int));

	ASSERT_NO_THROW(TPolinom poly(monom_arr, monom_size));
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_copy_poly)
{
	int monom_arr[][2] = { {2, 123}, {331, 452}, {21, 525}, {3, 55} };
	int monom_size = sizeof(monom_arr) / (2 * sizeof(int));

	TPolinom poly(monom_arr, monom_size);

	ASSERT_NO_THROW(TPolinom poly_c(poly));
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_plus_polynoms)
{
	int monom_arr[][2] = { {2, 123}, {331, 452}, {21, 525}, {3, 55} };
	int monom_size = sizeof(monom_arr) / (2 * sizeof(int));

	TPolinom poly(monom_arr, monom_size);

	int monom_arr_1[][2] = { {2, 123}, {331, 452}, {21, 525}, {3, 55} };
	int monom_size_1 = sizeof(monom_arr) / (2 * sizeof(int));

	TPolinom poly_1(monom_arr_1, monom_size_1);

	ASSERT_NO_THROW(TPolinom poly_sum = poly + poly_1);
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_assign_polynom)
{
	int monom_arr[][2] = { {2, 123}, {331, 452}, {21, 525}, {3, 55} };
	int monom_size = sizeof(monom_arr) / (2 * sizeof(int));

	TPolinom poly(monom_arr, monom_size);
	ASSERT_NO_THROW(TPolinom poly_a = poly);
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_calculate_polynom)
{
	int monom_arr[][2] = { {2, 123}, {331, 452}, {21, 525}, {3, 55} };
	int monom_size = sizeof(monom_arr) / (2 * sizeof(int));

	TPolinom poly(monom_arr, monom_size);

	EXPECT_EQ(20610, poly.CalculatePolynom(3, 5, 2));
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_input_polynom)
{
	TPolinom poly;

	std::cout << "Input poly: ";

	ASSERT_NO_THROW(std::cin >> poly);
}
//--------------------------------------------------------------------------------
TEST(TPolinom, can_output_polynom)
{
	int monom_arr[][2] = { {23, 411}, {2, 452}, {5, 732}, {8, 878} };
	int monom_size = sizeof(monom_arr) / (2 * sizeof(int));

	TPolinom poly(monom_arr, monom_size);

	ASSERT_NO_THROW(std::cout << poly);
}
//--------------------------------------------------------------------------------