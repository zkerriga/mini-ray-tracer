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

/*
** The function gets the light and should add its effect on the pixel.
*/

void	get_diffuse(t_scene *scene, t_rgbvec *diffuse, t_light *light, t_any_object *obj, t_point *point)
{
	float		diff;
	t_3dvector	*norm;
	t_3dvector	light_vec;
	t_rgbvec	color;

	light_vec.x = light->point.x - point->x;
	light_vec.y = light->point.y - point->y;
	light_vec.z = light->point.z - point->z;
	if (!is_shadow_point(scene, &light->point, &light_vec))
	{
		norm = obj->get_n(obj, point);
		if ((diff = maxf(vdot(*norm, light_vec) / module(light_vec), 0.0f)))
		{
			color.r = diff * light->color.r;
			color.g = diff * light->color.g;
			color.b = diff * light->color.b;
			color_sum(diffuse, *diffuse, color);
		}
		free(norm);
	}
}
