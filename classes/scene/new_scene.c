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

void		del_scene(t_scene *self);

static void	start_mlx(t_scene *self)
{
	if (!(self->mlx = mlx_init()))
		ft_exit(WINDOW_ERROR);
	if (!(self->window = mlx_new_window(self->mlx, self->resolution->x_size,
			self->resolution->y_size, MAINTAINER)))
		ft_exit(WINDOW_ERROR);
}

t_scene		*new_scene(t_resolution *resolution, t_ambient *ambient, t_list *all_obj)
{
	t_scene			*scene;
	t_any_object	*any;

	if (!(scene = (t_scene *)malloc_gc(sizeof(t_scene))))
		ft_exit(ENOMEM);
	scene->resolution = resolution;
	scene->ambient = ambient;
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	while (all_obj)
	{
		any = all_obj->content;
		if (any->identifier[0] == 'c' && any->identifier[1] == '\0')
			ft_lstadd_front(&scene->cameras, ft_lstnew(all_obj->content));
		else if (any->identifier[0] == 'l' && any->identifier[1] == '\0')
			ft_lstadd_front(&scene->lights, ft_lstnew(all_obj->content));
		else
			ft_lstadd_front(&scene->objects, ft_lstnew(all_obj->content));
		all_obj = all_obj->next;
	}
	start_mlx(scene);
	scene->del = &del_scene;
	return (scene);
}
