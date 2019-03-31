#pragma once

#include <gtest.h>
#include "DatList.h"
#include "Polinom.h"

TEST(TPolinom, can_create_polinom_without_parametres)
{
	// NO ACTIONS

	EXPECT_NO_THROW(TPolinom Pol);
}

TEST(TPolinom, polinom_without_parametres_has_its_own_adress)
{
	TPolinom Pol;

	EXPECT_NE(&Pol,nullptr);
}

TEST(TPolinom, polinom_copied_by_constructer_is_equal_to_origin)
{
	const int size = 2;
	int mon[][2] = { { 5, 3 },{ 2, 4 } };
	TPolinom Pol1(mon, size);

	TPolinom Pol2 = Pol1;

	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, polinom_copied_by_constructer_has_its_own_adress)
{
	const int size = 2;
	int mon[][2] = { { 5, 3 },{ 2, 4 } };
	TPolinom Pol1(mon, size);

	TPolinom Pol2 = Pol1;

	EXPECT_NE(&Pol1,&Pol2);
}

TEST(TPolinom, can_compare_the_polynoms)
{
	const int size = 3;
	int mon[][2] = { { 1, 3 },{ 2, 4 },{ 2, 100 } };
	TPolinom Pol1(mon, size);
	TPolinom Pol2(mon, size);

	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_polynoms_and_they_are_equal)
{
	// Arrange
	const int size = 2;
	int mon[][2] = { { 5, 3 },{ 2, 4 } };
	TPolinom Pol1(mon, size);
	TPolinom Pol2;

	Pol2 = Pol1;

	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_assign_many_polynoms_and_they_are_equal)
{
	const int size = 2;
	int mon[][2] = { { 5, 3 },{ 2, 4 } };
	TPolinom Pol1(mon, size);
	TPolinom Pol2,Pol3;

	Pol3=Pol2 = Pol1;
	bool _check = (Pol1 == Pol2) && (Pol2 == Pol3) && (Pol1 == Pol3);

	EXPECT_TRUE(_check);
}

