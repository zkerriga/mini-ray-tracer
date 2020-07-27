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

static void	set_another(t_plane *plane, char *line)
{
	line = ft_next(line);
	plane->color.r = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	plane->color.g = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	plane->color.b = (float)ft_atoi(line) / 255.f;
	plane->del = &del_plane;
	plane->solve = &pl_solve;
	plane->get_n = &pl_get_n;
	plane->prepare = &pl_prepare;
	normalize(&plane->norm);
}

t_plane		*new_plane(char *line)
{
	t_plane	*plane;

	if (!plane_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(plane = (t_plane *)malloc_gc(sizeof(t_plane))))
		ft_exit(ENOMEM);
	plane->identifier[0] = 'p';
	plane->identifier[1] = 'l';
	line = ft_next(line);
	plane->point.x = ft_atof(line);
	line = ft_next(line);
	plane->point.y = ft_atof(line);
	line = ft_next(line);
	plane->point.z = ft_atof(line);
	line = ft_next(line);
	plane->norm.x = ft_atof(line);
	line = ft_next(line);
	plane->norm.y = ft_atof(line);
	line = ft_next(line);
	plane->norm.z = ft_atof(line);
	set_another(plane, line);
	return (plane);
}
