/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:32:39 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/08 12:32:41 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

t_bool	is_shadow_point(t_scene *scene, t_point *light_point, t_3dvector *ray)
{
	t_any_object	*any;
	t_list			*objects;
	t_3dvector		reverse_ray;

	reverse_ray.x = ray->x * (-1.0f);
	reverse_ray.y = ray->y * (-1.0f);
	reverse_ray.z = ray->z * (-1.0f);
	objects = scene->objects;
	while (objects)
	{
		any = objects->content;
		if (any->solve(any, light_point, &reverse_ray, 0.0f, NOT_ONE) > 0.0f)
			return (TRUE);
		objects = objects->next;
	}
	return (FALSE);
}
