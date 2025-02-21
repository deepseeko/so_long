/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:21:43 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 23:06:58 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	copy_map(t_data *box)
{
	int	i;

	i = 0;
	box->copy_map = malloc(sizeof(char *) * (box->size_map[0] + 1));
	if (!box->copy_map)
		return (put_error("malloc !"), clear_data(box, 2), ft_exit(0));
	while (i < box->size_map[0] + 1)
	{
		box->copy_map[i] = ft_strdup(box->map[i]);
		i++;
	}
}

void	check_flood_fill(t_data *box)
{
	copy_map(box);
	get_index_player(box);
	if (box->number_of_enemy != 0)
		get_index_enemy(box);
	flood_fill_helper(box, box->index_player[0],
		box->index_player[1]);
	check_if_flooded(box);
}

void	flood_fill_helper(t_data *box, int x, int y)
{
	if (x < 0 || x >= box->size_map[0] || y < 0
		|| y >= box->size_map[1] || box->copy_map[x][y] == 'F')
		return ;
	if (box->copy_map[x][y] == '1')
		return ;
	if (box->copy_map[x][y] == 'E')
	{
		box->copy_map[x][y] = 'F';
		return ;
	}
	box->copy_map[x][y] = 'F';
	flood_fill_helper(box, x + 1, y);
	flood_fill_helper(box, x - 1, y);
	flood_fill_helper(box, x, y + 1);
	flood_fill_helper(box, x, y - 1);
}

void	check_if_flooded(t_data *box)
{
	int	x;
	int	i;
	int	j;

	if (!box->copy_map)
		return (ft_exit(1));
	x = box->size_map[0];
	i = 0;
	while (i < x)
	{
		j = 0;
		while (box->copy_map[i][j])
		{
			if (box->copy_map[i][j] == 'E' || box->copy_map[i][j] == 'C')
				return (put_error("map not valid[flood]\n")
					, clear_data(box, 2), ft_exit(1));
			j++;
		}
		i++;
	}
}
