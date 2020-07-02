/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 21:18:45 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/02 21:19:18 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function takes a pointer to the color structure and brightness.
** Each part of the light in the structure is multiplied by the brightness level.
*/

t_color		bright(t_color *color, float brightness)
{
	color->r *= brightness;
	color->g *= brightness;
	color->b *= brightness;
	return (*color);
}
