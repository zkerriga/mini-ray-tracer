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
# define K_ESCAPE 0xff1b
# define K_RIGHT 0xff53
# define K_LEFT 0xff51

# define RIGHT 2
# define LEFT 1
# define NONE 0

# define ENOMEM 12
# define INVALID_INPUT -1
# define INVALID_DESCRIPTOR -2
# define WINDOW_ERROR -3

# define FALSE 0
# define TRUE 1

# define AIR_BONUS 1
# define DEBUG 0

# include "scene.h"
# include "errno.h"
# include "stdio.h"
# include "mlx.h"

typedef struct	s_args
{
	t_bool		help;
	t_bool		save;
	const char	*path;
}				t_args;

void	ft_exit(int error_code);
void	ft_exit_memerror(int error_code);
void	ft_exit_invalid_input(void);
void	ft_exit_invalid_descriptor(void);
void	ft_exit_window_error(void);
void	show_help(void);

#endif
