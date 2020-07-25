/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dmlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:10:20 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/24 09:10:23 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dmlx.h"

void	del_dmlx(t_dmlx *self)
{
	mlx_destroy_image(self->mlx, self->img);
	if (self->win)
		mlx_destroy_window(self->mlx, self->win);
}
