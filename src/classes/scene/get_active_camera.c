/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_active_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:06:52 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/14 10:06:54 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "scene.h"

static t_dlist	*dlast(t_dlist *cameras)
{
	while (cameras->next)
		cameras = cameras->next;
	return (cameras);
}

t_camera		*get_active_camera(t_scene *self, t_bool mode)
{
	static t_dlist	*active = NULL;

	if (!self->cameras)
		return (NULL);
	if (active)
	{
		if (mode == RIGHT)
			active = (active->next) ? active->next : self->cameras;
		else if (mode == LEFT)
			active = (active->prev) ? active->prev : dlast(self->cameras);
	}
	else
		active = self->cameras;
	return (active->content);
}
