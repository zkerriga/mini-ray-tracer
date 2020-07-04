/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:38:33 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/03 17:38:46 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "func.h"
#include "render.h"

static float	solution_of_equation(float k1, float k2, float k3, t_bool flag)
{
	float			discriminant;
	float			t1;
	static float	t2;

	if (flag)
	{
		discriminant = k2 * k2 - 4 * k1 * k3;
		if (discriminant < 0)
		{
			t1 = -1.0f;
			t2 = -1.0f;
		}
		else
		{
			t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
			t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
		}
		return (t1);
	}
	else
		return (t2);
}

float			solve(t_sphere *self, t_point *camera, t_3dvector *ray)
{
	float		t1;
	float		t2;
	t_3dvector	oc;

	oc.x = camera->x - self->center.x;
	oc.y = camera->y - self->center.y;
	oc.z = camera->z - self->center.z;
	t1 = solution_of_equation(vdot(ray, ray), 2 * vdot(&oc, ray),
				vdot(&oc, &oc) - pow(self->diameter / 2, 2), TRUE);
	t2 = solution_of_equation(0,0,0, FALSE);
	if (t1 > MIN_T && t1 < MAX_T &&
		(t2 > MIN_T && t2 < MAX_T && t1 < t2 || t2 < MIN_T || t2 > MAX_T))
		return (t1);
	else if (t2 > MIN_T && t2 < MAX_T)
		return (t2);
	else
		return (-1.0f);
}
