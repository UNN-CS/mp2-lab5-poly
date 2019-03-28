#include "../gtest/gtest.h"
#include "../include/headring.h"

TEST(THeadRing, create_empty)
{
  THeadRing hr;

  EXPECT_TRUE(hr.IsEmpty());
}

TEST(THeadRing, throw_if_del_from_empty)
{
  THeadRing hr;

  EXPECT_ANY_THROW(hr.DelFirst());
}

TEST(THeadRing, can_insert_first)
{
  THeadRing hr;

  EXPECT_NO_THROW(hr.InsFirst());
  EXPECT_NO_THROW(hr.InsFirst());
  EXPECT_NO_THROW(hr.InsFirst());
  EXPECT_EQ(3, hr.GetListLength());
}

TEST(THeadRing, can_ins_last)
{
  THeadRing hr;

  EXPECT_NO_THROW(hr.InsLast());
  EXPECT_NO_THROW(hr.InsLast());
  EXPECT_NO_THROW(hr.InsLast());
  EXPECT_EQ(3, hr.GetListLength());
}

TEST(THeadRing, destructor_dont_throws)
{
  THeadRing *hr = new THeadRing;

  hr->TDatList::InsFirst();
  hr->TDatList::InsFirst();
  hr->TDatList::InsFirst();

  EXPECT_NO_THROW(delete hr);
}


