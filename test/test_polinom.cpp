#include "Polinom.h"
#include "DatList.h"
#include <gtest.h>

TEST(TPolinom, can_create_polinom2) 
{
    int m[][2] = { {2, 3}, {4, 5} };
    ASSERT_NO_THROW(TPolinom p(m, 2));
}

TEST(TPolinom, can_create_polinom1)
{
    int ms[][2] = { {-5,433}, {2,809}, {18,42}, {4,6} };
    TPolinom t(ms, 4);
    TDatList a;
    a.IsEmpty();

    ASSERT_FALSE(t.IsEmpty());
    EXPECT_EQ(4, t.GetListLength());
}


TEST(TPolinom, cant_create_polinom_with_wrong_index) 
{
    int m1[][2] = {{2, -3}, {4, 5}};
    int m2[][2] = {{2, 1000}, {5, 6}};
    ASSERT_ANY_THROW(TPolinom p(m1, 2));
    ASSERT_ANY_THROW(TPolinom p(m2, 2));
}

TEST(TPolinom, can_create_copied_polinom) 
{
    int m[][2] = {{2, 8}, {4, 5}};
    TPolinom p(m, 2);
    ASSERT_NO_THROW(TPolinom p2 = p);
}

TEST(TPolinom, copy_polinom_is_) 
{
    int m[][2] = {{2, 8}, {4, 5}};
    TPolinom p1(m, 2);
    TPolinom p2 = p1;
    ASSERT_TRUE(p1 == p2);
}

TEST(TPolinom, copied_polinom_has_its_own_memory) 
{
    int m1[][2] = {{2, 8}, {4, 5}};
    int m2[][2] = {{2, 6}, {5, 6}};
    TPolinom p1(m1, 1), p2 = p1, p3(m2, 2);
    p1 = p3;
    ASSERT_FALSE(p1 == p2);
}

TEST(TPolinom, can_add_polinoms1) {
    int m1[][2] = {{2, 8}};
    int m2[][2] = {{-2, 8}};
    TPolinom p, p1(m1,1), p2(m2, 1);
    p1+=p2;
    ASSERT_TRUE(p1 == p);
}

TEST(TPolinom, can_add_polinoms2) {
    int m[][2] = {{-2, 59}, {5, 43}};
    TPolinom p1, p2(m, 2);
    p1+=p2;
    ASSERT_TRUE(p1 == p2);
}

TEST(TPolinom, can_add_polinoms3) {
    int m[][2] = {{-2, 59}, {5, 43}};
    TPolinom p1, p2(m, 2), p3(m, 2);
    p2+=p1;
    ASSERT_TRUE(p3 == p2);
}

TEST(TPolinom, can_add_polinoms4) {
    int m1[][2] = {{1, 5}, {5, 4}, {3, 2}};
    int m2[][2] = {{3, 3}};
    int m3[][2] = {{1, 5}, {5, 4}, {3, 3}, {3, 2}};
    TPolinom p1(m1, 3), p2(m2, 1), p3(m3, 4);
    p1+=p2;
    ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, can_add_polinoms5) {
    int m1[][2] = {{1, 5}, {5, 4}, {3, 2}};
    int m2[][2] = {{3, 3}};
    int m3[][2] = {{1, 5}, {5, 4}, {3, 3}, {3, 2}};
    TPolinom p1(m1, 3), p2(m2, 1), p3(m3, 4);
    p2+=p1;
    ASSERT_TRUE(p2 == p3);
}

TEST(TPolinom, can_add_polinoms6) {
    int m1[][2] = {{1, 5}, {5, 4}, {3, 0}};
    int m2[][2] = {{-1, 5}, {-5, 4}, {-2, 0}};
    int m3[][2] = {{1, 0}};
    TPolinom p1(m1, 3), p2(m2, 3), p3(m3, 1);
    p1+=p2;
    ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, can_add_polinoms7) {
    int m1[][2] = {{2, 5}, {5, 4}, {3, 0}};
    int m2[][2] = {{-1, 5}, {-5, 4}, {-3, 0}};
    int m3[][2] = {{1, 5}};
    TPolinom p1(m1, 3), p2(m2, 3), p3(m3, 1);
    p1+=p2;
    ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, can_add_polinoms8) {
    int m1[][2] = {{1, 100}, {9, 10}, {2, 4}, {15, 0}};
    int m2[][2] = {{4, 100}, {-2, 4}, {4, 2}, {5, 0}};
    int m3[][2] = {{5, 100}, {9, 10}, {4, 2}, {20, 0}};
    TPolinom p1(m1, 4);
    TPolinom p2(m2, 4);
    TPolinom p3(m3, 4);
    p1 += p2;
    ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, can_add_polinoms9) {
    int m1[1000][2], m2[1000][2], m3[1000][2];
    for(int i = 0; i < 1000; i++)
    {
        m1[i][0] = i+1, m1[i][1] = 999-i;
        m2[i][0] = -i, m2[i][1] = 999-i;
        m3[i][0] = 1, m3[i][1] = 999-i;
    }
    TPolinom p1(m1, 1000), p2(m2, 1000), p3(m3, 1000);
    p1+=p2;
    ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, can_add_polinoms10) {
    TPolinom p1, p2, p3;
    p1+=p2;
    ASSERT_TRUE(p1 == p3);
}

