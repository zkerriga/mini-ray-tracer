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

#include "triangle.h"
#include "render.h"

t_bool			check_in_triangle(t_triangle *self, t_point *intersection)
{
	float	a = vdot(&self->ab_edge, &self->ab_edge);
	float	b = vdot(&self->ab_edge, &self->ac_edge);
	float	c = vdot(&self->ac_edge, &self->ac_edge);
	float	D;
	t_vec3	tmp1;
	t_vec3	tmp2;
	t_vec3	u_beta;
	t_vec3	u_gama;
	t_vec3	r;

	D = a * c - b * b;
	vsubtract(&u_beta, vmulti(&tmp1, &self->ab_edge, c / D), vmulti(&tmp2, &self->ac_edge, b / D));
	vsubtract(&u_gama, vmulti(&tmp1, &self->ac_edge, a / D), vmulti(&tmp2, &self->ab_edge, b / D));
	vget(&r, intersection, &self->a_point);
	if ((a = vdot(&u_beta, &r)) < 0 || (b = vdot(&u_gama, &r)) < 0 || 1 < a + b)
		return (FALSE);
	return (TRUE);
}

float			tr_solve(t_triangle *self, t_point *camera, t_vec3 *ray,
						  t_limits *l)
{
	float		t;
	t_vec3	cam_to_first;
	t_point		intersection;

//	if ((t = vdot(&self->norm, ray)) == 0.f)
	if (fbetween((t = vdot(&self->norm, ray)), -INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&cam_to_first, camera, &self->a_point);
	t = -vdot(&self->norm, &cam_to_first) / t;
	if (fbetween(t, l->min, l->max))
	{
		vset(&intersection, camera->x + t * ray->x, camera->y + t * ray->y,
			 camera->z + t * ray->z);
		if (check_in_triangle(self, &intersection))
			return (t);
	}
	return (-1.f);
}
