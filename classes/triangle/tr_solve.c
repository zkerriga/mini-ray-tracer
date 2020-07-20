/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:31:20 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 16:31:24 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "func.h"
#include "math.h"

/*
float	get_tr_square(float a, float b, float c)
{
	float p;

	p = (a + b + c) / 2;
	return (sqrt(p * (p - a) * (p - b) * (p -c)));
}

t_bool			check_in_triangle(t_triangle *self, t_point *dot)
{
	const float	inaccuracy = 0.01f;
	float		tr_square;
	float		fs;
	float		st;
	float		ft;

	tr_square = get_tr_square((fs = modulep(&self->first, &self->b_point)),
								(st = modulep(&self->c_point, &self->b_point)),
								(ft = modulep(&self->first, &self->c_point)));
	return (fbetween(get_tr_square(fs, modulep(&self->b_point, dot), modulep(&self->first, dot)) +
					get_tr_square(st, modulep(&self->b_point, dot), modulep(&self->c_point, dot)) +
					get_tr_square(ft, modulep(&self->c_point, dot), modulep(&self->first, dot)),
					tr_square - inaccuracy, tr_square + inaccuracy));
}

float			tr_solve(t_triangle *self, t_point *camera, t_3dvector *ray,
							t_limits *l)
{
	float		t;
	t_3dvector	cam_to_first;
	t_point		dot;

	if ((t = vdot(&self->norm, ray)) == 0.f)
		return (-1.f);
	set_vector(&cam_to_first, camera, &self->first);
	t = -vdot(&self->norm, &cam_to_first) / t;
	if (fbetween(t, l->min, l->max))
	{
		set_point(&dot, camera->x + t * ray->x, camera->y + t * ray->y, camera->z + t * ray->z);
		if (check_in_triangle(self, &dot))
			return (t);
	}
	return (-1.f);
}
*/

t_bool	check_in_triangle(t_triangle *self, t_point *intersection)
{
	float	a = vdot(&self->ab_edge, &self->ab_edge);
	float	b = vdot(&self->ab_edge, &self->ac_edge);
	float	c = vdot(&self->ac_edge, &self->ac_edge);
	float	D;
	t_3dvector	tmp1;
	t_3dvector	tmp2;
	t_3dvector	u_beta;
	t_3dvector	u_gama;
	t_3dvector	r;

	D = a * c - b * b;
	vsubtract(&u_beta, vmulti(&tmp1, &self->ab_edge, c / D), vmulti(&tmp2, &self->ac_edge, b / D));
	vsubtract(&u_gama, vmulti(&tmp1, &self->ac_edge, a / D), vmulti(&tmp2, &self->ab_edge, b / D));
	set_vector(&r, intersection, &self->a_point);
	if ((a = vdot(&u_beta, &r)) < 0 || (b = vdot(&u_gama, &r)) < 0 || 1 < a + b)
		return (FALSE);
	return (TRUE);
}

float			tr_solve(t_triangle *self, t_point *camera, t_3dvector *ray,
						  t_limits *l)
{
	float		t;
	t_3dvector	cam_to_first;
	t_point		intersection;

	if ((t = vdot(&self->norm, ray)) == 0.f)
		return (-1.f);
	set_vector(&cam_to_first, camera, &self->a_point);
	t = -vdot(&self->norm, &cam_to_first) / t;
	if (fbetween(t, l->min, l->max))
	{
		set_point(&intersection, camera->x + t * ray->x, camera->y + t * ray->y, camera->z + t * ray->z);
		if (check_in_triangle(self, &intersection))
			return (t);
	}
	return (-1.f);
}
