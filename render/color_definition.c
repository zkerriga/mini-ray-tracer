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

static void		setup_ambient(t_color *color, t_color found, t_color ambient, float bright)
{
	short	tmp;

	if ((tmp = found.r * (ambient.r * bright / 255)) > 255)
		color->r = 255;
	else
		color->r = tmp;
	if ((tmp = found.g * (ambient.g * bright / 255)) > 255)
		color->g = 255;
	else
		color->g = tmp;
	if ((tmp = found.b * (ambient.b * bright / 255)) > 255)
		color->b = 255;
	else
		color->b = tmp;
}

/*static void		setup_color(t_color *color, t_color found, t_color ambient, float bright)
{
	short	tmp;

	if ((short)(ambient.r * bright) + (short)(ambient.g * bright) + (short)(ambient.b * bright) > 0)
	{
		if ((tmp = (found.r + ambient.r) * bright) > 255)
			color->r = 255;
		else
			color->r = tmp;
		if ((tmp = (found.g + ambient.g) * bright) > 255)
			color->g = 255;
		else
			color->g = tmp;
		if ((tmp = (found.b + ambient.b) * bright) > 255)
			color->b = 255;
		else
			color->b = tmp;
	}
	else
	{
		color->r = 0;
		color->g = 0;
		color->b = 0;
	}
}*/

/*
** The function gets the point where the ray collides with the object and
** the object. Next, the function determines how the object's color
** should change and returns an integer of the color.
** The function must clear the point that was created for it!
*/

int		color_definition(t_scene *scene, t_any_object *found, t_point *point)
{
	t_color		color;
	t_light		*light;
	t_list		*list;

	setup_ambient(&color, found->color, scene->ambient->color, scene->ambient->light_ratio);
	list = scene->lights;
	while (list)
	{
		//color find work
		list = list->next;
	}
	free(point);
	return (color_to_int(color));
}