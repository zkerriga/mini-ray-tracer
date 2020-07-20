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
#include "func.h"

static void	set_another(t_triangle *triangle, char *line)
{
	t_3dvector	ab;
	t_3dvector	ac;

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
	set_point(&triangle->norm, 0.f, 0.f, 0.f);
	triangle->del = &del_triangle;
	triangle->solve = &tr_solve;
	triangle->get_n = &tr_get_n;
	set_vector(&ab, &triangle->second, &triangle->first);
	set_vector(&ac, &triangle->third, &triangle->first);
	vprod(&triangle->norm, &ab, &ac);
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
