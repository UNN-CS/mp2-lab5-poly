#define _CRT_SECURE_NO_WARNING
#include "Polynom.h"
#include <gtest.h>
#include <iostream>

TEST(TDatLink, can_create_link)
{
	PTMonom pMonom = new TMonom(1, 111);
	ASSERT_NO_THROW(TDatLink temp(pMonom));
}

TEST(TDatLink, can_set_get_value)
{
	PTMonom pMonom = new TMonom(1, 111);
	TDatLink temp(pMonom);
	temp.SetDatValue(pMonom);
	EXPECT_EQ(pMonom, temp.GetDatValue());
}

TEST(TDatList, can_insert_first)
{
	PTMonom pMonom = new TMonom(1, 111);
	TDatList temp;
	temp.InsFirst(pMonom);
	EXPECT_EQ(pMonom, temp.GetDatValue(FIRST));
}

TEST(TDatList, can_insert_last)
{
	PTMonom pMonom = new TMonom(1, 111);
	TDatList temp;
	temp.InsLast(pMonom);
	EXPECT_EQ(pMonom, temp.GetDatValue(LAST));
}

TEST(TDatList, can_insert_current)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 112);
	PTMonom pMonom2 = new TMonom(1, 122);
	TDatList temp;
	temp.InsFirst(pMonom);
	temp.InsLast(pMonom2);
	temp.InsCurrent(pMonom1);
	EXPECT_EQ(pMonom1, temp.GetDatValue(CURRENT));
}

TEST(TDatList, can_detect_if_list_empty)
{
	TDatList temp;
	EXPECT_TRUE(temp.IsEmpty());
}

TEST(TDatList, can_get_list_length)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	TDatList temp;
	temp.InsFirst(pMonom);
	temp.InsFirst(pMonom1);
	EXPECT_EQ(2, temp.GetListLength());

}

TEST(TDatList, can_set_get_current_position)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	TDatList temp;
	temp.InsFirst(pMonom);
	temp.InsFirst(pMonom1);
	temp.SetCurrentPos(0);
	EXPECT_EQ(0, temp.GetCurrentPos());

}

TEST(TDatList, can_reset_list)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	TDatList temp;
	temp.InsFirst(pMonom);
	temp.InsFirst(pMonom1);
	temp.Reset();
	EXPECT_EQ(pMonom1, temp.GetDatValue());
}

TEST(TDatList, can_go_next_list)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	PTMonom pMonom2 = new TMonom(1, 111);
	TDatList temp;
	temp.InsLast(pMonom);
	temp.InsLast(pMonom1);
	temp.InsLast(pMonom2);
	temp.Reset();
	temp.GoNext();
	EXPECT_EQ(pMonom1, temp.GetDatValue());
}

TEST(TDatList, can_detect_list_is_ended)
{
	PTMonom pMonom = new TMonom(1, 111);
	TDatList temp;
	temp.InsLast(pMonom);
	temp.GoNext();
	EXPECT_TRUE(temp.IsListEnded());
}

TEST(TDatList, can_delete_first)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	TDatList temp;
	temp.InsFirst(pMonom);
	temp.InsFirst(pMonom1);
	temp.DelFirst();
	EXPECT_EQ(pMonom, temp.GetDatValue());
}

TEST(TDatList, can_delete_current)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	TDatList temp;
	temp.InsLast(pMonom);
	temp.InsCurrent(pMonom1);
	temp.DelCurrent();
	EXPECT_EQ(pMonom, temp.GetDatValue());
}

TEST(TDatList, can_delete_list)
{
	PTMonom pMonom = new TMonom(1, 111);
	PTMonom pMonom1 = new TMonom(1, 111);
	TDatList temp;
	temp.InsLast(pMonom);
	temp.InsCurrent(pMonom1);
	temp.DelList();
	EXPECT_TRUE(temp.IsEmpty());
}

TEST(TPolynom, throws_when_create_poly_with_wrong_index)
{
	int arrMn[][2] = { {1, -111}, {1, 111}, {1, 111} };
	ASSERT_ANY_THROW(TPolynom p(arrMn, 3));
}

TEST(TPolynom, can_create_copied_Polynom)
{
	int arrMn[][2] = { {2, 414}, {2, 111}, {3, 111} };
	int size = sizeof(arrMn) / (2 * sizeof(int));
	TPolynom p(arrMn, size);
	ASSERT_NO_THROW(TPolynom p1(p));
}

TEST(TPolynom, copied_Polynom_eq_to_source)
{
	int arrMn[][2] = { {2, 414}, {2, 111}, {3, 111} };
	int size = sizeof(arrMn) / (2 * sizeof(int));
	TPolynom p(arrMn, size);
	TPolynom p1(p);
	p.Reset();
	p1.Reset();
	bool okey = true;
	for (int i = 0; i < size; i++, p.GoNext(), p1.GoNext())
		if (p.GetMonom()->GetCoeff() != p1.GetMonom()->GetCoeff())
			okey = false;
	if (p.GetMonom()->GetIndex() != p1.GetMonom()->GetIndex())
		okey = false;
	EXPECT_TRUE(okey);
}

TEST(TPolynom, copied_Polynom_has_its_own_memory)
{
	int arrMn[][2] = { {2, 414}, {2, 111}, {3, 111} };
	int size = sizeof(arrMn) / (2 * sizeof(int));
	TPolynom p(arrMn, size);
	TPolynom p1(p);
	EXPECT_NE(&p, &p1);
}

TEST(TPolynom, can_assign_Polynom)
{
	int arrMn[][2] = { {2, 414}, {2, 111}, {3, 111} };
	int size = sizeof(arrMn) / (2 * sizeof(int));
	TPolynom p(arrMn, size);
	TPolynom p1;
	ASSERT_NO_THROW(p1 = p);
}

TEST(TPolynom, summ_of_Polynoms)
{
	int arrMn[][2] = { {2, 414}, {2, 111} };
	int arrMn2[][2] = { {3, 414}, {2, 112} };
	int arrMnR[][2] = { 5, 414, {2, 112}, {2, 111} };
	int size = sizeof(arrMn) / (2 * sizeof(int));
	TPolynom p(arrMn, size);
	TPolynom p1(arrMn2, size);
	TPolynom r(arrMnR, 3);
	TPolynom summ = p + p1;
	summ.Reset();
	r.Reset();
	bool okey = true;
	for (int i = 0; i < 3; r.GoNext(), summ.GoNext(), i++)
	{
		if (r.GetMonom()->GetIndex() != summ.GetMonom()->GetIndex())
			okey = false;
		if (r.GetMonom()->GetCoeff() != summ.GetMonom()->GetCoeff())
			okey = false;
	}
	EXPECT_TRUE(okey);
}

TEST(TPolynom, can_calculate_Polynom)
{
	int arrMn[][2] = { {2, 414}, {2, 111} };
	TPolynom p(arrMn, 2);
	EXPECT_EQ(1040, p.CalculatePolynom(2, 2, 2));
}

TEST(TPolynom, can_print_Polynom)
{
	int arrMn[][2] = { {2, 414}, {2, 111} };
	TPolynom p(arrMn, 2);
	ASSERT_NO_THROW(std::cout << p << std::endl);
}

