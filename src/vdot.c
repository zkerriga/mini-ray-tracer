/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:26:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/03 17:26:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Scalar multiplication of two vectors
*/

float	vdot(t_3dvector a, t_3dvector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
