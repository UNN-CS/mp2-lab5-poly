#include "Polinom.h"
#include <gtest.h>

TEST(TPolinom, Cant_Create_Monom_With_Wrong_Index)
{
    ASSERT_ANY_THROW(PTMonom m = new TMonom(3, -100));
}

TEST(TPolinom, Can_Create_Polinom)
{
    int m[][2] = { { 1 , 2 },{ 3, 4 } };
    ASSERT_NO_THROW(TPolinom p(m, 2));
}


TEST(TPolinom, Can_Compare_1)
{
    int m[][2] = { { 1 , 2 },{ 3, 4 } };
    int m1[][2] = { { 2, 405 } };
    TPolinom p(m, 2), p1(m1, 1);
    EXPECT_EQ(false, p == p1);
}


TEST(TPolinom, Check_IsEmpty)
{
    int m[][2] = { { 1 , 2 },{ 3, 4 } };
    TPolinom p(m, 2);
    EXPECT_EQ(false, p.IsEmpty());
} 

TEST(TPolinom, Unequal_Polinoms_Are_Not_Equal)
{
    int m1[][2] = { { 1, 2 },{ 3, 4 } };
    int m2[][2] = { { 1, 2 },{ 5, 6 } };
    TPolinom p1(m1, 2);
    TPolinom p2(m2, 2);

    EXPECT_TRUE(p1 != p2);
}

TEST(TPolinom, Cant_Create_Polinom_With_Negative_Numbers_of_Monoms)
{
    int m[][2] = { { 1, 1 },{ 2, 2 } };
    ASSERT_ANY_THROW(TPolinom p(m, -1));
}

TEST(TPolinom, can_create_empty_polinom)
{
    TPolinom p;

    EXPECT_TRUE(p.IsEmpty());
}

TEST(TDatList, Can_Insert_First_in_Empty_List)
{
    TDatList List;
    TMonom *m = new TMonom(1, 1);
    List.InsFirst(m);

    EXPECT_EQ(1, List.GetListLength());
}

TEST(TDatList, Can_Insert_Last_in_Empty_List)
{
    TDatList List;
    TMonom *m = new TMonom(1, 1);
    List.InsLast(m);

    EXPECT_EQ(1, List.GetListLength());
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