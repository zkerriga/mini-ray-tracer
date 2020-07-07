/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:21:11 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/29 17:21:30 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** This function converts a structure containing colors to a single integer,
** which is used by the minilibx library to determine the color.
*/

int		color_to_int(t_rgbvec color)
{
	return (((char)(color.r * 255) << 16) + ((char)(color.g * 255) << 8) + (char)(color.b * 255));
}

/*int		color_to_int(t_color color)
{
	return ((color.r << 16) + (color.g << 8) + color.b);
}*/
