/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsubtract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:44:56 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/20 12:44:58 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Subtracts the second vector from the first vector.
** Returns the original pointer to dest.
*/

t_3dvector	*vsubtract(t_3dvector *dest, t_3dvector *vec1, t_3dvector *vec2)
{
	dest->x = vec1->x - vec2->x;
	dest->y = vec1->y - vec2->y;
	dest->z = vec1->z - vec2->z;
	return (dest);
}
