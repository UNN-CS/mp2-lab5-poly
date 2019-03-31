#include "polinom.h"

#include <gtest.h>

TEST(TDatList, can_insert_first_if_empty)
{
	TDatList List;
	TMonom *monom = new TMonom(1, 111);
	List.InsFirst(monom);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, can_insert_first_if_no_empty)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	List.InsFirst(monom1);
	List.InsFirst(monom2);

	EXPECT_EQ(2, List.GetListLength());
}

TEST(TDatList, can_insert_last_if_empty)
{
	TDatList List;
	TMonom *monom = new TMonom(1, 111);
	List.InsLast(monom);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, can_insert_last_if_no_empty)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	List.InsLast(monom1);
	List.InsLast(monom2);

	EXPECT_EQ(2, List.GetListLength());
}

TEST(TDatList, can_insert_current_if_empty)
{
	TDatList List;
	TMonom *monom = new TMonom(1, 111);
	List.InsCurrent(monom);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, can_insert_current_if_no_empty_1)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.GoNext();
	List.InsCurrent(monom3);

	EXPECT_EQ(3, List.GetListLength());
}

TEST(TDatList, can_insert_current_if_no_empty_2)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.GoNext();
	List.InsCurrent(monom3);

	EXPECT_EQ(1, List.GetCurrentPos());
}

TEST(TDatList, can_insert_current_if_no_empty_3)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.GoNext();
	List.GoNext();
	List.InsCurrent(monom3);

	EXPECT_EQ(2, List.GetCurrentPos());
}

TEST(TDatList, cant_delete_first_empty_list)
{
	TDatList List;

	ASSERT_ANY_THROW(List.DelFirst());
}

TEST(TDatList, can_delete_first_single)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	List.InsFirst(monom1);
	List.DelFirst();

	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList, can_delete_first_1)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.DelFirst();

	EXPECT_FALSE(List.IsEmpty());
}

TEST(TDatList, can_delete_first_2)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.DelFirst();

	EXPECT_EQ(2, List.GetListLength());
}

TEST(TDatList, cant_delete_current_empty_list)
{
	TDatList List;

	ASSERT_ANY_THROW(List.DelCurrent());
}

TEST(TDatList, can_delete_current_single)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	List.InsFirst(monom1);
	List.DelCurrent();

	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList, can_delete_current_1)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.GoNext();
	List.GoNext();
	List.DelCurrent();

	EXPECT_FALSE(List.IsEmpty());
}

TEST(TDatList, can_delete_current_2)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.GoNext();
	List.GoNext();
	List.DelCurrent();

	EXPECT_EQ(2, List.GetListLength());
}

TEST(TDatList, can_delete_list_single_elements)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	List.InsFirst(monom1);
	List.DelList();

	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList, can_delete_list)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.DelList();

	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList, list_empty)
{
	TDatList List;

	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList, list_no_empty)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	List.InsFirst(monom1);

	EXPECT_FALSE(List.IsEmpty());
}

TEST(TDatList, list_empty_length)
{
	TDatList List;

	EXPECT_EQ(0, List.GetListLength());
}

TEST(TDatList, list_no_empty_length)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	List.InsFirst(monom1);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, can_set_current_position)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.SetCurrentPos(1);

	EXPECT_EQ(1, List.GetCurrentPos());
}

TEST(TDatList, can_get_current_position)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);

	EXPECT_EQ(0, List.GetCurrentPos());
}

TEST(TDatList, can_reset_current_position)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.GoNext();
	List.GoNext();
	List.Reset();

	EXPECT_EQ(0, List.GetCurrentPos());
}

TEST(TDatList, list_ended)
{
	TDatList List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.GoNext();
	List.GoNext();
	List.GoNext();

	EXPECT_TRUE(List.IsListEnded());
}

