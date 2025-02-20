/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:15:51 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 19:53:48 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	check_load(t_data *box)
{
	if (!box->wall || !box->exit || !box->coin_frames[0] || !box->coin_frames[1]
		|| !box->coin_frames[2] || !box->coin_frames[3] || !box->coin_frames[4]
		|| !box->coin_frames[5] || !box->coin_frames[6] || !box->coin_frames[7]
		|| !box->coin_frames[8] || !box->player || !box->bg)
		return (clear_data(box, 3), ft_exit(0));
	if (box->number_of_enemy != 0 && !box->enemy)
		return (clear_data(box, 3), ft_exit(0));
}

void	load_basic_textures(t_mlx *mlx_data, int img_size)
{
	mlx_data->game->wall = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/wall.xpm", &img_size, &img_size);
	mlx_data->game->exit = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/exit.xpm", &img_size, &img_size);
}

void	load_coin_textures(t_mlx *mlx_data, int img_size)
{
	mlx_data->game->coin_frames[0] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_1.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[1] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_2.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[2] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_3.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[3] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_4.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[4] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_5.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[5] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_6.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[6] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_7.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[7] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_8.xpm", &img_size, &img_size);
	mlx_data->game->coin_frames[8] = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/coin_9.xpm", &img_size, &img_size);
}

void	load_player_enemy_bg(t_mlx *mlx_data, int img_size)
{
	mlx_data->game->player = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/player.xpm", &img_size, &img_size);
	if (mlx_data->game->number_of_enemy != 0)
		mlx_data->game->enemy = mlx_xpm_file_to_image(mlx_data->mlx,
				"textures/enemy.xpm", &img_size, &img_size);
	mlx_data->game->bg = mlx_xpm_file_to_image(mlx_data->mlx,
			"textures/bg.xpm", &img_size, &img_size);
}

void	load_textures(t_mlx *mlx_data)
{
	int	img_size;

	img_size = 64;
	load_basic_textures(mlx_data, img_size);
	load_coin_textures(mlx_data, img_size);
	load_player_enemy_bg(mlx_data, img_size);
	check_load(mlx_data->game);
}
