/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:21:43 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/17 14:23:43 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"


void copy_map(a_data *box)
{
	int i;

	i = 0;
	box->copy_map = malloc(sizeof(char *) * (box->size_map[0] + 1));
	if (!box->copy_map)
		return (clear_data(box, 2), ft_exit(0));
	while (i < box->size_map[0] + 1)
	{
		box->copy_map[i] = ft_strdup(box->map[i]);
		i++;
	}
}

void get_index_player(a_data *box)
{
	int j;
	int i;

	i = 0;
	while(i < box->size_map[0])
	{
		j = 0;
		while(j < box->size_map[1])
		{
			if (box->copy_map[i][j] == 'P')
			{
				box->index_player[0] = i;
				box->index_player[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void check_flood_fill(a_data *box)
{
	int x;
	int y;

	x = box->size_map[0];
	y = box->size_map[1];
	copy_map(box);
	get_index_player(box);
	flood_fill(box->copy_map, x, y, box->index_player[0], box->index_player[1], 'F');
	// int i = 0;
	// while(i <= box->size_map[0])
	// {
	// 	printf("%s\n", box->copy_map[i]);
	// 	i++;
	// }
	check_if_flooded(box);

}

void flood_fill(char **map , int x_m, int y_m, int x, int y , char target)
{
	if(x < 0 || x >= x_m || y < 0 || y >= y_m || map[x][y] == target)
		return ;
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = 'F';
		return ;
	}
	map[x][y] = 'F';
	flood_fill(map, x_m, y_m, x + 1, y, target);
	flood_fill(map, x_m, y_m, x - 1, y, target);
	flood_fill(map, x_m, y_m, x, y + 1, target);
	flood_fill(map, x_m, y_m, x, y - 1, target);
}

void check_if_flooded(a_data *box)
{
	int x;
	int y;
	int i;
	int j;

	x = box->size_map[0];
	y = box->size_map[1];
	i = 0;
	while(i <= x)
	{
		j = 0;
		while(j <= y)
		{
			if (box->copy_map[i][j] == 'E'
				|| box->copy_map[i][j] == 'C')
				return (clear_data(box, 2), ft_exit(1));
			j++;
		}
		i++;
	}
}
