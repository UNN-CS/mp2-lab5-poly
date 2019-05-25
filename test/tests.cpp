#include <iostream>
#include <gtest.h>
#include "DatList.h"
#include "Polinom.h"

// ___________DatList___________

TEST(DatList, can_create_list) // 1
{
	// Act & Assert
	ASSERT_NO_THROW(TDatList{});
}

TEST(DatList, is_empty_work_right_when_list_empty) // 2
{
	// Arrange
	TDatList tmp;

	// Act & Assert
	ASSERT_EQ(tmp.IsEmpty(), 1);
}

TEST(DatList, is_empty_work_right_when_list_no_empty) // 3
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	// Assert
	ASSERT_EQ(tmp.IsEmpty(), 0);
}

TEST(DatList, get_list_length_works_right) // 4
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsFirst(t);

	// Assert
	ASSERT_EQ(tmp.GetListLength(), 3);
}

TEST(DatList, go_next_works) // 5
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsFirst(t);

	// Assert
	ASSERT_NO_THROW(tmp.GoNext());
}

TEST(DatList, go_next_works_right) // 6
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsLast(t);

	tmp.GoNext();
	tmp.GoNext();

	// Assert
	ASSERT_TRUE(tmp.GetCurrentPos() == 2);
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, set_curr_pos_works_right) // 7
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsFirst(t);

	tmp.SetCurrentPos(2);

	// Assert
	ASSERT_TRUE(tmp.GetCurrentPos() == 2);
}

TEST(DatList, ins_first_works_right) // 8
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsFirst(t);

	tmp.Reset();

	// Assert
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, ins_last_works_right) // 9
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsLast(t);

	t = new TMonom(8, 230);
	tmp.InsLast(t);

	t = new TMonom(-7, 102);
	tmp.InsLast(t);

	tmp.SetCurrentPos(2);

	// Assert
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, ins_curr_works_right) // 10
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsLast(t);

	t = new TMonom(8, 230);
	tmp.InsLast(t);

	t = new TMonom(-7, 102);
	tmp.InsLast(t);

	tmp.Reset();
	tmp.GoNext();

	t = new TMonom(5, 200);
	tmp.InsCurrent(t);

	tmp.Reset();
	tmp.GoNext();

	// Assert
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, reset_works_right) // 11
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsFirst(t);

	tmp.GoNext();
	tmp.GoNext();
	tmp.Reset();

	// Assert
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, del_list_works_right) // 12
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsFirst(t);

	t = new TMonom(-7, 102);
	tmp.InsFirst(t);

	tmp.DelList();

	// Assert

	ASSERT_EQ(tmp.IsEmpty(), 1);
}

TEST(DatList, del_first_works_right) // 13
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsLast(t);

	tmp.DelFirst();
	tmp.Reset();

	// Assert
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, del_curr_works_right) // 14
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act

	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsLast(t);

	t = new TMonom(-7, 102);
	tmp.InsLast(t);

	t = new TMonom(5, 102);
	tmp.InsLast(t);

	tmp.SetCurrentPos(2);
	tmp.DelCurrent();
	tmp.SetCurrentPos(2);

	// Assert
	ASSERT_TRUE(tmp.GetDatValue() == t);
}

TEST(DatList, is_list_ended_works_right_when_it_is_ended) // 15
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsLast(t);

	t = new TMonom(-7, 102);
	tmp.InsLast(t);

	tmp.SetCurrentPos(2);
	tmp.GoNext();

	// Assert
	ASSERT_EQ(tmp.IsListEnded(), 1);
}

TEST(DatList, is_list_ended_works_right_when_it_is_not_ended) // 16
{
	// Arrange
	TDatList tmp;
	PTMonom t;

	// Act
	t = new TMonom(-7, 21);
	tmp.InsFirst(t);

	t = new TMonom(8, 230);
	tmp.InsLast(t);

	t = new TMonom(-7, 102);
	tmp.InsLast(t);

	tmp.SetCurrentPos(1);

	// Assert
	ASSERT_EQ(tmp.IsListEnded(), 0);
}

TEST(DatList, cant_delete_from_empty_list) // 17
{
	// Arrange
	TDatList tmp;

	// Act & Assert
	ASSERT_ANY_THROW(tmp.DelFirst());
	ASSERT_ANY_THROW(tmp.DelCurrent());
}

// ___________Polinom___________

TEST(Polinom, can_create_polinom)
{
	// Arrange
	int m[][2] = { {2, 220}, {-4, 240}, {8, 321}, {4, 457}, {1, 12} };
	
	// Act & Assert
	ASSERT_NO_THROW(TPolinom p(m, 5));
}

TEST(Polinom, can_copy_polinom)
{
	// Arrange
	int m[][2] = { {2, 220}, {-4, 240}, {8, 321}, {4, 457}, {1, 12} };
	TPolinom p1(m, 5);

	// Act & Assert
	ASSERT_NO_THROW(TPolinom p2(p1));
}

TEST(Polinom, copy_polinom_right)
{
	// Arrange
	int m[][2] = { {2, 220}, {-4, 240}, {8, 321}, {4, 457}, {1, 12} };
	TPolinom p1(m, 5);
	TPolinom p2(p1);

	// Act & Assert
	ASSERT_TRUE(p1 == p2);
}

TEST(Polinom, can_add_with_assignment)
{
	// Arrange
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 321}, {4, 457}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 322}, {4, 478}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	// Act & Assert
	ASSERT_NO_THROW(p1 += p2);
}

TEST(Polinom, add_with_assignment_right)
{
	// Arrange
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	int m3[][2] = { {7, 220}, {4, 240}, {7, 122}, {8, 121}, {4, 78}, {4, 57}, {3, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);
	TPolinom p3(m3, 7);

	// Act
	p1 += p2;
	
	// Assert
	ASSERT_TRUE(p1 == p3);
}

TEST(Polinom, can_compare)
{
	// Arrange
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	// Act & Assert
	ASSERT_NO_THROW(p1 == p2);
}

TEST(Polinom, compare_right)
{
	// Arrange
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	// Act & Assert
	ASSERT_FALSE(p1 == p2);
}

TEST(Polinom, can_assign)
{
	// Arrange
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);
	
	// Act & Assert
	ASSERT_NO_THROW(p1 = p2);
}

TEST(Polinom, assign_right)
{
	// Arrange
	int m1[][2] = { {2, 220}, {-4, 240}, {8, 121}, {4, 57}, {1, 12} };
	int m2[][2] = { {5, 220}, {8, 240}, {7, 122}, {4, 78}, {2, 12} };
	TPolinom p1(m1, 5);
	TPolinom p2(m2, 5);

	// Act
	p1 = p2;

	// Assert
	ASSERT_TRUE(p1 == p2);
}