TEST(TPolinom, can_add_up_simple_polynoms)
{
	const int size1 = 3;
	const int size2 = 4;
	int mon1[][2] = { { 5, 2 },{ 8, 3 },{ 9, 4 } };
	int mon2[][2] = { { 1, 1 },{ -8, 3 },{ 1, 4 },{ 2, 5 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);

	TPolinom Pol= Pol1 + Pol2;

	const int expected_size = 4;
	int expected_mon[][2] = { { 1, 1 },{ 5, 2 },{ 10, 4 },{ 2, 5 } };
	// z+5z^2+10z^4+2z^5
	TPolinom check_Pol(expected_mon, expected_size);

	EXPECT_TRUE(Pol == check_Pol);
}

TEST(TPolinom, can_create_polinom_from_one_monom)
{
	int mon[][2] = { { 1, 3 } };

	TPolinom A(mon, 1);

	TMonom res(1, 3);
	EXPECT_EQ(res, (TMonom)(*A.GetMonom()));
}

TEST(TPolinom, can_create_polinom_from_two_monoms)
{
	const int size = 2;
	int mon[][2] = { { 1, 3 },{ 2, 4 } };

	TPolinom Pol(mon, size);

	TMonom monoms[size];
	for (int i = 0; i < size; i++)
		monoms[i] = TMonom(mon[i][0], mon[i][1]);
	for (int i = 0; i < size; i++, Pol.GoNext())
		EXPECT_EQ(monoms[i], *Pol.GetMonom());
}

TEST(TPolinom, can_create_pol_from_many_monoms)
{
	const int size = 10;
	int mon[][2] = { { 1, 3 },{ 2, 4 },{ 2, 100 },{ 3, 110 },
	{ 5, 150 },{ 6, 302 },{ 3, 400 },{ 2, 500 },{ 7 ,800 },{ 2, 888 } };

	TPolinom Pol(mon, size);

	TMonom monoms[size];
	for (int i = 0; i < size; i++)
		monoms[i] = TMonom(mon[i][0], mon[i][1]);
	for (int i = 0; i < size; i++, Pol.GoNext())
		EXPECT_EQ(monoms[i], *Pol.GetMonom());
}

TEST(TPolinom, can_assign_empty_polynom)
{
	TPolinom Pol1;
	TPolinom Pol2;

	Pol2 = Pol1;

	EXPECT_TRUE(Pol1 == Pol2);
}

TEST(TPolinom, can_add_up_linear_polynoms)
{
	const int size = 1;
	int mon1[][2] = { { 2, 1 } };
	int mon2[][2] = { { 1, 1 } };
	// 2z
	TPolinom Pol1(mon1, size);
	// z
	TPolinom Pol2(mon2, size);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 1;
	int expected_mon[][2] = { { 3, 1 } };
	// z+2z^2
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_polynoms)
{
	const int size1 = 5;
	const int size2 = 4;
	int mon1[][2] = { { 5, 213 },{ 8, 321 },{ 10, 432 },{ -21, 500 },{ 10, 999 } };
	int mon2[][2] = { { 15, 0 },{ -8, 321 },{ 1, 500 },{ 20, 702 } };
	// 5x^2yz^3+8x^3y^2z+10x^4y^3z^2-21x^5+10x^9y^9z^9
	TPolinom Pol1(mon1, size1);
	// 15-8x^3y^2z+x^5+20x^7z^2
	TPolinom Pol2(mon2, size2);

	TPolinom Pol = Pol1 + Pol2;

	const int expected_size = 6;
	int expected_mon[][2] = { { 15, 0 },{ 5, 213 },{ 10, 432 },{ -20, 500 },{ 20, 702 },{ 10, 999 } };
	// 15+5x^2yz^3+10x^4y^3z^2-20x^5+20x^7z^2+10x^9y^9z^9
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_add_up_many_polynoms)
{
	const int size1 = 3;
	const int size2 = 4;
	const int size3 = 3;
	int mon1[][2] = { { 5, 2 },{ 8, 3 },{ 9, 4 } };
	int mon2[][2] = { { 1, 1 },{ -8, 3 },{ 1, 4 },{ 2, 5 } };
	int mon3[][2] = { { 10, 0 },{ 2, 3 },{ 8, 5 } };
	// 5z^2+8z^3+9z^4
	TPolinom Pol1(mon1, size1);
	// z-8z^3+z^4+2z^5
	TPolinom Pol2(mon2, size2);
	// 10+2z^3+8z^5
	TPolinom Pol3(mon3, size3);

	TPolinom Pol = Pol1 + Pol2 + Pol3;

	const int expected_size = 6;
	int expected_mon[][2] = { { 10, 0 },{ 1, 1 },{ 5, 2 },{ 2, 3 },{ 10, 4 },{ 10, 5 } };
	// z+5z^2+10z^4+2z^5
	TPolinom expected_Pol(expected_mon, expected_size);
	EXPECT_TRUE(Pol == expected_Pol);
}

TEST(TPolinom, can_calculate_the_polinom_with_different_monoms)
{
	int size = 3;
	int mon[][2] = { { 1, 1 },{ 2, 10 },{ 3, 100 } };
	TPolinom Pol(mon, size);

	EXPECT_EQ(Pol.calculate(1, 1, 1), 6);
}

TEST(TPolinom, can_calculate_the_polinom_with_equal_monoms_with_different_coeffs)
{
	int size = 3;
	int mon[][2] = { { 1, 111 },{ -2, 111 },{ 3, 111 } };
	TPolinom Pol(mon, size);

	EXPECT_EQ(Pol.calculate(1, 1, 1), 2);
}

TEST(TPolinom, can_calculate_the_polinom_with_different_and_equals_monoms)
{
	int size = 3;
	int mon[][2] = { { 1, 111 },{ -1, 111 },{ 2, 11 } };
	TPolinom Pol(mon, size);

	EXPECT_EQ(Pol.calculate(1, 1, 1), 2);
}

TEST(TPolinom, can_calculate_the_empty_polinom_and_it_is_equal_null)
{
	TPolinom Pol;

	EXPECT_EQ(Pol.calculate(1, 1, 1), 0);
}