/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_to_bmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 10:07:34 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/24 10:07:36 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dmlx.h"
#include <fcntl.h>
#include <unistd.h>

#define BM_INFO_SIZE 40
#define BM_HEAD_SIZE 14
#define RESERVED 0
#define OFFSET 54
#define PLANES 1
#define COMPRESSION 0
#define PIXEL_PER_METER 1000
#define COLOR_TABLE 0

static void	write_n(int fd, int nbr, int size)
{
	short	tmp;

	if (size == sizeof(short))
	{
		tmp = (short)nbr;
		write(fd, &tmp, size);
	}
	else
		write(fd, &nbr, size);
}

void		put_image_to_bmp(t_dmlx *self, int x_size, int y_size)
{
	int		fd;

	fd = open("zkerriga.bmp", O_CREAT | O_RDWR);
	write(fd, "BM", 2);
	write_n(fd, BM_HEAD_SIZE + BM_INFO_SIZE +
				sizeof(int) * x_size * y_size, sizeof(int));
	write_n(fd, RESERVED, sizeof(int));
	write_n(fd, OFFSET, sizeof(int));
	write_n(fd, BM_INFO_SIZE, sizeof(int));
	write(fd, &x_size, sizeof(int));
	write_n(fd, -y_size, sizeof(int));
	write_n(fd, PLANES, sizeof(short));
	write_n(fd, (short)self->bits_per_pixel, sizeof(short));
	write_n(fd, COMPRESSION, sizeof(int));
	write_n(fd, x_size * y_size, sizeof(int));
	write_n(fd, PIXEL_PER_METER, sizeof(int));
	write_n(fd, PIXEL_PER_METER, sizeof(int));
	write_n(fd, COLOR_TABLE, sizeof(int));
	write_n(fd, COLOR_TABLE, sizeof(int));
	write(fd, self->addr, x_size * y_size * sizeof(int));
	close(fd);
}
