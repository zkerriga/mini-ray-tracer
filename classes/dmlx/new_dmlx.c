/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dmlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:10:04 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/24 09:10:06 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "dmlx.h"

t_dmlx	*new_dmlx(int *x_size, int *y_size)
{
	t_dmlx	*dmlx;
	int		tmp_size_x;
	int		tmp_size_y;

	if (!(dmlx = (t_dmlx *)malloc_gc(sizeof(t_dmlx))))
		ft_exit(ENOMEM);
	if (!(dmlx->mlx = mlx_init()))
		ft_exit(WINDOW_ERROR);
	mlx_get_screen_size(dmlx->mlx, &tmp_size_x, &tmp_size_y);
	if (tmp_size_x < *x_size)
		*x_size = tmp_size_x;
	if (tmp_size_y < *y_size)
		*y_size = tmp_size_y;
	if (!(dmlx->img = mlx_new_image(dmlx->mlx, *x_size, *y_size)))
		ft_exit(WINDOW_ERROR);
	dmlx->win = NULL;
	dmlx->addr = (int *)mlx_get_data_addr(dmlx->img, &dmlx->bits_per_pixel, &dmlx->line_length, &dmlx->endian);
	dmlx->del = &del_dmlx;
	dmlx->set_win = &create_window;
	dmlx->put_bmp = &put_image_to_bmp;
	dmlx->put_win = &put_image_to_win;
	return (dmlx);
}
