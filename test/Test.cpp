#include <gtest.h>
#include "Polinom.h"
//_________________________DatList____________________________
TEST(DatList, can_create_list) 
{
	ASSERT_NO_THROW(TDatList{});
}

TEST(DatList, is_empty_with_empty_list) 
{
	TDatList list;
	ASSERT_EQ(list.IsEmpty(), 1);
}

TEST(DatList, is_empty_with_not_empty_list) 
{
	TDatList list;
	PTMonom t;
	t = new TMonom(10, 17);
	list.InsFirst(t);

	ASSERT_EQ(list.IsEmpty(), 0);
}

TEST(DatList, can_get_list_length_with_empty_list)
{
	TDatList list;

	EXPECT_EQ(0, list.GetListLength());
}

TEST(DatList, can_get_list_length_with_not_empty_list)
{
	TDatList list;
	PTMonom p = new TMonom(10, 17);
	list.InsFirst(p);

	EXPECT_EQ(1, list.GetListLength());
}

TEST(DatList, can_insert_first_in_empty_list)
{
	TDatList list;
	PTMonom t = new TMonom(10, 17);
	list.InsFirst(t);

	EXPECT_EQ(1, list.GetListLength());
}

TEST(DatList, can_insert_first_in_not_empty_list)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	list.InsFirst(p1);
	list.InsFirst(p2);

	EXPECT_EQ(2, list.GetListLength());
}

TEST(DatList, can_insert_last_in_empty_list)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	list.InsLast(p1);

	EXPECT_EQ(1, list.GetListLength());
}

TEST(DatList, can_insert_last_in_not_empty_list)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	list.InsLast(p1);
	list.InsLast(p2);

	EXPECT_EQ(2, list.GetListLength());
}

TEST(DatList, can_insert_current_in_empty_list)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	list.InsCurrent(p1);

	EXPECT_EQ(1, list.GetListLength());
}

TEST(DatList, can_insert_current_in_not_empty_list1)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.GoNext();
	list.InsCurrent(p3);

	EXPECT_EQ(3, list.GetListLength());
}

TEST(DatList, can_insert_current_in_not_empty_list2)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.GoNext();
	list.InsCurrent(p3);

	EXPECT_EQ(1, list.GetCurrentPos());
}

TEST(DatList, can_insert_current_in_not_empty_list3)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.GoNext();
	list.GoNext();
	list.InsCurrent(p3);

	EXPECT_EQ(2, list.GetCurrentPos());
}

TEST(DatList, can_set_current_position)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
	list.SetCurrentPos(1);

	EXPECT_EQ(1, list.GetCurrentPos());
}

TEST(DatList, can_get_current_position)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);

	EXPECT_EQ(0, list.GetCurrentPos());
}

TEST(DatList, can_reset_current_position)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
	list.GoNext();
	list.GoNext();
	list.Reset();

	EXPECT_EQ(0, list.GetCurrentPos());
}

TEST(DatList, can_go_next1) 
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
		
	ASSERT_NO_THROW(list.GoNext());
}

TEST(DatList, can_go_next2) // 6
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	list.InsFirst(p1);

	PTMonom p2 = new TMonom(11, 18);
	list.InsFirst(p2);

	PTMonom p3 = new TMonom(12, 19);
	list.InsLast(p3);


	list.GoNext();
	list.GoNext();

	ASSERT_TRUE(list.GetCurrentPos() == 2);
	ASSERT_TRUE(list.GetDatValue() == p3);
}

TEST(DatList, is_list_ended)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
	list.GoNext();
	list.GoNext();
	list.GoNext();

	EXPECT_TRUE(list.IsListEnded());
}

TEST(DatList, cant_delete_first_in_empty_list)
{
	TDatList list;

	ASSERT_ANY_THROW(list.DelFirst());
}

TEST(DatList, can_delete_first_1)
{
	TDatList list;
	PTMonom p = new TMonom(10, 17);
	list.InsFirst(p);
	list.DelFirst();

	EXPECT_TRUE(list.IsEmpty());
}

TEST(DatList, can_delete_first_2)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
	list.DelFirst();

	EXPECT_EQ(list.GetListLength(), 2);
}

TEST(DatList, cant_delete_current_empty_list)
{
	TDatList list;

	ASSERT_ANY_THROW(list.DelCurrent());
}

TEST(DatList, can_delete_current) 
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	PTMonom p4 = new TMonom(11, 20);

	list.InsFirst(p1);
	list.InsLast(p2);
	list.InsLast(p3);
	list.InsLast(p4);

	list.SetCurrentPos(2);
	list.DelCurrent();
	list.SetCurrentPos(2);

	ASSERT_TRUE(list.GetDatValue() == p4);
}

TEST(DatList, can_delete_current_single)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	list.InsFirst(p1);
	list.DelCurrent();

	EXPECT_TRUE(list.IsEmpty());
}

TEST(DatList, can_delete_list_single_elements)
{
	TDatList list;
	PTMonom p = new TMonom(10, 17);
	list.InsFirst(p);
	list.DelList();

	EXPECT_TRUE(list.IsEmpty());
}

TEST(DatList, can_delete_list)
{
	TDatList list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);
	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
	list.DelList();

	EXPECT_TRUE(list.IsEmpty());
}


//_______________________HeadRing____________________________________


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
	THeadRing list;
	PTMonom p1 = new TMonom(10, 17);
	PTMonom p2 = new TMonom(11, 18);
	PTMonom p3 = new TMonom(12, 19);

	list.InsFirst(p1);
	list.InsFirst(p2);
	list.InsFirst(p3);
	list.DelFirst();

	EXPECT_FALSE(list.IsEmpty());
}


//____________________________Polinom___________________________________

TEST(Polinom, can_create_polinom)
{
	int m[][2] = { {1, 10}, {-4, 120}, {8, 159}, {5, 456}, {2, 17} };

	ASSERT_NO_THROW(TPolinom p(m, 5));
}

TEST(Polinom, can_copy_polinom)
{
	int m[][2] = { {1, 10}, {-4, 120}, {8, 159}, {5, 456}, {2, 17} };
	TPolinom p1(m, 5);

	ASSERT_NO_THROW(TPolinom p2(p1));
}

TEST(Polinom, can_copy_polinom_right)
{
	int m[][2] = { {1, 10}, {-4, 120}, {8, 159}, {5, 456}, {2, 17} };
	TPolinom p1(m, 5);
	TPolinom p2(p1);

	ASSERT_TRUE(p1 == p2);
}

TEST(Polinom, can_add_with_assignment)
{
	int m1[][2] = { {1, 10}, {-4, 120}, {8, 159}, {5, 456}, {2, 17} };
	int m2[][2] = { {1, 10}, {-4, 120}, {8, 159}, {5, 456}, {2, 17} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	ASSERT_NO_THROW(p1 += p2);
}

TEST(Polinom, add_with_assignment_right)
{
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	int m3[][2] = { {7, 220}, {4, 240}, {7, 122}, {8, 121}, {4, 78}, {4, 57}, {3, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);
	TPolinom p3(m3, 7);

	p1 += p2;

	ASSERT_TRUE(p1 == p3);
}

TEST(Polinom, can_compare)
{
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	ASSERT_NO_THROW(p1 == p2);
}

TEST(Polinom, compare_right)
{
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	ASSERT_FALSE(p1 == p2);
}

TEST(Polinom, can_assign)
{
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	ASSERT_NO_THROW(p1 = p2);
}

TEST(Polinom, assign_right)
{
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	p1 = p2;

	ASSERT_TRUE(p1 == p2);
}