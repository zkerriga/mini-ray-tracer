/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:29:59 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:30:06 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "plane.h"

void	del_plane(t_plane *self);

t_plane	*new_plane(char *line)
{
	t_plane	*plane;

	if (!(plane = (t_plane *)malloc_gc(sizeof(t_plane))))
		ft_exit(ENOMEM);
	plane->identifier[0] = 'p';
	plane->identifier[1] = 'l';
	plane->point.x = ft_atof((line = ft_next(line)));
	plane->point.y = ft_atof((line = ft_next(line)));
	plane->point.z = ft_atof((line = ft_next(line)));
	plane->vector.x = ft_atof((line = ft_next(line)));
	plane->vector.y = ft_atof((line = ft_next(line)));
	plane->vector.z = ft_atof((line = ft_next(line)));
	plane->color.r = ft_atoi((line = ft_next(line)));
	plane->color.g = ft_atoi((line = ft_next(line)));
	plane->color.b = ft_atoi((line = ft_next(line)));
	plane->del = &del_plane;
	return (plane);
}
