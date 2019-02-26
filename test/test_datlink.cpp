#include "../gtest/gtest.h"
#include "../include/datlink.h"
#include "../include/monom.h"

TEST(TDatLink, can_get_next_link)
{
  TDatLink l2;
  TDatLink l1(nullptr, &l2);

  EXPECT_EQ(&l2, l1.GetNextLink());
}

TEST(TDatLink, can_set_next_link)
{
  TDatLink l1, l2;

  EXPECT_NO_THROW(l1.SetNextLink(&l2));
  EXPECT_EQ(&l2, l1.GetNextLink());
}

TEST(TDatLink, can_get_value)
{
  TMonom m;
  TDatLink l(&m);

  EXPECT_EQ(&m, l.GetDatValue());
}

TEST(TDatLink, can_set_value)
{
  TMonom m;
  TDatLink l;

  EXPECT_NO_THROW(l.SetDatValue(&m));
  EXPECT_EQ(&m, l.GetDatValue());
}


