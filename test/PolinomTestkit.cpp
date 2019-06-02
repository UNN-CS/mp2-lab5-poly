#include <stdio.h>
#include <gtest.h>
#include "Polinom.h"

TEST(TMonom, is_possible_to_create_monom)
{
	ASSERT_NO_THROW(TMonom m(6, 6));
}

TEST(TMonom, is_possible_to_get_copy_of_monom)
{
	TMonom m(6, 6);
	TMonom *m2 = (TMonom*)m.GetCopy();
	EXPECT_TRUE(*m2 == m);
}

TEST(TMonom, set_get_index_test)
{
	TMonom m(6, 6);
	m.SetIndex(13);
	EXPECT_EQ(13, m.GetIndex());
}

TEST(TMonom, set_get_coeff_test)
{
	TMonom m(6, 6);
	m.SetCoeff(13);
	EXPECT_EQ(13, m.GetCoeff());
}

TEST(TMonom, assign_monoms)
{
	TMonom m(6, 6);
	TMonom m2 = m;
	EXPECT_TRUE(m2 == m);
}

TEST(TMonom, op_equal_for_monoms)
{
	TMonom m1(6, 6), m2(6, 6), m3(13, 13);
	EXPECT_TRUE(m1 == m2);
	EXPECT_FALSE(m1 == m3);
}

TEST(TMonom, compare_monoms)
{
	TMonom m1(6, 13), m2(6, 6);
	EXPECT_TRUE(m2 < m1);
}

TEST(TDatList, is_possible_to_create_list)
{
	ASSERT_NO_THROW(TDatList l);
}

TEST(TDatlist, getting_value_from_list)
{
	TDatList l;
	EXPECT_EQ(l.GetDatValue(), nullptr);
}

TEST(TDatlist, getting_length)
{
	TDatList l;
	for (int i = 0; i < 666; i++)
		l.InsLast(new TMonom(i, i));
	EXPECT_EQ(666, l.GetListLength());
}

TEST(TDatlist, getting_position)
{
	TDatList l;
	EXPECT_EQ(l.GetCurrentPos(), -1);
}

TEST(TDatlist, setting_position)
{
	TDatList l;
	for (int i = 0; i < 666; i++)
		l.InsLast(new TMonom(i, i));
	ASSERT_NO_THROW(l.SetCurrentPos(13));
	ASSERT_ANY_THROW(l.SetCurrentPos(666));
}

TEST(TDatlist, is_possible_to_reset)
{
	TDatList l;
	l.InsFirst(new TMonom(6, 6));
	l.InsLast(new TMonom(13, 13));
	l.Reset();
	EXPECT_EQ(l.GetCurrentPos(), 0);
}

TEST(TDatlist, is_list_ended)
{
	TDatList l;
	l.InsFirst(new TMonom(6, 6));
	l.GoNext();
	EXPECT_TRUE(l.IsListEnded());
}

TEST(TDatlist, going_next_when_list_is_empty)
{
	TDatList l;
	EXPECT_EQ(1, l.GoNext());
}

TEST(TDatlist, insert_first)
{
	TDatList l;
	ASSERT_NO_THROW(l.InsFirst(new TMonom(6, 6)));
}

TEST(TDatlist, insert_last)
{
	TDatList l;
	ASSERT_NO_THROW(l.InsLast(new TMonom(6, 6)));
}

TEST(TDatlist, insert_current)
{
	TDatList l;
	ASSERT_NO_THROW(l.InsCurrent(new TMonom(6, 6)));
}

TEST(TDatlist, deleting_first_when_list_is_empty)
{
	TDatList l;
	ASSERT_ANY_THROW(l.DelFirst());
}

TEST(TDatlist, deleting_first_normal)
{
	TDatList l;
	for (int i = 0; i < 666; i++)
		l.InsLast(new TMonom(i, i));
	l.DelFirst();
	l.Reset();
	TMonom m(1, 1);
	EXPECT_TRUE(m == *(PTMonom)l.GetDatValue(FIRST));
}

TEST(TDatlist, deleting_current)
{
	TDatList l;
	for (int i = 0; i < 666; i++)
		l.InsLast(new TMonom(i, i));
	l.SetCurrentPos(13);
	l.DelCurrent();
	TMonom m(14, 14);
	EXPECT_TRUE(m == *(PTMonom)l.GetDatValue(CURRENT));
}

TEST(TDatlist, deleting_whole_list)
{
	TDatList l;
	for (int i = 0; i < 666; i++)
		l.InsLast(new TMonom(i, i));
	l.DelList();
	EXPECT_TRUE(l.IsEmpty());
}

TEST(TPolinom, is_possible_to_create_poly)
{
	int mnms[][2] = { { 777, 777 },{ 666, 666 },{ 13, 13 },{ 1, 1 } };
	ASSERT_NO_THROW(TPolinom poly1());
	ASSERT_NO_THROW(TPolinom poly2(mnms, 4));
}

TEST(TPolinom, creating_poly_copy)
{
	int mnms[][2] = { { 13,13 },{ 666, 666 } };
	TPolinom p1(mnms, 2);
	TPolinom p2(p1);
	p1.Reset(); p2.Reset();
	bool fl = 1;
	while (!p1.IsListEnded())
	{
		if (p1.GetMonom()->GetCoeff() != p2.GetMonom()->GetCoeff() || p1.GetMonom()->GetIndex() != p2.GetMonom()->GetIndex())
			fl = 0;
		p1.GoNext(); p2.GoNext();
	}
	EXPECT_TRUE(fl);
}

TEST(TPolinom, is_possible_to_assign_poly)
{
	int mnms[][2] = { { 1, 2 },{ 13, 13 },{ 666, 666 } };
	TPolinom p1(mnms, 3);
	TPolinom p2 = p1;
	p1.Reset(); p2.Reset();
	bool fl = 1;
	while (!p1.IsListEnded())
	{
		if (p1.GetMonom()->GetCoeff() != p2.GetMonom()->GetCoeff() || p1.GetMonom()->GetIndex() != p2.GetMonom()->GetIndex())
			fl = 0;
		p1.GoNext(); p2.GoNext();
	}
	EXPECT_TRUE(fl);
}

TEST(TPolinom, is_possible_to_plus_poly)
{
	int mnms1[][2] = { { 1, 2 },{ 13, 13 },{ 666, 666 } };
	int mnms2[][2] = { { 2, 3 },{ 14,15 },{ 777, 777 } };
	TPolinom p1(mnms1, 3), p2(mnms2, 3);
	ASSERT_NO_THROW(p1 + p2);
}
