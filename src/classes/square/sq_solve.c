/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 08:38:07 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 08:38:08 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "render.h"

float	sq_solve(t_square *self, t_point *origin, t_vec3 *ray, t_limits *l)
{
	float	t;
	t_point	intersection;
	t_vec3	oc;

	if (fbetween((t = vdot(&self->norm, ray)), -INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&oc, origin, &self->center);
	t = -vdot(&self->norm, &oc) / t;
	if (fbetween(t, l->min, l->max))
	{
		vset(&intersection, origin->x + t * ray->x, origin->y + t * ray->y,
				origin->z + t * ray->z);
		vget(&oc, &intersection, &self->center);
		if (fbetween(vdot(&oc, &self->right) / self->side_size, -0.5f, 0.5f)
			&& fbetween(vdot(&oc, &self->up) / self->side_size, -0.5f, 0.5f))
			return (t);
	}
	return (-1.f);
}
