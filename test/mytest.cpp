#include "gtest.h"
#include "Polinom.h"

using namespace std;

TEST(TDatList, can_insert_first_in_empty_list)
{
	TDatList List;
	TMonom *m = new TMonom(1, 1);
	List.InsFirst(m);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, can_insert_last_in_empty_list)
{
	TDatList List;
	TMonom *m = new TMonom(1, 1);
	List.InsLast(m);

	EXPECT_EQ(1, List.GetListLength());
}


TEST(TDatList, can_insert_current_in_empty_list)
{
	TDatList List;
	TMonom *m = new TMonom(1, 1);
	List.InsCurrent(m);

	EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, cant_delete_first_empty_list)
{
	TDatList List;
	List.DelFirst();
	EXPECT_EQ(ListEmpty, List.GetRetCode());
}

TEST(TDatList, cant_delete_current_empty_list)
{
	TDatList List;
	List.DelCurrent();
	EXPECT_EQ(ListEmpty, List.GetRetCode());
}

TEST(TDatList, can_del_list)
{
	TDatList List;
	TMonom *m1 = new TMonom(1, 1);
	TMonom *m2 = new TMonom(2, 2);
	TMonom *m3 = new TMonom(3, 3);
	List.InsFirst(m1);
	List.InsFirst(m2);
	List.InsFirst(m3);
	List.DelList();

	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList,new_list_is_empty)
{
	TDatList List;
	EXPECT_TRUE(List.IsEmpty());
}

TEST(TDatList, can_reset)
{
	TDatList List;
	TMonom *m1 = new TMonom(1, 1);
	TMonom *m2 = new TMonom(2, 2);
	TMonom *m3 = new TMonom(3, 3);
	List.InsCurrent(m1);
	List.InsCurrent(m2);
	List.InsCurrent(m3);
	List.Reset();
	EXPECT_EQ(0, List.GetCurrentPos());
}

TEST(TPolinom, can_create_polinom)
{
	int monoms[][2] = { {1, 1}, {2, 2} };
	ASSERT_NO_THROW(TPolinom(monoms, 2));
}

TEST(TPolinom, can_create_empty_polinom)
{
	TPolinom p;

	EXPECT_TRUE(p.IsEmpty());
}

TEST(TPolinom, can_assign_polinom)
{
	int monoms[][2] = { {1, 1}, {2, 2} };
	TPolinom p(monoms, 2);
	TPolinom p1;
	ASSERT_NO_THROW(p1 = p);
}

TEST(TPolinom, can_add)
{
	int monoms[][2] = { {1, 1}, {2, 2} };
	int res_monoms[][2] = { {2, 1}, {4, 2} };
	TPolinom res_p(res_monoms, 2);
	TPolinom p(monoms, 2);
	TPolinom p1(monoms, 2);
	p += p1;
	EXPECT_EQ(true, res_p == p);
}

TEST(TPolinom, cant_create_poli_with_negative_numbers_of_monoms)
{
	int monoms[][2] = { {1, 1}, {2, 2} };
	ASSERT_ANY_THROW(TPolinom p(monoms, -1));
}
