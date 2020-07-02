#include "gtest/gtest.h"

extern "C" {
#include <stdio.h>
#include "func.h"
};

void	get_bits(int n) {
	char	bits[sizeof(int) * 8];
	int		clone;

	clone = n;
	for (int i = sizeof(int) * 8 - 1; i > -1; i--) {
		bits[i] = clone % 2;
		clone /= 2;
	}
	for (int i = 0; i < sizeof(int) * 8; i++) {
		printf("%d", bits[i]);
		if (i == 7 || i == 15 || i == 23)
			printf(" ");
	}
	printf("\n");
}

TEST (color, color_0)
{

	t_color color;

	color.r = 224;
	color.g = 4;
	color.b = 128;
	get_bits(color_to_int(color));
	ASSERT_EQ(0b111000000000010010000000, color_to_int(color));
}
