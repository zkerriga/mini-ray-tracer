/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_prepare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:36:43 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/27 21:36:45 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	scene_prepare(t_scene *self)
{
	t_list			*objects;
	t_any_object	*any;

	objects = self->objects;
	while (objects)
	{
		any = objects->content;
		any->prepare(any, self);
		objects = objects->next;
	}
}
