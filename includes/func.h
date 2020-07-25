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
float		vdot(t_vec3 *vec1, t_vec3 *vec2);
float		module(t_vec3 *vector);
float		modulep(t_point *a, t_point *b);
t_bool		fbetween(float nbr, float down, float up);
void		set_vector(t_vec3 *dest, t_point *to, t_point *from);
float		maxf(float one, float two);
t_limits	*ray_lim(t_limits *dest, float min, float max);
t_vec3	*vprod(t_vec3 *dest, t_vec3 *a, t_vec3 *b);
void		set_point(t_vec3 *dest, float x, float y, float z);
t_vec3	*normalize(t_vec3 *vector);
t_vec3	*reverse_vec(t_vec3 *vector);
float		rad_to_deg(float radians);
t_vec3	*vmulti(t_vec3 *dest, t_vec3 *vec, float multiplier);
t_vec3	*vaddition(t_vec3 *dest, t_vec3 *vec1, t_vec3 *vec2);
t_vec3	*vsubtract(t_vec3 *dest, t_vec3 *vec1, t_vec3 *vec2);
void		set_lookat(t_matrix *lookat, t_vec3 *norm);
t_vec3	*vreverse(t_vec3 *dest, t_vec3 *vector);

#endif