TEST(THeadRing, can_insert_first)
{
	THeadRing List;
	TMonom *monom = new TMonom(1, 111);
	List.InsFirst(monom);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(THeadRing, can_delete_first_single)
{
	THeadRing List;
	TMonom *monom1 = new TMonom(1, 111);
	List.InsFirst(monom1);
	List.DelFirst();

	EXPECT_TRUE(List.IsEmpty());
}

TEST(THeadRing, can_delete_first)
{
	THeadRing List;
	TMonom *monom1 = new TMonom(1, 111);
	TMonom *monom2 = new TMonom(2, 222);
	TMonom *monom3 = new TMonom(3, 333);
	List.InsFirst(monom1);
	List.InsFirst(monom2);
	List.InsFirst(monom3);
	List.DelFirst();

	EXPECT_FALSE(List.IsEmpty());
}

TEST(TPolinom, can_create_empty_polinom)
{
	TPolinom polinom;

	EXPECT_TRUE(polinom.IsEmpty());
}

TEST(TPolinom, can_create_no_empty_polinom_1)
{
	int m1[][2] = { { 1, 594 },{ 5, 321 },{ 12, 132 },{ 2, 98 },{ 10, 19 },{ -5, 6 },{ -10, 0 } };
	TPolinom polinom(m1, 7);

	EXPECT_FALSE(polinom.IsEmpty());
}

TEST(TPolinom, can_create_no_empty_polinom_2)
{
	int m1[][2] = { { 1, 594 },{ 5, 321 },{ 12, 132 },{ 2, 98 },{ 10, 19 },{ -5, 6 },{ -10, 0 } };
	TPolinom polinom(m1, 7);

	EXPECT_EQ(7, polinom.GetListLength());
}

TEST(TPolinom, can_create_copy_empty_polinom)
{
	TPolinom polinom1;
	TPolinom polinom2(polinom1);

	EXPECT_TRUE(polinom2.IsEmpty());
}

TEST(TPolinom, can_create_copy_no_empty_polinom_1)
{
	int m1[][2] = { { 1, 594 },{ 5, 321 },{ 12, 132 },{ 2, 98 },{ 10, 19 },{ -5, 6 },{ -10, 0 } };
	TPolinom polinom1(m1, 7);
	TPolinom polinom2(polinom1);

	EXPECT_FALSE(polinom2.IsEmpty());
}

TEST(TPolinom, can_create_copy_no_empty_polinom_2)
{
	int m1[][2] = { { 1, 594 },{ 5, 321 },{ 12, 132 },{ 2, 98 },{ 10, 19 },{ -5, 6 },{ -10, 0 } };
	TPolinom polinom1(m1, 7);
	TPolinom polinom2(polinom1);

	EXPECT_EQ(7, polinom2.GetListLength());
}

TEST(TPolinom, can_create_copy_no_empty_polinom_3)
{
	int m1[][2] = { { 1, 594 },{ 5, 321 },{ 12, 132 },{ 2, 98 },{ 10, 19 },{ -5, 6 },{ -10, 0 } };
	TPolinom polinom1(m1, 7);
	TPolinom polinom2(polinom1);

	EXPECT_NE(&polinom1, &polinom2);
}

TEST(TPolinom, can_add_1)
{
	int mon1[][2] = { { 1, 543 },{ 3, 432 },{ 5, 321 },{ 7, 210 } };
	int mon2[][2] = { { 2, 643 },{ 4, 431 },{ -5, 321 },{ 8, 110 },{ 3, 60 } };
	int mon3[][2] = { { 2, 643 },{ 1, 543 },{ 3, 432 },{ 4, 431 },{ 7, 210 },{ 8, 110 },{ 3, 60 } };
	TPolinom p1(mon1, 4);
	TPolinom p2(mon2, 5);
	TPolinom p3(mon3, 7);
	p1 += p2;

	EXPECT_TRUE(p3 == p1);
}

TEST(TPolinom, can_add_2)
{
	int m0[][2] = { { 1,344 },{ -3,233 },{ 6,23 } };
	int m1[][2] = { { 6,342 },{ 3,33 } };
	int m2[][2] = { { 3,33 } };
	int m3[][2] = { { 1,344 },{ 6,342 },{ -3,233 },{ 6,23 } };
	TPolinom p1(m0, 3), p2(m1, 2), p3(m2, 1), p4(m3, 4);
	p1 += p2;
	p3 += p4;
	EXPECT_TRUE(p1 == p3);
}

TEST(TPolinom, can_add_3)
{
	int m1[][2] = { { 3,33 } };
	int m2[][2] = { { -3,33 } };
	TPolinom p1(m1, 1), p2(m2, 1);
	p1 += p2;

	EXPECT_TRUE(p1.IsEmpty());
}

TEST(TPolinom, can_add_4)
{
	int m1[][2] = { {2,222}, {1,111}, { 3,33 } };
	int m2[][2] = { {3,333}, { -3,33 } };
	TPolinom p1(m1, 1), p2(m2, 1);
	p1 += p2;

	EXPECT_FALSE(p1.IsEmpty());
}

TEST(TPolinom, can_add_5)
{
	int m1[][2] = { { 2,222 },{ 1,111 },{ 3,33 } };
	int m2[][2] = { { 3,333 },{ -3,33 } };
	TPolinom p1(m1, 3), p2(m2, 2);
	p1 += p2;

	EXPECT_EQ(3, p1.GetListLength());
}

TEST(TPolinom, can_assign_1)
{
	int m1[][2] = { { 2,222 },{ 1,111 },{ 3,33 } };
	int m2[][2] = { { 3,333 },{ -3,33 } };
	TPolinom p1(m1, 1), p2(m2, 1);
	p1 = p2;

	EXPECT_TRUE(p1 == p2);
}

TEST(TPolinom, can_assign_2)
{
	int m1[][2] = { { 2,222 },{ 1,111 },{ 3,33 } };
	int m2[][2] = { { 3,333 },{ -3,33 } };
	TPolinom p1(m1, 1), p2(m2, 1);
	p1 = p2;

	EXPECT_FALSE(&p1 == &p2);
}

TEST(TPolinom, can_assign_3)
{
	int m1[][2] = { { 2,222 },{ 1,111 },{ 3,33 } };
	int m2[][2] = { { 3,333 },{ -3,33 } };
	TPolinom p1(m1, 3), p2(m2, 2);
	p1 = p2;

	EXPECT_EQ(2, p1.GetListLength());
}

TEST(TPolinom, can_assign_4)
{
	int m1[][2] = { { 2,222 },{ 1,111 },{ 3,33 } };
	TPolinom p1(m1, 1), p2;
	p1 = p2;

	EXPECT_TRUE(p1.IsEmpty());
}

TEST(TPolinom, can_assign_5)
{
	int m1[][2] = { { 2,222 },{ 1,111 },{ 3,33 } };
	TPolinom p1(m1, 1), p2;
	p1 = p2;

	EXPECT_EQ(0, p1.GetListLength());
}





