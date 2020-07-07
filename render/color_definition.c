/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_definition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:52:46 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/06 18:52:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"
#include "func.h"

static void		set_ambient(t_rgbvec *dest, t_rgbvec ambient, float bright)
{
	dest->r = bright * ambient.r;
	dest->g = bright * ambient.g;
	dest->b = bright * ambient.b;
}

static void		zero_color(t_rgbvec *color)
{
	color->r = 0.0f;
	color->g = 0.0f;
	color->b = 0.0f;
}

/*
** The function gets the point where the ray collides with the object and
** the object. Next, the function determines how the object's color
** should change and returns an integer of the color.
** The function must clear the point that was created for it!
*/

int		color_definition(t_scene *scene, t_any_object *obj, t_point *point)
{
	t_rgbvec		ambient;
	t_rgbvec		diffuse;
	t_rgbvec		result_color;
	t_light			*light;
	t_list			*list;

	zero_color(&result_color);
	zero_color(&diffuse);
	set_ambient(&ambient, scene->ambient->color, scene->ambient->light_ratio);
	list = scene->lights;
	while (list)
	{
		//diffuse definition
		list = list->next;
	}
	free(point);
	color_multi(&result_color, *color_sum(&result_color, ambient, diffuse), obj->color);
	return (color_to_int(result_color));
}
