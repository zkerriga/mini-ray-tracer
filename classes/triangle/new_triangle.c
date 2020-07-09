/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:44:40 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:44:47 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "triangle.h"

static void	set_another(t_triangle *triangle, char *line)
{
	line = ft_next(line);
	triangle->third.x = ft_atof(line);
	line = ft_next(line);
	triangle->third.y = ft_atof(line);
	line = ft_next(line);
	triangle->third.z = ft_atof(line);
	line = ft_next(line);
	triangle->color.r = (float)ft_atoi(line) / 255;
	line = ft_next(line);
	triangle->color.g = (float)ft_atoi(line) / 255;
	line = ft_next(line);
	triangle->color.b = (float)ft_atoi(line) / 255;
	triangle->del = &del_triangle;
}

t_triangle	*new_triangle(char *line)
{
	t_triangle	*triangle;

	if (!triangle_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(triangle = (t_triangle *)malloc_gc(sizeof(t_triangle))))
		ft_exit(ENOMEM);
	triangle->identifier[0] = 't';
	triangle->identifier[1] = 'r';
	line = ft_next(line);
	triangle->first.x = ft_atof(line);
	line = ft_next(line);
	triangle->first.y = ft_atof(line);
	line = ft_next(line);
	triangle->first.z = ft_atof(line);
	line = ft_next(line);
	triangle->second.x = ft_atof(line);
	line = ft_next(line);
	triangle->second.y = ft_atof(line);
	line = ft_next(line);
	triangle->second.z = ft_atof(line);
	set_another(triangle, line);
	return (triangle);
}
