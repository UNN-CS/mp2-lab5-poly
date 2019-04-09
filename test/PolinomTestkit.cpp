#include <gtest.h>
#include "Polinom.h"

//--------------------------------------------------------------
//Tests for TMonom

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom a(5, 5));
}

TEST(TMonom, can_set_coeff)
{
	TMonom a(5, 5);
	a.SetCoeff(6);
	EXPECT_EQ(a.GetCoeff(), 6);
}

TEST(TMonom, can_set_index)
{
	TMonom a(5, 5);
	a.SetIndex(6);
	EXPECT_EQ(a.GetIndex(), 6);
}

TEST(TMonom, equal_operator_returns_true_on_equal_monoms)
{
	TMonom a(5, 5), b(5, 5);
	EXPECT_TRUE(a == b);
}

TEST(TMonom, equal_operator_returns_false_on_different_monoms)
{
	TMonom a(5, 5), b(6, 6);
	EXPECT_FALSE(a == b);
}

TEST(TMonom, can_compare_monoms)
{
	TMonom a(5, 222), b(5, 111);
	EXPECT_TRUE(b < a);
}

TEST(TMonom, can_assign_monoms)
{
	TMonom a(5, 222), b;
	b = a;
	EXPECT_TRUE(b == a);
}

TEST(TMonom, can_get_copy)
{
	TMonom a(5, 222);
	TMonom* b = (TMonom*)a.GetCopy();

	EXPECT_TRUE(*b == a);
}

//--------------------------------------------------------------
//Tests for TDatList

TEST(TDatList, can_create_list)
{
	ASSERT_NO_THROW(TDatList a);
}

TEST(TDatList, error_when_gonext_in_empty_list)
{
	TDatList a;
	EXPECT_EQ(1, a.GoNext());
}

TEST(TDatList, can_insert_elements)
{
	TDatList a;
	ASSERT_NO_THROW(a.InsFirst(new TMonom(1, 1)));
}

TEST(TDatList, can_insert_last_in_empty_list)
{
	TDatList a;
	ASSERT_NO_THROW(a.InsLast(new TMonom(1, 1)));
}

TEST(TDatList, can_insert_current_in_empty_list)
{
	TDatList a;
	ASSERT_NO_THROW(a.InsCurrent(new TMonom(1, 1)));
}



TEST(TDatList, can_get_first_element)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsFirst(new TMonom(i, i*i*i));
	a.Reset();
	TMonom res(4, 64);

	EXPECT_TRUE(res == *(TMonom*)a.GetDatValue());
}

TEST(TDatList, can_get_any_element)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(new TMonom(i, i*i*i));
	a.SetCurrentPos(3);
	TMonom res(3, 27);

	EXPECT_TRUE(res == *(TMonom*)a.GetDatValue());
}

TEST(TDatList, can_set_any_existent_position)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(new TMonom(i, i*i*i));
	ASSERT_NO_THROW(a.SetCurrentPos(3));
}

TEST(TDatList, cant_set_nonexistent_position)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(new TMonom(i, i*i*i));
	ASSERT_ANY_THROW(a.SetCurrentPos(15));
}

TEST(TDatList, cant_get_value_from_an_empty_list)
{
	TDatList a;
	ASSERT_ANY_THROW(a.GetDatValue());
}

TEST(TDatList, can_delete_first_element)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(new TMonom(i, i*i*i));
	a.DelFirst();
	a.Reset();
	TMonom res(1, 1);

	EXPECT_TRUE(res == *(TMonom*)a.GetDatValue());
}

TEST(TDatList, cant_delete_first_element_in_empty_list)
{
	TDatList a;
	ASSERT_ANY_THROW(a.DelFirst());
}

TEST(TDatList, can_delete_any_element)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(new TMonom(i, i*i*i));
	a.SetCurrentPos(3);
	a.DelCurrent();
	TMonom res(4, 64);

	EXPECT_TRUE(res == *(TMonom*)a.GetDatValue());
}

TEST(TDatList, can_delete_list)
{
	TDatList a;
	for (int i = 0; i < 5; i++)
		a.InsLast(new TMonom(i, i*i*i));
	a.DelList();
	EXPECT_TRUE(a.IsEmpty());
}

//--------------------------------------------------------------
//Tests for TPolinom

int pol1Arr[3][2] = {{1, 221},{2, 198},{5, 56}};
int pol2Arr[3][2] = {{ 3, 566 },{ 2, 322 },{ 65, 228 }};
int polSumArr[6][2] = {{3, 566 },{ 2, 322 },{ 65, 228 },{ 1, 221},{ 2, 198 },{ 5, 56 }};
int polNeg1Arr[3][2] = { { -1, 221 },{ -2, 198 },{ -5, 56 } };

TEST(TPolinom, can_create_polinom)
{
	ASSERT_NO_THROW(TPolinom a);
}

TEST(TPolinom, can_create_polinom_from_array)
{
	ASSERT_NO_THROW(TPolinom a(pol1Arr, 3));
}

TEST(TPolinom, cant_create_polinom_with_negative_number_of_monoms)
{
	ASSERT_ANY_THROW(TPolinom a(pol1Arr, -3));
}

TEST(TPolinom, can_create_polinom_from_another_polinom)
{
	TPolinom a(pol1Arr, 3), b(a);
	EXPECT_TRUE(a.GetCurrentPos() == b.GetCurrentPos());
}

TEST(TPolinom, can_assign_polinom)
{
	TPolinom a(pol1Arr, 3), b = a;
	EXPECT_TRUE(a.GetCurrentPos() == b.GetCurrentPos());
}

TEST(TPolinom, can_add_polinoms)
{
	TPolinom a(pol1Arr, 3), b(pol2Arr, 3);
	ASSERT_NO_THROW(a + b);
}

TEST(TPolinom, can_add_polinoms_correctly)
{
	TPolinom a(pol1Arr, 3), b(pol2Arr, 3), c(polSumArr, 6);
	auto d = a + b;
	EXPECT_EQ(d.GetCurrentPos(), c.GetCurrentPos());
}
