#include "../gtest/gtest.h"
#include "../include/datlist.h"

TEST(TDatList, can_insert_first)
{
  TDatList l;

  EXPECT_NO_THROW(l.InsFirst());
  EXPECT_NO_THROW(l.InsFirst());
  EXPECT_NO_THROW(l.InsFirst());
}

TEST(TDatList, can_del_first)
{
  TDatList l;

  l.InsFirst();
  l.InsFirst();
  l.InsFirst();

  EXPECT_NO_THROW(l.DelFirst());
  EXPECT_NO_THROW(l.DelFirst());
  EXPECT_NO_THROW(l.DelFirst());
}

TEST(TDatList, can_set_current_position)
{
  TDatList l;

  l.InsFirst();
  l.InsFirst();
  l.InsFirst();

  EXPECT_NO_THROW(l.SetCurrentPos(1));
}

TEST(TDatList, can_get_current_position)
{
  const int POS = 1;
  TDatList l;

  l.InsFirst();
  l.InsFirst();
  l.InsFirst();

  l.SetCurrentPos(POS);
  EXPECT_EQ(POS, l.GetCurrentPos());
}

TEST(TDatList, created_empty)
{
  TDatList l;

  EXPECT_TRUE(l.IsEmpty());
}

TEST(TDatList, get_list_length)
{
  const int C = 4;
  TDatList l;

  for(int i = 0; i < C; ++i)
    l.InsFirst();

  EXPECT_EQ(C, l.GetListLength());
}

TEST(TDatList, del_list)
{
  TDatList *l = new TDatList;

  l->InsFirst();
  l->InsFirst();
  l->InsFirst();

  EXPECT_NO_THROW(delete l);
}

TEST(TDatList, reset_)
{
  TDatList l;

  l.InsFirst();
  l.InsFirst();
  l.InsFirst();
  l.SetCurrentPos(2);

  EXPECT_NO_THROW(l.Reset());
  EXPECT_EQ(0, l.GetCurrentPos());
}

TEST(TDatList, go_next)
{
  TDatList l;

  l.InsFirst();
  l.InsFirst();
  l.InsFirst();

  EXPECT_NO_THROW(l.GoNext());
  EXPECT_NO_THROW(l.GoNext());
  EXPECT_NO_THROW(l.GoNext());
  EXPECT_ANY_THROW(l.GoNext());
}

TEST(TDatList, is_list_ended)
{
  TDatList l;

  l.InsFirst();
  l.InsFirst();
  l.InsFirst();

  EXPECT_FALSE(l.IsListEnded());

  l.GoNext();
  l.GoNext();
  l.GoNext();

  EXPECT_TRUE(l.IsListEnded());
}

TEST(TDatList, get_dat_value)
{
  TDatList l;

  EXPECT_EQ(nullptr, l.GetDatValue());
}

TEST(TDatList, throw_if_del_from_empty)
{
  TDatList l;

  EXPECT_ANY_THROW(l.DelFirst());
}


