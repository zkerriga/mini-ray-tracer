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

#include "render.h"

/*
** The function gets the light and should add its effect on the pixel.
*/

void	get_diffuse(t_rgbvec *diffuse, t_light *light, t_vec3 *norm,
					t_point *point)
{
	float		diff;
	t_vec3		light_vec;
	t_rgbvec	color;

	vget(&light_vec, &light->point, point);
	normalize(&light_vec);
	if ((diff = maxf(vdot(norm, &light_vec), 0.f)))
	{
		color.r = diff * light->color.r;
		color.g = diff * light->color.g;
		color.b = diff * light->color.b;
		color_sum(diffuse, diffuse, &color);
	}
	free(norm);
}
