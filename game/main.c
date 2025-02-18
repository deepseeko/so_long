/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:29:14 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/18 18:54:14 by ybouanan         ###   ########.fr       */
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
	mlx_data->game->bg = mlx_xpm_file_to_image(mlx_data->mlx, "textures/bg.xpm", &img_size, &img_size);
	if (!mlx_data->game->wall || !mlx_data->game->bg || !mlx_data->game->player || !mlx_data->game->exit)
		return (clear_data(mlx_data->game, 3), ft_exit(0));
	// || !mlx_data->game->exit
	// 		|| !mlx_data->game->coin || !mlx_data->game->player
	// 			|| !mlx_data->game->enemy)
	// 	return (clear_data(mlx_data->game, 3), ft_exit(0));
}

void render_map(void *mlx, void *win, char **map,a_data *box)
{
    int x, y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, box->wall, x * 64, y * 64);
			if(map[y][x] == '0')
				mlx_put_image_to_window(mlx, win , box->bg, x * 64, y * 64);
			if(map[y][x] == 'P')
				mlx_put_image_to_window(mlx, win, box->player, x * 64, y * 64);
            if (map[y][x] == 'E')
				mlx_put_image_to_window(mlx, win, box->exit, x * 64, y * 64);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, box->coin, x * 64, y * 64);
			x++;
        }
        y++;
    }
}

void render_coins(void *mlx, void *win, char **map,a_data *box)
{
	int x, y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx, win, box->coin, x * 64, y * 64);
			x++;
		}
		y++;
	}
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
	height = box->size_map[0] * height_pixel + 64;
	box->mlx_data->mlx = mlx_init();
	if(!box->mlx_data->mlx)
		return (clear_data(box, 2), ft_exit(0));
	mlx_get_screen_size(box->mlx_data->mlx, &box->screen_w, &box->screen_h);
	if (wigth > box->screen_w || height > box->screen_h)
		return (clear_data(box, 3));
	box->mlx_data->win = mlx_new_window(box->mlx_data->mlx, wigth, height, "so_long");
	if (!box->mlx_data->win)
		return (clear_data(box, 3), ft_exit(0));
	load_textures(box->mlx_data);
	render_map(box->mlx_data->mlx, box->mlx_data->win, box->map , box);
	render_coins(box->mlx_data->mlx, box->mlx_data->win, box->map , box);
	mlx_loop_hook(box->mlx_data->mlx, & box);
	mlx_loop(box->mlx_data->mlx);
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
