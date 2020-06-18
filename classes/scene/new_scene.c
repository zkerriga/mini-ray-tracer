/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:01:59 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 19:03:03 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"
#include "minirt.h"

t_scene		*new_scene(int x, int y)
{
	t_scene	*scene;

	if ((scene = (t_scene *)malloc_gc(sizeof(t_scene))))
		exit(ENOMEM);
	scene->x_size = x;
	scene->y_size = y;
	scene->del = &del_scene;
	return (scene);
}
