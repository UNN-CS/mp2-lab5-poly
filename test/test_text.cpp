#include "Polinom.h"
#include "DatList.h"

#include <gtest.h>

#include <iostream>
using namespace std;

TEST(TPolinom, can_create_polinom) {
    int m[][2] = { {2, 3}, {4, 5} };
    ASSERT_NO_THROW(TPolinom p(m, 2));
}