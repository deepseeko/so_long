/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_enemy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:20:12 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/27 18:49:22 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void check_space(t_data *box, int x, int y)
{
	if (box->map[y][x] == '0')
	{
		box->map[y][x] = 'M';
		box->index_enemy[0] = y;
		box->index_enemy[1] = x;
		box->number_of_enemy = 1;
	}
}

void get_random_position(t_data *box)
{
	int	x;
	int	y;
	static int get;

	if (get)
		return ;
	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == '0')
			{
				check_space(box, x, y);
				get = 1;
				return ;
			}
			x++;
		}
		y++;
	}
	get = 1;
	write(1, "No space for enemy\n", 20);
}

