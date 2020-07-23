/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:47:35 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/29 17:47:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# include "minirt.h"

int			color_to_int(t_rgbvec color);
t_rgbvec	*color_sum(t_rgbvec *dest, t_rgbvec one, t_rgbvec two);
t_rgbvec	*color_multi(t_rgbvec *dest, t_rgbvec one, t_rgbvec two);
float		vdot(t_3dvector *vec1, t_3dvector *vec2);
float		module(t_3dvector *vector);
float		modulep(t_point *a, t_point *b);
t_bool		fbetween(float nbr, float down, float up);
void		set_vector(t_3dvector *dest, t_point *to, t_point *from);
float		maxf(float one, float two);
t_limits	*ray_lim(float min, float max);
t_3dvector	*vprod(t_3dvector *dest, t_3dvector *a, t_3dvector *b);
void		set_point(t_3dvector *dest, float x, float y, float z);
t_3dvector	*normalize(t_3dvector *vector);
t_3dvector	*reverse_vec(t_3dvector *vector);
float		rad_to_deg(float radians);
t_3dvector	*vmulti(t_3dvector *dest, t_3dvector *vec, float multiplier);
t_3dvector	*vaddition(t_3dvector *dest, t_3dvector *vec1, t_3dvector *vec2);
t_3dvector	*vsubtract(t_3dvector *dest, t_3dvector *vec1, t_3dvector *vec2);
void		set_lookat(t_matrix *lookat, t_3dvector *norm);

#endif
