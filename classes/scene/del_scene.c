/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:02:10 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 19:02:58 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

static	del_objects(t_list *objects)
{
	t_list			*tmp;
	t_any_object	*any;

	while (objects)
	{
		any = objects->content;
		any->del(objects->content);
		tmp = objects;
		objects = objects->next;
		free(tmp);
	}
}

void	del_scene(t_scene *self)
{
	t_list			*tmp;
	t_any_object	*any;

	self->resolution->del(self->resolution);
	self->ambient->del(self->ambient);
	while (self->cameras)
	{
		((t_camera *)self->cameras->content)->del(self->cameras->content);
		tmp = self->cameras;
		self->cameras = self->cameras->next;
		free(tmp);
	}
	while (self->lights)
	{
		((t_light *)self->lights->content)->del(self->lights->content);
		tmp = self->lights;
		self->lights = self->lights->next;
		free(tmp);
	}
	del_objects(self->objects);
	free_gc(self);
}
