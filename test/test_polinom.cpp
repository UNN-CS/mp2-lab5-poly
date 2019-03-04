#include "../gtest/gtest.h"
#include "../include/polinom.h"

TEST(TPolinom, create)
{
  EXPECT_NO_THROW(TPolinom p);
}

TEST(TPolinom, print_empty)
{
  TPolinom p;

  EXPECT_NO_THROW(std::cout << p);
  std::cout << "|->\n";
}

TEST(TPolinom, init_constructor)
{
  int monoms[][2] = {{-1, 246},
                     { 3, 245},
                     { 2, 234},
                     { 0, 999},
                     { 1, 123}};
  EXPECT_NO_THROW(TPolinom(monoms, 5));
}

TEST(TPolinom, print_non_empty)
{
  int monoms[][2] = {{-1, 246},
                     { 3, 245},
                     { 2, 234},
                     { 0, 999},
                     { 1, 123}};
  TPolinom p(monoms, 5);

  EXPECT_NO_THROW(std::cout << p);
  std::cout << "|->\n";
}

TEST(TPolinom, operator_plus_assign)
{
  int monoms[][2] = {{-1, 246},
                     { 3, 245},
                     { 2, 234},
                     { 0, 999},
                     { 1, 123}};
  int monoms1[][2] = {{ 1, 246},
                      {-3, 245},
                      {-2, 234},
                      { 0, 999},
                      {-1, 123}};

  TPolinom p(monoms, 5),
           p1(monoms1, 5);

  EXPECT_NO_THROW(p += p1);
  EXPECT_TRUE(p.IsEmpty());
}
/*
TEST(TPolinom, operator_plus_assign_1)
{
  int monoms[][2] = {{-1, 246},
                     { 3, 245},
                     { 2, 234},
                     { 0, 999},
                     { 1, 123}};
  int monoms1[][2] = {{ 4, 248},
                      {-7, 124}};
  int r[][2] = {{ -1, 246 },
                {  3, 245 },
                {  2, 234 },
                {  1, 123 },
                {  4, 248 },
                { -7, 124 }};

  TPolinom p(monoms, 5),
           p1(monoms1, 2),
           res(r, 6);

  EXPECT_NO_THROW(p += p1);
  EXPECT
}*/


