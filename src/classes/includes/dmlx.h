/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:09:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/24 09:09:27 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DMLX_H
# define DMLX_H

# include "mlx.h"

typedef struct	s_dmlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		(*put_win)(struct s_dmlx *);
	void		(*put_bmp)(struct s_dmlx *, int, int);
	void		(*set_win)(struct s_dmlx *, int, int);
	void		(*del)(struct s_dmlx *);
}				t_dmlx;

t_dmlx			*new_dmlx(int *x_size, int *y_size);
void			del_dmlx(t_dmlx *self);
void			create_window(t_dmlx *self, int x_size, int y_size);
void			put_image_to_win(t_dmlx *self);
void			put_image_to_bmp(t_dmlx *self, int x_size, int y_size);

#endif
