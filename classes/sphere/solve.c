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

float		solve(t_sphere *self, t_point camera, t_3dvector ray)
{
	float		t1;
	float		t2;
	t_3dvector	oc;
	float		disc;
	float		k1;
	float		k2;
	float		k3;

	k1 = vdot(ray, ray);
	k2 = 2 * vdot(oc, ray);
	k3 = vdot(oc, oc) - pow(self->diameter / 2, 2);
	oc.x = camera.x - self->center.x;
	oc.y = camera.y - self->center.y;
	oc.z = camera.z - self->center.z;
	disc = k2 * k2 - 4 * k1 * k3;
	if (disc < 0)
		return (-1.0f);
	t1 = (-k2 + sqrt(disc)) / (2 * k1);
	t2 = (-k2 - sqrt(disc)) / (2 * k1);
	if (t1 < t2 && t1 > MIN_T && t1 < MAX_T)
		return (t1);
	else if (t2 > MIN_T && t2 < MAX_T)
		return (t2);
}
