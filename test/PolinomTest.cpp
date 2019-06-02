#include "gtest.h"

#include "TDatList.h"
#include "TMonom.h"
#include "TPolinom.h"

TEST(TDatList, Can_Create_List)
{
	ASSERT_NO_THROW(TDatList l);
}

TEST(TDatList, Can_Ins_First)
{
	TDatList l;
	PTMonom m = new TMonom(-30, 368);

	ASSERT_NO_THROW(l.InsFirst(m));
	EXPECT_EQ(m, l.GetDatValue(FIRST));
}

TEST(TDatList, Can_Ins_Last)
{
	TDatList l;
	PTMonom m = new TMonom(128, 990);

	ASSERT_NO_THROW(l.InsLast(m));
	EXPECT_EQ(m, l.GetDatValue(LAST));
}

TEST(TDatList, Can_Ins_Current)
{
	TDatList l;
	PTMonom m1 = new TMonom(-1307, 221);
	PTMonom m2 = new TMonom(-1308, 222);
	PTMonom m3 = new TMonom(-1309, 223);

	l.InsFirst(m1);
	l.InsLast(m2);
	l.SetCurrentPos(1);

	ASSERT_NO_THROW(l.InsCurrent(m3));
	EXPECT_EQ(m3, l.GetDatValue(CURRENT));
}

TEST(TDatList, Can_Del_First)
{
	TDatList l;
	PTMonom m = new TMonom(7, 401);

	l.InsFirst(m);
	ASSERT_NO_THROW(l.DelFirst());
	EXPECT_EQ(nullptr, l.GetDatValue(FIRST));
}

TEST(TDatList, Can_Del_Current)
{
	TDatList l;
	PTMonom m1 = new TMonom(-1307, 221);
	PTMonom m2 = new TMonom(-1308, 222);
	PTMonom m3 = new TMonom(-1309, 223);

	l.InsFirst(m3);
	l.InsFirst(m2);
	l.InsFirst(m1);
	l.SetCurrentPos(1);

	ASSERT_NO_THROW(l.DelCurrent());
	EXPECT_EQ(m3, l.GetDatValue(LAST));
	EXPECT_EQ(m1, l.GetDatValue(FIRST));
	EXPECT_EQ(m3, l.GetDatValue(CURRENT));
}

TEST(TDatList, List_Len_Is_Correct)
{
	TDatList l;
	PTMonom m1 = new TMonom(-1307, 221);
	PTMonom m2 = new TMonom(-1308, 222);
	PTMonom m3 = new TMonom(-1309, 223);

	EXPECT_EQ(0, l.GetListLength());
	l.InsFirst(m3);
	EXPECT_EQ(1, l.GetListLength());
	l.InsFirst(m2);
	EXPECT_EQ(2, l.GetListLength());
	l.DelFirst();
	EXPECT_EQ(1, l.GetListLength());
	l.InsFirst(m1);
	EXPECT_EQ(2, l.GetListLength());
}

TEST(TDatList, Empty_List_Is_Empty)
{
	TDatList l;
	PTMonom m = new TMonom(-8832, 300);

	EXPECT_EQ(1, l.IsEmpty());
	l.InsFirst(m);
	EXPECT_EQ(0, l.IsEmpty());
	l.DelFirst();
	EXPECT_EQ(1, l.IsEmpty());
}

TEST(TDatList, Go_Next_Is_Correct)
{
	TDatList l;
	PTMonom m = new TMonom(1, 404);

	EXPECT_EQ(-1, l.GetCurrentPos());
	l.InsFirst(m);
	EXPECT_EQ(0, l.GetCurrentPos());
	ASSERT_NO_THROW(l.GoNext());
	EXPECT_EQ(1, l.GetCurrentPos());
}

TEST(TDatList, Reset_Is_Correct)
{
	TDatList l;
	PTMonom m1 = new TMonom(1, 404);
	PTMonom m2 = new TMonom(1, 404);
	PTMonom m3 = new TMonom(1, 404);

	l.InsFirst(m3);
	l.InsFirst(m2);
	l.InsFirst(m1);
	l.SetCurrentPos(2);

	ASSERT_NO_THROW(l.Reset());
	EXPECT_EQ(0, l.GetCurrentPos());
}

