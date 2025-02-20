/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:32:08 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 19:53:13 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	check_char(t_data *box)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (box->map[i])
	{
		j = 0;
		while (box->map[i][j])
		{
			if (box->map[i][j] != '1' && box->map[i][j] != 'M'
				&& box->map[i][j] != '0' && box->map[i][j] != 'C'
				&& box->map[i][j] != 'E' && box->map[i][j] != 'P')
			{
				ft_putstr_fd("Error: Invalid character in the map\n", 2);
				return (clear_data(box, 1), ft_exit(1));
			}
			j++;
		}
		i++;
	}
}

void	count_char(t_data *box)
{
	int	i;
	int	j;

	init_zero(box, &i, &j);
	while (box->map[i])
	{
		j = 0;
		while (box->map[i][j])
		{
			if (box->map[i][j] == 'C')
				box->number_of_collect++;
			if (box->map[i][j] == 'E')
				box->number_of_exit++;
			if (box->map[i][j] == 'P')
				box->number_of_player++;
			if (box->map[i][j] == 'M')
				box->number_of_enemy++;
			j++;
		}
		i++;
	}
	if (box->number_of_exit != 1 || box->number_of_player != 1
		|| box->number_of_collect == 0 || box->number_of_enemy > 1)
		return (clear_data(box, 1));
}

void	init_zero(t_data *box, int *i, int *j)
{
	*i = 0;
	*j = 0;
	box->number_of_collect = 0;
	box->number_of_exit = 0;
	box->number_of_player = 0;
	box->number_of_enemy = 0;
	box->moves = 0;
	box->collect = 0;
}
