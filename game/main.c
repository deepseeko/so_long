/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:29:14 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/28 14:17:28 by ybouanan         ###   ########.fr       */
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
	return (0);
}
