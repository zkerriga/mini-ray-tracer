/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 23:23:50 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 23:24:02 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	ft_exit(int error_code)
{
	if (error_code == ENOMEM)
		ft_exit_memerror(error_code);
	else if (error_code == INVALID_INPUT)
		ft_exit_invalid_input();
	else if (error_code == INVALID_DESCRIPTOR)
		ft_exit_invalid_descriptor();
	else if (error_code == WINDOW_ERROR)
		ft_exit_window_error();
}
