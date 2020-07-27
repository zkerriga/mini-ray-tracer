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

static void	computing(t_triangle *self)
{
	float	ab_ab_coef;
	float	ab_ac_coef;
	float	ac_ac_coef;
	float	d;
	t_vec3	tmp[2];

	ab_ab_coef = vdot(&self->ab_edge, &self->ab_edge);
	ab_ac_coef = vdot(&self->ab_edge, &self->ac_edge);
	ac_ac_coef = vdot(&self->ac_edge, &self->ac_edge);
	d = ab_ab_coef * ac_ac_coef - ab_ac_coef * ab_ac_coef;
	vsubtract(&self->u_beta, vmulti(&tmp[0], &self->ab_edge, ac_ac_coef / d),
				vmulti(&tmp[1], &self->ac_edge, ab_ac_coef / d));
	vsubtract(&self->u_gama, vmulti(&tmp[0], &self->ac_edge, ab_ab_coef / d),
				vmulti(&tmp[1], &self->ab_edge, ab_ac_coef / d));
}

static void	set_another(t_triangle *triangle, char *line)
{
	line = ft_next(line);
	triangle->c_point.x = ft_atof(line);
	line = ft_next(line);
	triangle->c_point.y = ft_atof(line);
	line = ft_next(line);
	triangle->c_point.z = ft_atof(line);
	line = ft_next(line);
	triangle->color.r = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	triangle->color.g = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	triangle->color.b = (float)ft_atoi(line) / 255.f;
	vset(&triangle->norm, 0.f, 0.f, 0.f); //TODO: delete string
	triangle->del = &del_triangle;
	triangle->solve = &tr_solve;
	triangle->get_n = &tr_get_n;
	triangle->prepare = &tr_prepare;
	vget(&triangle->ab_edge, &triangle->b_point, &triangle->a_point);
	vget(&triangle->ac_edge, &triangle->c_point, &triangle->a_point);
	vprod(&triangle->norm, &triangle->ab_edge, &triangle->ac_edge);
	normalize(&triangle->norm);
	computing(triangle);
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
