/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:27:38 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/27 18:47:08 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_path(char *str, t_data *box, char **splited_path)
{
	box->path = str;
	free_2darr(splited_path);
}

void	init_null(t_data *box)
{
	box->mlx_data = NULL;
}

t_data	*init_data(char **av)
{
	t_data	*box;

	box = malloc(sizeof(t_data));
	if (!box)
		ft_exit(0);
	init_null(box);
	check_path(av[1], box);
	check_map(box);
	get_random_position(box);
	return (box);
}
