/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:29:14 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 19:53:50 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int ac, char **av)
{
	t_data	*box;

	if (ac != 2)
		ft_exit(0);
	box = init_data(av);
	init_win(box);
	(void)box;
	return (0);
}
