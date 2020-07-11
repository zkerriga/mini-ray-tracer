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
	t_rgbvec color;

	color.r = 224.f / 255;
	color.g = 4.f / 255;
	color.b = 128.f / 255;
	get_bits(color_to_int(color));
	ASSERT_EQ(0b111000000000010010000000, color_to_int(color));
}

TEST (color, color_1)
{
	t_rgbvec dest;
	t_rgbvec color;
	t_rgbvec color2;

	color.r = 200.f / 255;
	color.g = 0.f / 255;
	color.b = 254.f / 255;
	color2.r = 10.f / 255;
	color2.g = 10.f / 255;
	color2.b = 10.f / 255;
	color_sum(&dest, color, color2);
	printf("->%d:%d:%d<-\n", dest.r, dest.g, dest.b);
	ASSERT_EQ(dest.r, 210);
	ASSERT_EQ(dest.g, 10);
	ASSERT_EQ(dest.b, 255);
}

TEST (color, color_2)
{
	t_rgbvec dest;
	t_rgbvec color;
	t_rgbvec color2;

	color.r = 200.f / 255;
	color.g = 0.f / 255;
	color.b = 254.f / 255;
	color2.r = 10.f / 255;
	color2.g = 10.f / 255;
	color2.b = 10.f / 255;
	color_sum(&dest, color, color2);
	printf("->%d:%d:%d<-\n", dest.r, dest.g, dest.b);
	ASSERT_EQ(dest.r, 205);
	ASSERT_EQ(dest.g, 5);
	ASSERT_EQ(dest.b, 255);
}