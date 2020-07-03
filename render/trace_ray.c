/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:48:05 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/03 16:48:08 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "func.h"

int		trace_ray(t_scene *scene, t_point *camera, t_3dvector *ray)
{
	static int		background = -1;
	t_list			*objects;
	t_any_object	*any;
	float			t;
	float			t_min;
	t_color			*color;

	objects = scene->objects;
	if (objects)
	{
		t_min = MAX_T;
		color = NULL;
		while (objects)
		{
			any = objects->content;
			if ((t = any->solve(any, camera, ray)) > 0 && t < t_min)
			{
				t_min = t;
				color = &any->color;
			}
			objects = objects->next;
		}
		if (color)
			return (color_to_int(*color));
	}
	if (background < 0)
		background = color_to_int(bright(&scene->ambient->color, scene->ambient->light_ratio));
	return (background);
}
