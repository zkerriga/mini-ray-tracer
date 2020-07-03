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
#include "func.h"

int		trace_ray(t_scene *scene, t_point camera, t_3dvector *ray)
{
	static int	background = -1;
	const float	min_t = 1;
	const float	max_t = 1048576;

	if (background < 0)
		background = color_to_int(bright(&scene->ambient->color, scene->ambient->light_ratio));
	return (background);
}
