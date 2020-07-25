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

t_vec3	*vaddition(t_vec3 *dest, t_vec3 *vec1, t_vec3 *vec2)
{
	dest->x = vec1->x + vec2->x;
	dest->y = vec1->y + vec2->y;
	dest->z = vec1->z + vec2->z;
	return (dest);
}
