#include "gtest/gtest.h"

extern "C" {
#include <stdio.h>
#include "func.h"
};

static void	set_a_vector(t_3dvector *dest, float x, float y, float z)
{
	dest->x = x;
	dest->y = y;
	dest->z = z;
}

TEST (vectors, vprod)
{
	t_3dvector	dest;
	t_3dvector	one;
	t_3dvector	two;

	set_a_vector(&two, 0.f, 1.f, 0.f);
	set_a_vector(&one, 1.f, 0.f, 0.f);
	vprod(&dest, one, two);
	printf("dest={%.2f, %.2f, %.2f}", dest.x, dest.y, dest.z);
	ASSERT_EQ(dest.x + dest.y + dest.z, 1.f);
}
