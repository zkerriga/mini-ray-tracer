/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:19:30 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 19:19:52 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define MAINTAINER "zkerriga"
# define ESCAPE 0xff1b
# define ENOMEM 12
# define INVALID_INPUT -1
# define INVALID_DESCRIPTOR -2
# define WINDOW_ERROR -3
# define FALSE 0
# define TRUE 1

# include "scene.h"
# include "errno.h"
# include "stdio.h"
# include "mlx.h"

void	ft_exit(int error_code);
void	ft_exit_memerror(int error_code);
void	ft_exit_invalid_input();
void	ft_exit_invalid_descriptor();
void	ft_exit_window_error();

#endif
