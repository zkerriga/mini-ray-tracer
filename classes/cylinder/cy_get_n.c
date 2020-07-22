/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:30:46 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 16:30:48 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "func.h"
#include "math.h"

static t_bool		is_plane(t_cylinder *self, t_point *point)
{
	t_point		up;
	t_point		down;
	t_3dvector	tmp;

	set_point(&up, self->point.x + (self->height / 2) * self->vector.x,
				self->point.y + (self->height / 2) * self->vector.y,
				self->point.z + (self->height / 2) * self->vector.z);
	set_vector(&tmp, &up, point);
	normalize(&tmp);
	if (fbetween(vdot(&tmp, &self->vector), -INACCURACY, +INACCURACY))
		return (TRUE);
	set_point(&down, self->point.x - (self->height / 2) * self->vector.x,
				self->point.y - (self->height / 2) * self->vector.y,
				self->point.z - (self->height / 2) * self->vector.z);
	set_vector(&tmp, &down, point);
	normalize(&tmp);
	if (fbetween(vdot(&tmp, &self->vector), -INACCURACY, +INACCURACY))
		return (TRUE);
	return (FALSE);
}

t_3dvector		*cy_get_n(t_cylinder *self, t_point *point, t_point *camera)
{
	t_3dvector *norm;
	t_3dvector camera_to_point;
	t_3dvector point_to_center;
	t_3dvector orthogonal;

	if (!(norm = (t_3dvector *) malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	set_vector(&point_to_center, point, &self->point);
//	if (abs(vdot(&camera_to_point, &self->vector)) == self->height / 2)
	if (is_plane(self, point))
	{
		*norm = self->vector;
	}
	else
	{
		vprod(&orthogonal, &point_to_center, &self->vector);
		vprod(norm, &orthogonal, &self->vector);
	}
	set_vector(&camera_to_point, point, camera);
	if (vdot(norm, &camera_to_point) > 0.f)
		reverse_vec(norm);
	return (normalize(norm));
}
