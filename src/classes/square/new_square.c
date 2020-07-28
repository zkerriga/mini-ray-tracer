/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:36:34 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:36:41 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "square.h"

static void	calculate(t_square *self)
{
	if (self->norm.x != 0.f)
		vset(&self->right, -(self->norm.y) / self->norm.x, 1.f, 0.f);
	else if (self->norm.y != 0.f)
		vset(&self->right, 1.f, -(self->norm.x) / self->norm.y, 0.f);
	else
		vset(&self->right, 0.f, 1.f, -(self->norm.y) / self->norm.z);
	normalize(&self->right);
	vprod(&self->up, &self->right, &self->norm);
}

static void	set_another(t_square *square, char *line)
{
	line = ft_next(line);
	square->side_size = ft_atof(line);
	line = ft_next(line);
	square->color.r = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	square->color.g = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	square->color.b = (float)ft_atoi(line) / 255.f;
	square->del = &del_square;
	square->get_n = &sq_get_n;
	square->solve = &sq_solve;
	square->prepare = &sq_prepare;
	normalize(&square->norm);
	calculate(square);
}

t_square	*new_square(char *line)
{
	t_square	*square;

	if (!square_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(square = (t_square *)malloc_gc(sizeof(t_square))))
		ft_exit(ENOMEM);
	square->identifier[0] = 's';
	square->identifier[1] = 'q';
	line = ft_next(line);
	square->center.x = ft_atof(line);
	line = ft_next(line);
	square->center.y = ft_atof(line);
	line = ft_next(line);
	square->center.z = ft_atof(line);
	line = ft_next(line);
	square->norm.x = ft_atof(line);
	line = ft_next(line);
	square->norm.y = ft_atof(line);
	line = ft_next(line);
	square->norm.z = ft_atof(line);
	set_another(square, line);
	return (square);
}