TEST(TPolinom, Can_Create_Polinom)
{
	ASSERT_NO_THROW(TPolinom p);
}

TEST(TPolinom, Constructor_Is_Correct)
{
	int mon[][2] = { { -124, 841 },{ 1, 777 },{ 148, 432 },{ -170, 100 } };
	TPolinom p(mon, 4);
	PTMonom m = new TMonom(-124, 841);

	EXPECT_EQ(m->GetCoeff(), p.GetMonom()->GetCoeff());
	EXPECT_EQ(m->GetIndex(), p.GetMonom()->GetIndex());
}

TEST(TPolinom, Cant_Create_Polinom_With_Wrong_Index)
{
	int mon1[][2] = { { 180, -10 } };
	int mon2[][2] = { { -180, 1010 } };
	ASSERT_ANY_THROW(TPolinom p1(mon1, 1));
	ASSERT_ANY_THROW(TPolinom p2(mon2, 1));
}

TEST(TPolinom, Copied_Polinom_Has_Its_Own_Memory)
{
	int mon[][2] = { { 3, 664 },{ -4, 202 } };
	TPolinom p1(mon, 2);
	PTMonom m = new TMonom(10, 130);
	TPolinom p2(p1);
	p1.Reset();

	EXPECT_EQ(p1.GetMonom()->GetCoeff(), p2.GetMonom()->GetCoeff());
	EXPECT_EQ(p1.GetMonom()->GetIndex(), p2.GetMonom()->GetIndex());
	p2.InsFirst(m);
	EXPECT_NE(p1.GetMonom()->GetCoeff(), p2.GetMonom()->GetCoeff());
	EXPECT_NE(p1.GetMonom()->GetIndex(), p2.GetMonom()->GetIndex());
}

TEST(TPolinom, Equality_Operator_Is_Correct)
{
	int mon1[][2] = { { 50, 120 },{ -12, 110 } };
	int mon2[][2] = { { -16, 302 },{ -6, 100 } };
	TPolinom p1(mon1, 2);
	TPolinom p2(mon2, 2);
	PTMonom m = new TMonom(-33, 718);

	p2 = p1;
	p1.Reset();
	EXPECT_EQ(p1.GetMonom()->GetCoeff(), p2.GetMonom()->GetCoeff());
	EXPECT_EQ(p1.GetMonom()->GetIndex(), p2.GetMonom()->GetIndex());
	p2.InsFirst(m);
	EXPECT_NE(p1.GetMonom()->GetCoeff(), p2.GetMonom()->GetCoeff());
	EXPECT_NE(p1.GetMonom()->GetIndex(), p2.GetMonom()->GetIndex());
}

TEST(TPolinom, Equal_Polinoms_Are_Equal)
{
	int mon1[][2] = { { -32321, 543 },{ 74544, 294 } };
	int mon2[][2] = { { -32321, 543 },{ 74544, 294 } };
	TPolinom p1(mon1, 2);
	TPolinom p2(mon2, 2);

	EXPECT_TRUE(p1 == p2);
}

TEST(TPolinom, Addition_Of_Polinoms_1)
{
	int mon1[][2] = { { 5, 555 } };
	int mon2[][2] = { { 6, 666 } };
	int mon3[][2] = { { 6, 666 },{ 5, 555 } };
	TPolinom p1(mon1, 1);
	TPolinom p2(mon2, 1);
	TPolinom p3(mon3, 2);

	p1 += p2;
	EXPECT_TRUE(p1 == p3);
}

TEST(TPolinom, Addition_Of_Polinoms_2)
{
	int mon1[][2] = { { 100, 999 },{ 1, 123 } };
	int mon2[][2] = { { -100, 999 },{ -1, 123 } };
	TPolinom p1(mon1, 2);
	TPolinom p2(mon2, 2);
	TPolinom p3;

	p1 += p2;
	EXPECT_TRUE(p1 == p3);
}

TEST(TPolinom, Addition_Of_Polinoms_3)
{
	int mon1[][2] = { { -13, 504 },{ 800, 366 } };
	TPolinom p1;
	TPolinom p2(mon1, 1);

	p1 += p2;
	EXPECT_TRUE(p1 == p2);
}
