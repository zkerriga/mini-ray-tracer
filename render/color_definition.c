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

/*
** The function gets the point where the ray collides with the object and
** the object. Next, the function determines how the object's color
** should change and returns an integer of the color.
** The function must clear the point that was created for it!
*/

int		color_definition(t_scene *scene, t_any_object *found, t_point *point)
{
	t_color		color;

	color_copy(&color, found->color);
	//another color code
	free(point);
	if (scene->ambient)
		color_sum(&color, color, scene->ambient->color, scene->ambient->light_ratio);
	return (color_to_int(color));
}