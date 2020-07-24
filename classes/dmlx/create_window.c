/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:59:48 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/24 09:59:50 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dmlx.h"
#include "minirt.h"

void	create_window(t_dmlx *self, int x_size, int y_size)
{
	if (!(self->win = mlx_new_window(self->mlx, x_size, y_size, MAINTAINER)))
		ft_exit(WINDOW_ERROR);
}
