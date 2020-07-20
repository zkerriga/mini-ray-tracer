/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaddition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:46:17 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/20 12:46:19 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Adds two vectors.
** Returns the original pointer to dest.
*/

t_3dvector	*vaddition(t_3dvector *dest, t_3dvector *vec1, t_3dvector *vec2)
{
	dest->x = vec1->x + vec2->x;
	dest->y = vec1->y + vec2->y;
	dest->z = vec1->z + vec2->z;
	return (dest);
}
