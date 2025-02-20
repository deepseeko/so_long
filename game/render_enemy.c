/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:37:38 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 16:42:19 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_enemy(void *mlx, void *win, a_data *box)
{
	int	x;
	int	y;

	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == 'M')
				mlx_put_image_to_window(mlx, win, box->enemy, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	generate_random_move(a_data *box, int *new_x, int *new_y)
{
	int	x;

	*new_x = box->index_enemy[1];
	*new_y = box->index_enemy[0];
	x = rand() % 4;
	if (x == 0)
		(*new_x)++;
	else if (x == 1)
		(*new_x)--;
	else if (x == 2)
		(*new_y)++;
	else if (x == 3)
		(*new_y)--;
	if (box->map[*new_y][*new_x] != 'E' && box->map[*new_y][*new_x] != 'C'
		&& box->map[*new_y][*new_x] != '1')
		return (1);
	else
		(generate_random_move(box, new_x, new_y));
	return (1);
}

int	check_if_enemy_stopped(a_data *box)
{
	int	x;
	int	y;

	x = box->index_enemy[1];
	y = box->index_enemy[0];
	if ((box->map[y][x + 1] == '1' || box->map[y][x + 1] == 'E' || box->map[y][x
			+ 1] == 'C') &&
		(box->map[y][x - 1] == '1' || box->map[y][x - 1] == 'E' || box->map[y][x
				- 1] == 'C') &&
		(box->map[y + 1][x] == '1' || box->map[y + 1][x] == 'E' || box->map[y
				+ 1][x] == 'C') &&
		(box->map[y - 1][x] == '1' || box->map[y - 1][x] == 'E' || box->map[y
				- 1][x] == 'C'))
		return (1);
	return (0);
}

int	generate_valid_move(a_data *box, int *new_x, int *new_y)
{
	int	dx;
	int	dy;

	dx = box->index_player[1] - box->index_enemy[1];
	dy = box->index_player[0] - box->index_enemy[0];
	*new_x = box->index_enemy[1];
	*new_y = box->index_enemy[0];
	if (abs(dx) > abs(dy))
	{
		if (dx > 0)
			(*new_x)++;
		else
			(*new_x)--;
	}
	else
	{
		if (dy > 0)
			(*new_y)++;
		else
			(*new_y)--;
	}
	if (box->map[*new_y][*new_x] != 'E' && box->map[*new_y][*new_x] != 'C'
		&& box->map[*new_y][*new_x] != '1')
		return (1);
	return (generate_random_move(box, new_x, new_y), 1);
}

void	update_enemy_position(a_data *box)
{
	int	new_x;
	int	new_y;

	if (check_if_enemy_stopped(box))
		return ;
	while (!generate_valid_move(box, &new_x, &new_y))
		;
	box->map[box->index_enemy[0]][box->index_enemy[1]] = '0';
	box->index_enemy[0] = new_y;
	box->index_enemy[1] = new_x;
	if (box->map[new_y][new_x] == 'P')
		return (ft_putstr_fd("LOSER !!! ya lka3ka3\n", 1), clear_data(box, 3));
	box->map[new_y][new_x] = 'M';
	render_map(box->mlx_data->mlx, box->mlx_data->win, box->map, box);
}
