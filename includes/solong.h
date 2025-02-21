/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:44:04 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/21 22:31:56 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../src/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef WP
#  define WP 64
# endif

# ifndef HP
#  define HP 64
# endif

# define KEY_A 97
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115

typedef struct mlx_data	t_mlx;

typedef struct all_data
{
	char				*path;
	int					fd;
	char				**map;
	char				**copy_map;
	int					number_of_collect;
	int					number_of_exit;
	int					number_of_player;
	int					number_of_enemy;
	int					moves;
	int					collect;
	int					size_map[2];
	int					**map_copy;
	int					index_player[2];
	int					index_enemy[2];
	int					screen_w;
	int					screen_h;
	t_mlx				*mlx_data;
	void				*wall;
	void				*exit;
	void				*coin_frames[9];
	void				*player;
	void				*enemy;
	void				*bg;
}						t_data;

typedef struct mlx_data
{
	void				*mlx;
	void				*win;
	t_data				*game;
}						t_mlx;

void					ft_exit(int flag);
void					free_2darr(char **arr);
int						check_path(char *path, t_data *box);
void					init_path(char *str, t_data *box, char **splited_path);
t_data					*init_data(char **av);
void					clear_data(t_data *box, int flag);
void					free_data(t_data *data);
char					*get_next_line(int fd);
void					check_map(t_data *box);
char					**get_map(t_data *box);
void					ft_reset_file(t_data *box);
int						get_size_map(t_data *box);
void					check_lent_size(t_data *box, int i);
void					check_top_wall(t_data *box);
void					check_bottom_wall(t_data *box);
void					check_side_walls(t_data *box);
void					check_wall(t_data *box);
void					check_char(t_data *box);
void					get_index_player(t_data *box);
void					get_index_enemy(t_data *box);
void					init_zero(t_data *box, int *i, int *j);
void					count_char(t_data *box);
void					check_flood_fill(t_data *box);
void					copy_map(t_data *box);
void					flood_fill_helper(t_data *box, int x, int y);
void					check_if_flooded(t_data *box);
void					render_map(void *mlx, void *win, char **map,
							t_data *box);
void					free_data_mlx(t_data *box);
void					display_stats(t_data *box);
int						handle_keypress(int keycode, t_data *box);
int						timer_handler(void *param);
void					update_position(int keycode, int *new_x, int *new_y);
void					update_game_state(t_data *box, int new_x, int new_y);
void					update_enemy_position(t_data *box);
int						generate_valid_move(t_data *box, int *new_x,
							int *new_y);
void					init_win(t_data *box);
void					load_textures(t_mlx *mlx_data);
void					check_load(t_data *box);
void					update_coin_frame(t_data *box);
void					put_error(char *str);
int						exit_clear(void *box);

#endif
