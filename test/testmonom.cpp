#include "Monom.h"
#include <gtest.h>

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(PTMonom pMonom = new TMonom(12, 333));
}

TEST(TMonom, can_assighn_monom)
{
	PTMonom pMonom = new TMonom(12, 123);
	PTMonom pMonom_a = new TMonom();

	ASSERT_NO_THROW(pMonom_a = pMonom);
}

TEST(TMonom, monom_has_its_own_memory)
{
	PTMonom pMonom = new TMonom(12, 123);
	PTMonom pMonom_a = new TMonom();

	EXPECT_NE(&pMonom, &pMonom_a);
}