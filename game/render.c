/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:11:32 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/27 18:47:50 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_map(void *mlx, void *win, char **map, t_data *box)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, box->wall, x * 64, y * 64);
			if (map[y][x] == '0')
				mlx_put_image_to_window(mlx, win, box->bg, x * 64, y * 64);
			if (map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, box->player, x * 64, y * 64);
			if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, box->exit, x * 64, y * 64);
			if (map[y][x] == 'M')
				mlx_put_image_to_window(mlx, win, box->enemy, x * 64, y * 64);
			x++;
		}
		y++;
	}
	display_stats(box);
}
