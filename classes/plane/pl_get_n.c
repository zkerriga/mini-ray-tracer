/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:11:57 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:33:26 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "plane.h"
#include "func.h"

t_3dvector	*pl_get_n(t_plane *self, t_point *point)
{
	t_3dvector	*norm;

	if (!(norm = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	norm->x = self->vector.x;
	norm->y = self->vector.y;
	norm->z = self->vector.z;
	return (normalize(norm));
}
