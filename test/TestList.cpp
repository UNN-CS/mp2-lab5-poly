#include "Polinom.h"
#include <gtest.h>

TEST(TDatList, can_create_empty_list)
{
	ASSERT_NO_THROW(TDatList list);
}

TEST(TDatList, can_insert_first)
{
	TDatList list;

	PTMonom pMonom = new TMonom();

	ASSERT_NO_THROW(list.InsFirst(pMonom));
}

TEST(TDatList, can_insert_last)
{
	TDatList list;

	PTMonom pMonom_f = new TMonom();
	PTMonom pMonom_l = new TMonom();

	list.InsFirst(pMonom_f);

	ASSERT_NO_THROW(list.InsLast(pMonom_l));
}

TEST(TDatList, can_insert_currient)
{
	TDatList list;

	PTMonom pMonom_f = new TMonom();
	PTMonom pMonom_l = new TMonom();
	PTMonom pMonom_c = new TMonom();

	list.InsFirst(pMonom_f);
	list.InsLast(pMonom_l);

	ASSERT_NO_THROW(list.InsCurrent(pMonom_c));
}

TEST(TDatList, can_get_current_position)
{
	TDatList list;

	PTMonom pMonom_f = new TMonom();
	PTMonom pMonom_l = new TMonom();
	PTMonom pMonom_c = new TMonom();

	list.InsFirst(pMonom_f);
	list.GoNext();
	list.InsLast(pMonom_l);
	list.GoNext();
	list.InsCurrent(pMonom_c);

	EXPECT_EQ(2, list.GetCurrentPos());
}

TEST(TDatList, can_del_first)
{
	TDatList list;

	PTMonom pMonom_f = new TMonom();
	PTMonom pMonom_l = new TMonom();
	PTMonom pMonom_c = new TMonom();

	list.InsFirst(pMonom_f);
	list.InsLast(pMonom_l);
	list.InsCurrent(pMonom_c);

	list.DelFirst();

	EXPECT_EQ(pMonom_f, list.GetDatValue());
}

TEST(TDatList, can_del_current)
{
	TDatList list;

	PTMonom pMonom_f = new TMonom();
	PTMonom pMonom_l = new TMonom();
	PTMonom pMonom_c = new TMonom();

	list.InsFirst(pMonom_f);
	list.InsLast(pMonom_l);
	list.InsCurrent(pMonom_c);

	list.DelCurrent();

	EXPECT_EQ(pMonom_f, list.GetDatValue());