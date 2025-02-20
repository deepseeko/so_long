/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_coin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:18:34 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 18:58:58 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	update_coin_frame(a_data *box)
{
	static int	frame;
	int			x;
	int			y;

	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == 'C')
				mlx_put_image_to_window(box->mlx_data->mlx, box->mlx_data->win,
					box->coin_frames[frame], x * 64, y * 64);
			x++;
		}
		y++;
	}
	frame = (frame + 1) % 9;
}
