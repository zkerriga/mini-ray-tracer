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

static void	mlx_setup(t_scene *self)
{
	self->dmlx = new_dmlx(&self->resolution->x_size, &self->resolution->y_size);
}

static void	zeroes(t_scene *self)
{
	self->lights = NULL;
	self->objects = NULL;
	self->act_cam = NULL;
}

t_scene		*new_scene(t_resolution *resolution, t_ambient *ambient,
						t_dlist *cameras, t_list *all_obj)
{
	t_scene			*scene;
	t_any_object	*any;
	void			*tmp;

	if (!(scene = (t_scene *)malloc_gc(sizeof(t_scene))))
		ft_exit(ENOMEM);
	scene->resolution = resolution;
	scene->ambient = ambient;
	scene->cameras = cameras;
	zeroes(scene);
	while (all_obj)
	{
		tmp = all_obj->next;
		any = all_obj->content;
		if (any->identifier[0] == 'l' && any->identifier[1] == '\0')
			ft_lstadd_front(&scene->lights, all_obj);
		else
			ft_lstadd_front(&scene->objects, all_obj);
		all_obj = tmp;
	}
	mlx_setup(scene);
	scene->get_d = &get_d;
	scene->del = &del_scene;
	scene->get_cam = &get_active_camera;
	return (scene);
}
