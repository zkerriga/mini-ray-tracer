/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:08:32 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/29 11:08:40 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdio.h>
# include <errno.h>

# define INVALID_INPUT (-1)
# define INVALID_DESCRIPTOR (-2)
# define WINDOW_ERROR (-3)

void			ft_exit(int error_code);
void			ft_exit_memerror(int error_code);
void			ft_exit_invalid_input(void);
void			ft_exit_invalid_descriptor(void);
void			ft_exit_window_error(void);

#endif
