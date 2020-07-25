#include "gtest/gtest.h"

extern "C" {
#include <stdio.h>
#include "func.h"
#include "minirt.h"
#include "math.h"
};

float	sss(float a, float b, float c)
{
	float p;

	p = (a + b + c) / 2;
	return (sqrt(p * (p - a) * (p - b) * (p -c)));
}

TEST (triangle, t1)
{
	t_point	f;
	t_point	s;
	t_point	t;
	t_point	p;
	t_point	d;
	t_vec3	fs;
	t_vec3	st;
	t_vec3	tf;

	t_vec3	fp;
	t_vec3	sp;
	t_vec3	tp;

	t_vec3	fd;
	t_vec3	sd;
	t_vec3	td;

	set_point((t_vec3 *)&f, 1.f, 1.f, 0.f);
	set_point((t_vec3 *)&s, 3.f, 6.f, 0.f);
	set_point((t_vec3 *)&t, 11.f, 2.f, 0.f);
	set_point((t_vec3 *)&p, 8.f, 3.f, 0.f);
	set_point((t_vec3 *)&d, 1.f, 2.f, 0.f);

	set_vector(&fs, &s, &f);
	set_vector(&st, &t, &s);
	set_vector(&tf, &f, &t);
	set_vector(&fp, &p, &f);
	set_vector(&sp, &p, &s);
	set_vector(&tp, &p, &t);
	set_vector(&fd, &d, &f);
	set_vector(&sd, &d, &s);
	set_vector(&td, &d, &t);

//	printf("P - result: %.2f : %.2f : %.2f\n", vdot(&fs, &fp), vdot(&st, &sp), vdot(&tf, &tp));
//	printf("D - result: %.2f : %.2f : %.2f\n", vdot(&fs, &fd), vdot(&st, &sd), vdot(&tf, &td));
	printf("Sum S for P = %.4f\nS for triangle = %.4f\n", sss(modulep(&f, &p),modulep(&s, &p),modulep(&f, &s)) + sss(modulep(&s, &p),modulep(&t, &p),modulep(&t, &s)) + sss(modulep(&f, &p),modulep(&t, &p),modulep(&f, &t)), sss(modulep(&f, &s),modulep(&s, &t),modulep(&t, &f)));
	printf("Sum S for D = %.4f\nS for triangle = %.4f\n", sss(modulep(&f, &d),modulep(&s, &d),modulep(&f, &s)) + sss(modulep(&s, &d),modulep(&t, &d),modulep(&t, &s)) + sss(modulep(&f, &d),modulep(&t, &d),modulep(&f, &t)), sss(modulep(&f, &s),modulep(&s, &t),modulep(&t, &f)));
	ASSERT_EQ(1, 1);
}
