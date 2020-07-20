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

	tr_square = get_tr_square((fs = modulep(&self->first, &self->second)),
								(st = modulep(&self->third, &self->second)),
								(ft = modulep(&self->first, &self->third)));
	return (fbetween(get_tr_square(fs, modulep(&self->second, dot), modulep(&self->first, dot)) +
					get_tr_square(st, modulep(&self->second, dot), modulep(&self->third, dot)) +
					get_tr_square(ft, modulep(&self->third, dot), modulep(&self->first, dot)),
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
