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

# define ENOMEM 12 /* Out of memory */ //TODO: delete the comment
# define INVALID_INPUT -1
# define INVALID_DESCRIPTOR -2

# include "scene.h"
# include "parser.h"
# include "errno.h"
# include "stdio.h"

void	ft_exit(int error_code);
void	ft_exit_memerror(int error_code);
void	ft_exit_invalid_input();
void	ft_exit_invalid_descriptor();

#endif
