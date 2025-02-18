/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:44:04 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/17 21:38:58 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include "../src/libft.h"
#include <mlx.h>


#ifndef width_pixel
# define width_pixel 64
#endif

#ifndef height_pixel
# define height_pixel 64
#endif

typedef struct all_data
{
    char *path;
    int fd;
    char   **map;
    char   **copy_map;
    int number_of_collect;
    int number_of_exit;
    int number_of_player;
    int number_of_enemy;
    int size_map[2];
    int **map_copy;
    int index_player[2];
    void *wall;
    void *exit;
    void *coin;
    void *player;
    void *enemy;
}                  a_data;

void ft_exit(int flag);
void free_2darr(char **arr);
int check_path(char *path, a_data *box);
void init_path(char *str , a_data *box , char **splited_path);
a_data *init_data(char **av);
void clear_data(a_data *box , int flag);
void free_data(a_data *data);
char	*get_next_line(int fd);
void check_map(a_data *box);
char **get_map(a_data *box);
void ft_reset_file(a_data *box);
int get_size_map(a_data *box);
void check_lent_size(a_data *box, int i);
void check_top_wall(a_data *box);
void check_bottom_wall(a_data *box);
void check_side_walls(a_data *box);
void check_wall(a_data *box);
void check_char(a_data *box);
void init_zero(a_data *box , int *i , int *j);
void count_char(a_data *box);
void check_flood_fill(a_data *box);
void copy_map(a_data *box);
void flood_fill(char **map , int x_m, int y_m, int x, int y , char target);
void check_if_flooded(a_data *box);


#endif
