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

#include "minirt.h"
#include "square.h"
#include "func.h"

static void	create_ort_vec(t_3dvector *dest, t_3dvector *norm)
{
	if (norm->x != 0.f)
		set_point(dest, -(norm->z + norm->y) / norm->x, 1.f, 1.f);
	else if (norm->y != 0.f)
		set_point(dest, 1.f, -(norm->z + norm->x) / norm->y, 1.f);
	else
		set_point(dest, 1.f, 1.f, -(norm->y + norm->x) / norm->z);
	normalize(dest);
}

float		sq_solve(t_square *self, t_point *camera, t_3dvector *ray, t_limits *l)
{
	float		t;
	t_point		dot;
	t_3dvector	tmp;
	t_3dvector	right;
	t_3dvector	up;

	if ((t = vdot(&self->vector, ray)) == 0.f)
		return (-1.f);
	set_vector(&tmp, camera, &self->center);
	t = -vdot(&self->vector, &tmp) / t;
	if (fbetween(t, l->min, l->max))
	{
		create_ort_vec(&right, &self->vector);
		vprod(&up, &right, &self->vector);
		set_point(&dot, camera->x + t * ray->x, camera->y + t * ray->y, camera->z + t * ray->z);
		set_vector(&tmp, &dot, &self->center);
		if (fbetween(vdot(&tmp, &right) / self->side_size, -0.5f, 0.5f)
			&& fbetween(vdot(&tmp, &up) / self->side_size, -0.5f, 0.5f))
			return (t);
	}
	return (-1.f);
}
