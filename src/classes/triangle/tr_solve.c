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
	float	k[3];
	t_vec3	tmp1;
	t_vec3	tmp2;
	t_vec3	u_beta;
	t_vec3	u_gama;

	k[2] = self->ab_ab_coef * self->ac_ac_coef -
			self->ab_ac_coef * self->ab_ac_coef;
	vsubtract(&u_beta, vmulti(&tmp1, &self->ab_edge, self->ac_ac_coef / k[2]),
				vmulti(&tmp2, &self->ac_edge, self->ab_ac_coef / k[2]));
	vsubtract(&u_gama, vmulti(&tmp1, &self->ac_edge, self->ab_ab_coef / k[2]),
				vmulti(&tmp2, &self->ab_edge, self->ab_ac_coef / k[2]));
	vget(&tmp1, intersection, &self->a_point);
	if ((k[0] = vdot(&u_beta, &tmp1)) < 0 ||
		(k[1] = vdot(&u_gama, &tmp1)) < 0 || 1 < k[0] + k[1])
		return (FALSE);
	return (TRUE);
}

float			tr_solve(t_triangle *self, t_point *camera, t_vec3 *ray,
							t_limits *l)
{
	float		t;
	t_vec3		cam_to_a;
	t_point		intersection;

	if (fbetween((t = vdot(&self->norm, ray)), -INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&cam_to_a, camera, &self->a_point);
	t = -vdot(&self->norm, &cam_to_a) / t;
	if (fbetween(t, l->min, l->max))
	{
		vset(&intersection, camera->x + t * ray->x, camera->y + t * ray->y,
				camera->z + t * ray->z);
		if (check_in_triangle(self, &intersection))
			return (t);
	}
	return (-1.f);
}
