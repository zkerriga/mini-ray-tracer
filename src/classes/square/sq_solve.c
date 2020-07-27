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

static void	create_ort_vec(t_vec3 *dest, t_vec3 *norm)
{
	if (norm->x != 0.f)
		vset(dest, -(norm->y) / norm->x, 1.f, 0.f);
	else if (norm->y != 0.f)
		vset(dest, 1.f, -(norm->x) / norm->y, 0.f);
	else
		vset(dest, 0.f, 1.f, -(norm->y) / norm->z);
	normalize(dest);
}

float		sq_solve(t_square *self, t_point *origin, t_vec3 *ray, t_limits *l)
{
	float	t;
	t_point	dot;
	t_vec3	tmp;
	t_vec3	right;
	t_vec3	up;

	if (fbetween((t = vdot(&self->norm, ray)), -INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&tmp, origin, &self->center);
	t = -vdot(&self->norm, &tmp) / t;
	if (fbetween(t, l->min, l->max))
	{
		create_ort_vec(&right, &self->norm);
		vprod(&up, &right, &self->norm);
		vset(&dot, origin->x + t * ray->x, origin->y + t * ray->y,
				origin->z + t * ray->z);
		vget(&tmp, &dot, &self->center);
		if (fbetween(vdot(&tmp, &right) / self->side_size, -0.5f, 0.5f)
			&& fbetween(vdot(&tmp, &up) / self->side_size, -0.5f, 0.5f))
			return (t);
	}
	return (-1.f);
}
