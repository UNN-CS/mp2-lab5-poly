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

TEST(TPolinom, insert_monom)
{
  int monoms[][2] = {{-1, 246},
                     { 3, 245},
                     { 2, 234},
                     { 0, 999},
                     { 1, 123}};
  TPolinom p(monoms, 5);
  PTMonom pm = new TMonom(-10, 235);

  EXPECT_NO_THROW(p.InsMonom(pm));
  EXPECT_EQ(2, p.GetCurrentPos());
}

TEST(TPolinom, insert_monom_last)
{
  int monoms[][2] = {{-1, 246},
                     { 3, 245},
                     { 2, 234},
                     { 0, 999},
                     { 1, 123}};
  TPolinom p(monoms, 5);
  PTMonom pm = new TMonom(-10, 246);

  std::cout << *pm << std::endl;

  EXPECT_NO_THROW(p.InsMonom(pm));
  p.SetCurrentPos(3);
  std::cout << *p.GetMonom() << std::endl;
  EXPECT_EQ(*pm, *p.GetMonom());
}

