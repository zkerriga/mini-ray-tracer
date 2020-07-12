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

/*
** The function gets the light and should add its effect on the pixel.
*/

void	get_diffuse(t_rgbvec *diffuse, t_light *light,
					t_any_object *obj, t_point *point, t_point *camera)
{
	float		diff;
	t_3dvector	*norm;
	t_3dvector	light_vec;
	t_rgbvec	color;

	set_vector(&light_vec, &light->point, point);
	norm = obj->get_n(obj, point, camera);
	normalize(&light_vec);
	if ((diff = maxf(vdot(norm, &light_vec), 0.f)))
	{
		color.r = diff * light->color.r;
		color.g = diff * light->color.g;
		color.b = diff * light->color.b;
		color_sum(diffuse, *diffuse, color);
	}
	free(norm);
}
