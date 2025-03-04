/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:03:33 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/28 15:01:57 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_win(t_data *box)
{
	int	wigth;
	int	height;

	box->mlx_data = malloc(sizeof(t_mlx));
	if (!box->mlx_data)
		return (put_error("malloc"), clear_data(box, 2), ft_exit(0));
	box->mlx_data->game = box;
	wigth = box->size_map[1] * WP;
	height = box->size_map[0] * HP + 64;
	box->mlx_data->mlx = mlx_init();
	if (!box->mlx_data->mlx)
		return (put_error("MLX error"), clear_data(box, 2), ft_exit(0));
	mlx_get_screen_size(box->mlx_data->mlx, &box->screen_w, &box->screen_h);
	box->mlx_data->win = mlx_new_window(box->mlx_data->mlx, wigth, height,
			"so_long");
	if (!box->mlx_data->win)
		return (put_error("MLX error"), clear_data(box, 3), ft_exit(0));
	load_textures(box->mlx_data);
	render_map(box->mlx_data->mlx, box->mlx_data->win, box->map, box);
	mlx_key_hook(box->mlx_data->win, handle_keypress, box);
	mlx_hook(box->mlx_data->win, 17, 4, exit_clear, box);
	mlx_loop_hook(box->mlx_data->mlx, timer_handler, box);
	mlx_loop(box->mlx_data->mlx);
}
