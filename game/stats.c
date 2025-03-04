/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:07:16 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/27 14:49:54 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	update_game_state(t_data *box, int new_x, int new_y)
{
	if (box->map[new_y][new_x] == 'C')
	{
		box->collect++;
	}
	if (box->map[new_y][new_x] == 'E' && box->collect == box->number_of_collect)
	{
		ft_putstr_fd("You win !\n", 1);
		close(2);
		clear_data(box, 3);
	}
	box->map[box->index_player[0]][box->index_player[1]] = '0';
	box->index_player[0] = new_y;
	box->index_player[1] = new_x;
	box->map[new_y][new_x] = 'P';
}

void	display_stats(t_data *box)
{
	char		*moves_str;
	char		*collect_str;
	static int	moves_cmp;

	moves_str = ft_itoa(box->moves);
	collect_str = ft_itoa(box->collect);
	mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 20, 20, 0x000000,
		"Moves: ");
	mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 80, 20, 0xfa7302,
		moves_str);
	mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 20, 40, 0x000000,
		"Collect: ");
	mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 80, 40, 0xfa7302,
		collect_str);
	if (moves_cmp != box->moves)
		moves_cmp = box->moves;
	free(moves_str);
	free(collect_str);
}
