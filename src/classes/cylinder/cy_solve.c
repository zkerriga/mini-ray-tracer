/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:30:59 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 16:31:01 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "render.h"

static void	min_solution_of_equation(float t[2], const float k[3], t_limits *l)
{
	float	discriminant;
	float	t1;
	float	t2;
	t_bool	t1_is_biggest;

	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0)
	{
		t1 = -1.f;
		t2 = -1.f;
	}
	else
	{
		t1 = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
		t2 = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
		t1 = fbetween(t1, l->min, l->max) ? t1 : -1.f;
		t2 = fbetween(t2, l->min, l->max) ? t2 : -1.f;
	}
	t1_is_biggest = t2 > 0.f && (t1 < 0.f || t2 < t1);
	t[0] = t1_is_biggest ? t2 : t1;
	t[1] = t1_is_biggest ? t1 : t2;
}

static t_bool			check_intersection(t_cylinder *self, t_point *intersection)
{
	if (pow(modulep(intersection, &self->point), 2) * 4 > self->diameter * self->diameter + self->height * self->height)
		return (FALSE);
	else
		return (TRUE);
}

static float			check_circle(t_cylinder *self, t_point *camera, t_vec3 *ray, float t)
{
	t_point		point;

	vset(&point, camera->x + t * ray->x, camera->y + t * ray->y,
		 camera->z + t * ray->z);
	if (pow(modulep(&point, &self->point), 2) * 4 < self->diameter * self->diameter + self->height * self->height)
		return (t);
	else
		return (-1.f);
}

static float			check_plane(t_cylinder *self, t_point *origin, t_vec3 *ray,
									t_limits *l)
{
	float	t[2];
	float	denominator;
	t_vec3	op;

	if (fbetween((denominator = vdot(&self->vector, ray)),
					-INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&op, origin, &self->up_center);
	t[0] = -vdot(&self->vector, &op) / denominator;
	vget(&op, origin, &self->down_center);
	t[1] = -vdot(&self->vector, &op) / denominator;
	if (fbetween(t[0], l->min, l->max) &&
		!(fbetween(t[1], l->min, l->max) && t[0] > t[1]))
		return (check_circle(self, origin, ray, t[0]));
	else if (fbetween(t[1], l->min, l->max))
		return (check_circle(self, origin, ray, t[1]));
	else
		return (-1.f);
}

float			cy_solve(t_cylinder *self, t_point *origin, t_vec3 *ray,
							t_limits *l)
{
	float		t[3];
	t_vec3		op;
	float		k[3];
	t_point		intersection;

	vget(&op, origin, &self->point);
	k[0] = vdot(ray, &self->vector);
	k[2] = vdot(&op, &self->vector);
	k[1] = 2 * (vdot(ray, &op) - k[0] * k[2]);
	k[0] = vdot(ray, ray) - k[0] * k[0];
	k[2] = vdot(&op, &op) - k[2] * k[2] - self->radius_square;
	min_solution_of_equation(t, k, l);
	t[2] = check_plane(self, origin, ray, l);
	if (t[0] > 0.f && (t[2] < 0 || t[2] > t[0]))
	{
		vset(&intersection, origin->x + t[0] * ray->x,
			 origin->y + t[0] * ray->y, origin->z + t[0] * ray->z);
		if (check_intersection(self, &intersection))
			return (t[0]);
	}
	return (t[2]);
}
