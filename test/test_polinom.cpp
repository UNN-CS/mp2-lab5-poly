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


