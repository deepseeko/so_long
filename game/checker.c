/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:50:11 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/17 13:37:57 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"
# include <fcntl.h>

int check_path(char *path, a_data *box)
{
    char **path_tree;
    int dir;
    int index;

    if (!path || ft_strlen(path) <= 4)
        return (free(box),ft_exit(0), 0);
    path_tree = ft_split(path, '/');
    if (!path_tree)
        ft_exit(0);
    dir = 0;
    while (path_tree[dir])
        dir++;
    if (dir == 0)
        return (free_2darr(path_tree) , free(box), ft_exit(0) , 0);
    index = ft_strlen(path_tree[dir - 1]);
    if (index > 4 && ft_strncmp(path_tree[dir - 1] + index - 4, ".ber", 4) == 0)
        return (init_path(path, box, path_tree) , 1);
    else
        return (free_2darr(path_tree), free(box), ft_exit(0), 0);
}

void check_lent_size(a_data *box, int i)
{
    int j;
    int len;

    j = 0;
    len = ft_strlen(box->map[0]);
    while (box->map[j])
    {
        if (ft_strlen(box->map[j]) != len)
            return (clear_data(box, 1), ft_exit(0));
        j++;
    }
    box->size_map[0] = i;
    box->size_map[1] = len;
}

void ft_reset_file(a_data *box)
{
    close(box->fd);
    box->fd = open(box->path, O_RDONLY);
}

int get_size_map(a_data *box)
{
    int i;
    int flag;
    char *line;

    i = 0;
    flag = 1;
    while(flag)
    {
        line = get_next_line(box->fd);
        if (!line)
            flag = 0;
        free(line);
        i++;
    }
    ft_reset_file(box);
    return (i);
}

char **get_map(a_data *box)
{
    int i;

    i = get_size_map(box);
    if ( i <= 2)
        return (clear_data(box, 1), ft_exit(0), box->map);
    box->map = malloc(sizeof(char *) * (i + 1));
    if (!box->map)
       return (clear_data(box, 1), ft_exit(0),box->map);
    i = 0;
    box->map[i] = get_next_line(box->fd);
    while(box->map[i])
    {
        i++;
        box->map[i] = get_next_line(box->fd);
    }
    while(box->map[i] == NULL)
        i--;
    check_lent_size(box, i);
    check_wall(box);
    check_char(box);
    count_char(box);
    ft_reset_file(box);
    check_flood_fill(box);
    return (box->map);
}

void check_map(a_data *box)
{
    int fd;

    fd = open(box->path, O_RDONLY);
    box->fd = fd;
    if (fd == -1)
        return (free(box), ft_exit(0));
    get_map(box);
}
