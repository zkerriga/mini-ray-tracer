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
	triangle->c_point.x = ft_atof(line);
	line = ft_next(line);
	triangle->c_point.y = ft_atof(line);
	line = ft_next(line);
	triangle->c_point.z = ft_atof(line);
	line = ft_next(line);
	triangle->color.r = (float)ft_atoi(line) / 255;
	line = ft_next(line);
	triangle->color.g = (float)ft_atoi(line) / 255;
	line = ft_next(line);
	triangle->color.b = (float)ft_atoi(line) / 255;
	vset(&triangle->norm, 0.f, 0.f, 0.f);
	triangle->del = &del_triangle;
	triangle->solve = &tr_solve;
	triangle->get_n = &tr_get_n;
	vget(&triangle->ab_edge, &triangle->b_point, &triangle->a_point);
	vget(&triangle->ac_edge, &triangle->c_point, &triangle->a_point);
	vprod(&triangle->norm, &triangle->ab_edge, &triangle->ac_edge);
	normalize(&triangle->norm);
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
	triangle->a_point.x = ft_atof(line);
	line = ft_next(line);
	triangle->a_point.y = ft_atof(line);
	line = ft_next(line);
	triangle->a_point.z = ft_atof(line);
	line = ft_next(line);
	triangle->b_point.x = ft_atof(line);
	line = ft_next(line);
	triangle->b_point.y = ft_atof(line);
	line = ft_next(line);
	triangle->b_point.z = ft_atof(line);
	set_another(triangle, line);
	return (triangle);
}
