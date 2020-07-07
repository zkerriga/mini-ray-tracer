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
#define FUNC_H

#include "minirt.h"

int			color_to_int(t_rgbvec color);
//t_color		bright(t_color *color, float brightness);
void		color_sum(t_color *dest, t_color one, t_color two, float bright);
void		color_copy(t_color *dest, t_color src);
float		vdot(t_3dvector *a, t_3dvector *b);
float		module(t_3dvector vector);

#endif
