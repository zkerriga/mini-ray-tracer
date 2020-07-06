/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 00:48:16 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/07 00:48:19 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Just copies the color structure to dest.
*/

void	color_copy(t_color *dest, t_color src)
{
	dest->r = src.r;
	dest->g = src.g;
	dest->b = src.b;
}
