
#include "polinom.h"
#include "datlist.h"

#include "gtest.h"

#include <iostream>
using namespace std;

TEST(TPolinom, can_create_polinom) {
	int m[][2] = { { 2, 3 },{ 4, 5 } };
	ASSERT_NO_THROW(TPolinom p(m, 2));
}

TEST(TPolinom, can_create_copied_polinom) {
	int m[][2] = { { 2, 8 },{ 4, 5 } };
	TPolinom p(m, 2);
	ASSERT_NO_THROW(TPolinom p2 = p);
}

TEST(TPolinom, copied_polinom_is_equal_to_source_one) {
	int m[][2] = { { 2, 8 },{ 4, 5 } };
	TPolinom p1(m, 2);
	TPolinom p2 = p1;
	ASSERT_TRUE(p1 == p2);
}

TEST(TPolinom, copied_polinom_has_its_own_memory) {
	int m1[][2] = { { 2, 8 },{ 4, 5 } };
	int m2[][2] = { { 2, 6 },{ 5, 6 } };
	TPolinom p1(m1, 1), p2 = p1, p3(m2, 2);
	p1 = p3;
	ASSERT_FALSE(p1 == p2);
}


TEST(TPolinom, plus_test) {
	int m[][2] = { { -2, 59 },{ 5, 43 } };
	TPolinom p1, p2(m, 2);
	p1 += p2;
	ASSERT_TRUE(p1 == p2);
}

TEST(TPolinom, plus_test2) {
	int m[][2] = { { -2, 59 },{ 5, 43 } };
	TPolinom p1, p2(m, 2), p3(m, 2);
	p2 += p1;
	ASSERT_TRUE(p3 == p2);
}

TEST(TPolinom, plus_test3) {
	int m1[][2] = { { 1, 5 },{ 5, 4 },{ 3, 2 } };
	int m2[][2] = { { 3, 3 } };
	int m3[][2] = { { 1, 5 },{ 5, 4 },{ 3, 3 },{ 3, 2 } };
	TPolinom p1(m1, 3), p2(m2, 1), p3(m3, 4);
	p1 += p2;
	ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, plus_test4) {
	int m1[][2] = { { 1, 5 },{ 5, 4 },{ 3, 2 } };
	int m2[][2] = { { 3, 3 } };
	int m3[][2] = { { 1, 5 },{ 5, 4 },{ 3, 3 },{ 3, 2 } };
	TPolinom p1(m1, 3), p2(m2, 1), p3(m3, 4);
	p2 += p1;
	ASSERT_TRUE(p2 == p3);
}

TEST(TPolinom, plus_test5) {
	int m1[][2] = { { 1, 5 },{ 5, 4 },{ 3, 0 } };
	int m2[][2] = { { -1, 5 },{ -5, 4 },{ -2, 0 } };
	int m3[][2] = { { 1, 0 } };
	TPolinom p1(m1, 3), p2(m2, 3), p3(m3, 1);
	p1 += p2;
	ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, plus_test6) {
	int m1[][2] = { { 2, 5 },{ 5, 4 },{ 3, 0 } };
	int m2[][2] = { { -1, 5 },{ -5, 4 },{ -3, 0 } };
	int m3[][2] = { { 1, 5 } };
	TPolinom p1(m1, 3), p2(m2, 3), p3(m3, 1);
	p1 += p2;
	ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, plus_test7) {
	int m1[][2] = { { 1, 100 },{ 9, 10 },{ 2, 4 },{ 15, 0 } };
	int m2[][2] = { { 4, 100 },{ -2, 4 },{ 4, 2 },{ 5, 0 } };
	int m3[][2] = { { 5, 100 },{ 9, 10 },{ 4, 2 },{ 20, 0 } };
	TPolinom p1(m1, 4);
	TPolinom p2(m2, 4);
	TPolinom p3(m3, 4);
	p1 += p2;
	ASSERT_TRUE(p3 == p1);
}

TEST(TPolinom, plus_test8) {
	int m1[1000][2], m2[1000][2], m3[1000][2];
	for (int i = 0; i < 1000; i++)
	{
		m1[i][0] = i + 1, m1[i][1] = 999 - i;
		m2[i][0] = -i, m2[i][1] = 999 - i;
		m3[i][0] = 1, m3[i][1] = 999 - i;
	}
	TPolinom p1(m1, 1000), p2(m2, 1000), p3(m3, 1000);
	p1 += p2;
	ASSERT_TRUE(p1 == p3);
}

TEST(TPolinom, plus_test9) {
	TPolinom p1, p2, p3;
	p1 += p2;
	ASSERT_TRUE(p1 == p3);
}

TEST(TDatList, can_create_dat_list_object) {
	ASSERT_NO_THROW(TDatList tmp);
}


TEST(TDatList, can_insert_current_several_times) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	ASSERT_NO_THROW(List.InsCurrent(p));
	ASSERT_NO_THROW(List.InsCurrent(p));
	ASSERT_NO_THROW(List.InsCurrent(p));
	ASSERT_NO_THROW(List.InsCurrent(p));
	delete p;
}

TEST(TDatList, can_insert_last_several_times) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	ASSERT_NO_THROW(List.InsLast(p));
	ASSERT_NO_THROW(List.InsLast(p));
	delete p;
}

TEST(TDatList, can_delete_first_element_several_times) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.InsFirst(p);
	ASSERT_NO_THROW(List.DelFirst());
	ASSERT_NO_THROW(List.DelFirst());
	delete p;
}

TEST(TDatList, can_delete_current_element_several_times) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.InsFirst(p);
	ASSERT_NO_THROW(List.DelCurrent());
	ASSERT_NO_THROW(List.DelCurrent());
	delete p;
}

TEST(TDatList, cant_delete_from_empty_list) {
	TDatList List;
	ASSERT_ANY_THROW(List.DelFirst());
	ASSERT_ANY_THROW(List.DelCurrent());
}

TEST(TDatList, list_len_is_changed_after_inserts_and_deletes) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	ASSERT_TRUE(List.GetListLength() == 1);
	List.InsLast(p);
	ASSERT_TRUE(List.GetListLength() == 2);
	List.InsCurrent(p);
	ASSERT_TRUE(List.GetListLength() == 3);
	List.DelFirst();
	ASSERT_TRUE(List.GetListLength() == 2);
	List.DelCurrent();
	ASSERT_TRUE(List.GetListLength() == 1);
}

TEST(TDatList, list_del_function_is_correct) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.InsLast(p);
	List.InsCurrent(p);
	List.DelList();
	ASSERT_TRUE(List.GetListLength() == 0);
	ASSERT_TRUE(List.GetDatValue() == NULL);
	ASSERT_TRUE(List.GetCurrentPos() == -1);
}

TEST(TDatList, can_go_next) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.InsFirst(p);
	List.InsFirst(p);
	List.Reset();
	ASSERT_NO_THROW(List.GoNext());
	ASSERT_TRUE(List.GetCurrentPos() == 1);
}

TEST(TDatList, cant_go_next_after_last_elem) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.Reset();
	List.GoNext();
	ASSERT_ANY_THROW(List.GoNext());
}

TEST(TDatList, reset_function_is_correct) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.Reset();
	ASSERT_TRUE(List.GetCurrentPos() == 0);
	List.DelFirst();
	List.Reset();
	ASSERT_TRUE(List.GetCurrentPos() == -1);
}

TEST(TDatList, is_list_ended_function_is_correct) {
	TDatList List;
	PTMonom p = new TMonom(5, 6);
	List.InsFirst(p);
	List.Reset();
	List.GoNext();
	ASSERT_TRUE(List.IsListEnded() == 1);
}