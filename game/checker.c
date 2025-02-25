/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:50:11 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/25 19:57:44 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"
#include <fcntl.h>

int	check_path(char *path, t_data *box)
{
	char	**path_tree;
	int		dir;
	int		index;

	if (!path || ft_strlen(path) <= 4)
		return (free(box), ft_exit(0), 0);
	path_tree = ft_split(path, '/');
	if (!path_tree)
		return (free(box), ft_exit(0), 0);
	dir = 0;
	while (path_tree[dir])
		dir++;
	if (dir == 0)
		return (free_2darr(path_tree), free(box), ft_exit(0), 0);
	index = ft_strlen(path_tree[dir - 1]);
	if (index > 4 && ft_strncmp(path_tree[dir - 1] + index - 4, ".ber", 4) == 0)
		return (init_path(path, box, path_tree), 1);
	else
		return (free_2darr(path_tree), free(box), ft_exit(0), 0);
}

void	check_lent_size(t_data *box, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(box->map[0]);
	while (box->map[j])
	{
		if (ft_strlen(box->map[j]) != len)
			return (put_error("map not valid"), clear_data(box, 1), ft_exit(0));
		j++;
	}
	box->size_map[0] = i;
	box->size_map[1] = len;
	if (box->size_map[0] < 3 || box->size_map[1] < 3)
		return (put_error("map not valid\n"), clear_data(box, 1), ft_exit(0));
}

void	ft_reset_file(t_data *box)
{
	close(box->fd);
	box->fd = open(box->path, O_RDONLY);
}

int	get_size_map(t_data *box)
{
	int		i;
	int		flag;
	char	*line;

	i = 0;
	flag = 1;
	while (flag)
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
