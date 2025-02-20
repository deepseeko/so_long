/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:12:59 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 22:25:38 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	handle_keypress(int keycode, t_data *box)
{
	int	new_x;
	int	new_y;

	new_x = box->index_player[1];
	new_y = box->index_player[0];
	if (keycode == 65307)
		clear_data(box, 3);
	if (keycode != KEY_W && keycode != KEY_S && keycode != KEY_A
		&& keycode != KEY_D)
		return (0);
	update_position(keycode, &new_x, &new_y);
	if (box->map[new_y][new_x] != '1')
	{
		if (box->map[new_y][new_x] == 'E'
			&& box->collect != box->number_of_collect)
			return (0);
		box->moves++;
		if (box->map[new_y][new_x] == 'M')
			return (ft_putstr_fd("LOSER !!! ya lka3ka3\n", 1), close(2),
				clear_data(box, 3), 0);
		update_game_state(box, new_x, new_y);
		render_map(box->mlx_data->mlx, box->mlx_data->win, box->map, box);
	}
	return (0);
}

void	update_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == KEY_W)
	{
		(*new_y)--;
	}
	else if (keycode == KEY_S)
	{
		(*new_y)++;
	}
	else if (keycode == KEY_A)
	{
		(*new_x)--;
	}
	else if (keycode == KEY_D)
	{
		(*new_x)++;
	}
}
