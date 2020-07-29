/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_memerror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 23:26:33 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 23:26:39 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "libft.h"

void	ft_exit_memerror(int error_code)
{
	errno = error_code;
	perror("An error occurred during memory allocation");
	exit(error_code);
}
