/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:30:46 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 16:30:48 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "func.h"

t_3dvector		*cy_get_n(t_cylinder *self, t_point *point, t_point *camera)
{
	t_3dvector	*norm;

	if (!(norm = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	set_vector(norm, point, &self->point);
	if (2 * modulep(camera, &self->point) < self->diameter)
		reverse_vec(norm);
	return (normalize(norm));

}
