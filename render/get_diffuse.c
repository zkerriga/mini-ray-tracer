/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diffuse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:23:38 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/07 18:24:10 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <func.h>
#include "minirt.h"
#include "render.h"

static float	maxf(float one, float two)
{
	return ((one > two) ? one : two);
}

void	get_diffuse(t_rgbvec *diffuse, t_light *light, t_any_object *obj, t_point *point)
{
	float		diff;
	t_3dvector	*norm;
	t_3dvector	light_vec;
	t_rgbvec	color;

	norm = obj->get_n(obj, point);
	light_vec.x = point->x - light->point.x;
	light_vec.y = point->y - light->point.y;
	light_vec.z = point->z - light->point.z;
	diff = maxf(vdot(norm, &light_vec) / module(light_vec), 0.0f);
	color.r = diff * light->color.r;
	color.g = diff * light->color.g;
	color.b = diff * light->color.b;
	diffuse = color_sum(diffuse, *diffuse, color);
}
