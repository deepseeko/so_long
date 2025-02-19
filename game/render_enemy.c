/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:37:38 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/19 20:38:38 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"


void render_enemy(void *mlx, void *win, a_data *box)
{
	int x, y;

	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, box->enemy, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void update_enemy_position(a_data *box)
{
	int new_x = box->index_enemy[1];
	int new_y = box->index_enemy[0];
	int random = rand() % 4;

	if (random == 0)
		new_x++;
	if (random == 1)
		new_x--;
	if (random == 2)
		new_y++;
	if (random == 3)
		new_y--;
	if (box->map[new_y][new_x] != '1')
	{
		box->map[box->index_enemy[0]][box->index_enemy[1]] = '0';
		box->index_enemy[0] = new_y;
		box->index_enemy[1] = new_x;
		box->map[new_y][new_x] = 'E';
	}
}
