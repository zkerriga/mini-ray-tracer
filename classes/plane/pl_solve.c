/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:12:05 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:33:23 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "plane.h"
#include "func.h"

float	pl_solve(t_plane *self, t_point *camera, t_3dvector *ray, t_limits *l)
{
	float		t;
	t_3dvector	op;

	if ((t = vdot(&self->norm, ray)) == 0.f)
		return (-1.f);
	set_vector(&op, camera, &self->point);
	t = -vdot(&self->norm, &op) / t;
	if (fbetween(t, l->min, l->max))
		return (t);
	else
		return (-1.f);
}
