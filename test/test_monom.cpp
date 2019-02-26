#include "../gtest/gtest.h"
#include "../include/monom.h"

TEST(TMonom, can_create)
{
  EXPECT_NO_THROW(TMonom tm(4, 123));
}

TEST(TMonom, throw_if_invalid_arguments)
{
  EXPECT_ANY_THROW(TMonom tm(4, 1000));
  EXPECT_ANY_THROW(TMonom tm(4, -2));
}

TEST(TMonom, can_get_index)
{
  const int COEFF = 4,
            INDEX = 123;
  TMonom tm(COEFF, INDEX);

  EXPECT_NO_THROW(tm.GetIndex());
  EXPECT_EQ(INDEX, tm.GetIndex());
}

TEST(TMonom, can_set_index)
{
  const int INDEX = 123;
  TMonom tm;

  EXPECT_NO_THROW(tm.SetIndex(INDEX));
  EXPECT_EQ(INDEX, tm.GetIndex());
}


TEST(TMonom, can_get_coeff)
{
  const int COEFF = 4,
            INDEX = 123;
  TMonom tm(COEFF, INDEX);

  EXPECT_NO_THROW(tm.GetCoeff());
  EXPECT_EQ(COEFF, tm.GetCoeff());
}

TEST(TMonom, can_set_coeff)
{
  const int COEFF = 123;
  TMonom tm;

  EXPECT_NO_THROW(tm.SetCoeff(COEFF));
  EXPECT_EQ(COEFF, tm.GetCoeff());
}

TEST(TMonom, operator_equal)
{
  const int COEFF = 4,
            INDEX = 123;
  TMonom tm1(COEFF, INDEX),
         tm2(COEFF, INDEX);

  EXPECT_TRUE(tm1 == tm2);
}

TEST(TMonom, operator_less)
{
  const int COEFF = 4,
            INDEX = 123;
  TMonom tm1(COEFF, INDEX - 1),
         tm2(COEFF, INDEX);

  EXPECT_TRUE(tm1 < tm2);
}

TEST(TMonom, operator_assign)
{
  TMonom tm1(4, 123),
         tm2;
  tm2 = tm1;

  EXPECT_EQ(tm2, tm2);
}


