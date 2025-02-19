/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:29:14 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/19 13:23:19 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void check_load(a_data *box)
{
	if (!box->wall || !box->exit || !box->coin_frames[0]
		|| !box->coin_frames[1] || !box->coin_frames[2]
			|| !box->coin_frames[3] || !box->coin_frames[4]
				|| !box->coin_frames[5] || !box->coin_frames[6]
					|| !box->coin_frames[7] || !box->coin_frames[8]
						|| !box->player || !box->bg)
		return (clear_data(box, 3), ft_exit(0));
}

void load_textures(t_mlx *mlx_data)
{
    int img_size = 64;
    mlx_data->game->wall = mlx_xpm_file_to_image(mlx_data->mlx, "textures/wall.xpm", &img_size, &img_size);
    mlx_data->game->exit = mlx_xpm_file_to_image(mlx_data->mlx, "textures/exit.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[0] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_1.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[1] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_2.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[2] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_3.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[3] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_4.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[4] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_5.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[5] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_6.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[6] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_7.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[7] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_8.xpm", &img_size, &img_size);
    mlx_data->game->coin_frames[8] = mlx_xpm_file_to_image(mlx_data->mlx, "textures/coin_9.xpm", &img_size, &img_size);
    mlx_data->game->player = mlx_xpm_file_to_image(mlx_data->mlx, "textures/player.xpm", &img_size, &img_size);
    //mlx_data->game->enemy = mlx_xpm_file_to_image(mlx_data->mlx, "textures/enemy.xpm", &img_size, &img_size);
    mlx_data->game->bg = mlx_xpm_file_to_image(mlx_data->mlx, "textures/bg.xpm", &img_size, &img_size);
    check_load(mlx_data->game);
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
			x++;
        }
        y++;
    }
}

void update_coin_frame(a_data *box)
{
    static int frame = 0;
    int x, y;

    y = 0;
    while (box->map[y])
    {
        x = 0;
        while (box->map[y][x])
        {
            if (box->map[y][x] == 'C')
                mlx_put_image_to_window(box->mlx_data->mlx, box->mlx_data->win, box->coin_frames[frame], x * 64, y * 64);
            x++;
        }
        y++;
    }
    frame = (frame + 1) % 9;
}


int timer_handler(void *param)
{
	static int cout;

    a_data *box = (a_data *)param;
	//usleep(130000);
	if (cout % 5700 == 0)
	{
		update_coin_frame(box);
		cout = 0;
	}
	cout++;
    return (0);
}

int handle_keypress(int keycode, a_data *box)
{
    int new_x = box->index_player[1];
    int new_y = box->index_player[0];

    update_position(keycode, &new_x, &new_y);
    if (keycode == 65307)
    {
        clear_data(box, 3);
        ft_exit(0);
    }
    if (box->map[new_y][new_x] != '1')
    {
		if (new_x != box->index_player[1] || new_y != box->index_player[0] && (box->map[new_y][new_x] =='E' && box->collect == box->number_of_collect))
			box->moves++;
        update_game_state(box, new_x, new_y);
        render_map(box->mlx_data->mlx, box->mlx_data->win, box->map, box);
        display_stats(box);
    }
    return (0);
}

void update_position(int keycode, int *new_x, int *new_y)
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

void update_game_state(a_data *box, int new_x, int new_y)
{
    if (box->map[new_y][new_x] == 'C')
    {
        box->collect++;
    }
	if (box->map[new_y][new_x] == 'E' && box->collect == box->number_of_collect)
	{
		ft_putstr_fd("You win !\n", 1);
		clear_data(box, 3);
		ft_exit(0);
	}

    box->map[box->index_player[0]][box->index_player[1]] = '0';
    box->index_player[0] = new_y;
    box->index_player[1] = new_x;
    box->map[new_y][new_x] = 'P';
}

void display_stats(a_data *box)
{
    char *moves_str = ft_itoa(box->moves);
    char *collect_str = ft_itoa(box->collect);

    mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 20, 20, 0x000000, "Moves: ");
    mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 80, 20, 0xfa7302, moves_str);
    mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 20, 40, 0x000000, "Collect: ");
    mlx_string_put(box->mlx_data->mlx, box->mlx_data->win, 80, 40, 0xfa7302, collect_str);
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(box->moves, 1);
	ft_putstr_fd("\n", 1);
    free(moves_str);
    free(collect_str);
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
	mlx_key_hook(box->mlx_data->win, handle_keypress, box);
	mlx_loop_hook(box->mlx_data->mlx, timer_handler, box);
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
