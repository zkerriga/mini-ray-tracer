/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vprod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:40:04 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/11 17:40:05 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function implements vector multiplication.
** The resulting vector is written to dest. The function gets and returns
** a pointer to the vector where the multiplication result will be.
** (!) `dest` must not be equal to `a` or `b`
*/

t_3dvector	*vprod(t_3dvector *dest, t_3dvector *a, t_3dvector *b)
{
	dest->x = a->y * b->z - a->z * b->y;
	dest->y = a->z * b->x - a->x * b->z;
	dest->z = a->x * b->y - a->y * b->x;
	return (dest);
}
