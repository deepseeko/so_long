/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:29:14 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/18 11:22:16 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void load_textures(t_mlx *mlx_data)
{
    int img_size = 64;
    mlx_data->game->wall = mlx_xpm_file_to_image(mlx_data->mlx, "textures/wall.xpm", &img_size, &img_size);
    mlx_data->game->exit = mlx_xpm_file_to_image(mlx_data->mlx, "textures/exit.xpm", &img_size, &img_size);
    mlx_data->game->coin = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin.xpm", &img_size, &img_size);
    mlx_data->game->player = mlx_xpm_file_to_image(mlx_data->mlx, "textures/player.xpm", &img_size, &img_size);
    mlx_data->game->enemy = mlx_xpm_file_to_image(mlx_data->mlx, "textures/enemy.xpm", &img_size, &img_size);
	if (!mlx_data->game->wall || !mlx_data->game->exit
			|| !mlx_data->game->coin || !mlx_data->game->player
				|| !mlx_data->game->enemy)
		return (clear_data(mlx_data->game, 2), ft_exit(0));
}

void init_win(a_data *box)
{
	int wigth;
	int height;
	box->mlx_data = malloc(sizeof(t_mlx));
	if (!box->mlx_data)
		return (clear_data(box, 2), ft_exit(0));
	box->mlx_data->game = box;
	wigth = box->size_map[1] * width_pixel;
	height = box->size_map[0] * height_pixel;
	box->mlx_data->mlx = mlx_init();
	if(!box->mlx_data->mlx)
		return (clear_data(box, 2), ft_exit(0));
	mlx_get_screen_size(box->mlx_data->mlx, &box->screen_w, &box->screen_h);
	if (wigth > box->screen_w || height > box->screen_h)
		return (clear_data(box, 3));
	mlx_data->win = mlx_new_window(mlx_data->mlx, wigth, height, "so_long");
	if (!mlx_data->win)
		return (clear_data(box, 3), ft_exit(0));
	load_textures(box->mlx_data);
	
	mlx_loop(mlx_data->mlx);
}

int main(int ac, char **av)
{
	a_data *box;

	if (ac != 2)
		ft_exit(0);
	box = init_data(av);
	init_win(box);

	(void)box;
	return (0);
}
