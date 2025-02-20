/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:27:38 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 20:00:14 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_path(char *str, t_data *box, char **splited_path)
{
	box->path = str;
	free_2darr(splited_path);
}

t_data	*init_data(char **av)
{
	t_data	*box;

	box = malloc(sizeof(t_data));
	if (!box)
		ft_exit(0);
	check_path(av[1], box);
	check_map(box);
	return (box);
}
