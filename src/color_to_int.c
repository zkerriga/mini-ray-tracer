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

int		color_to_int(t_color *color)
{
	int	rgb;

	rgb = color->r;
	rgb = rgb << 8;
	rgb += color->g;
	rgb = rgb << 8;
	rgb += color->b;
	return (rgb);
}
