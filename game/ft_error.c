/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:56:32 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/21 22:32:22 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	ft_exit(int flag)
{
	if (flag == 0)
		ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	put_error(char *str)
{
	if (str[0] != 'E')
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	close(2);
}

int	exit_clear(void *box)
{
	clear_data((t_data *)box, 3);
	return (1);
}
