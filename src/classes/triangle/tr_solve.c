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

t_bool	check_in_triangle(t_triangle *self, t_point *intersection)
{
	float	k1;
	float	k2;
	t_vec3	r;

	vget(&r, intersection, &self->a_point);
	if ((k1 = vdot(&self->u_beta, &r)) < 0 ||
		(k2 = vdot(&self->u_gama, &r)) < 0 || 1 < k1 + k2)
		return (FALSE);
	return (TRUE);
}

float	tr_solve(t_triangle *self, t_point *origin, t_vec3 *ray, t_limits *l)
{
	float		t;
	t_vec3		oa;
	t_point		intersection;

	if (fbetween((t = vdot(&self->norm, ray)), -INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&oa, origin, &self->a_point);
	t = -vdot(&self->norm, &oa) / t;
	if (fbetween(t, l->min, l->max))
	{
		vset(&intersection, origin->x + t * ray->x, origin->y + t * ray->y,
				origin->z + t * ray->z);
		if (check_in_triangle(self, &intersection))
			return (t);
	}
	return (-1.f);
}
