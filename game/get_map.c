/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:34:24 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/25 19:54:00 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"
#include <fcntl.h>

void	check_all(t_data *box, int i)
{
	check_lent_size(box, i - 1);
	check_wall(box);
	check_char(box);
	count_char(box);
	ft_reset_file(box);
	check_flood_fill(box);
	close(box->fd);
}

char	**get_map(t_data *box)
{
	int		i;
	char	*s ;

	s = "map not valid\n";
	box->map = NULL;
	i = get_size_map(box);
	if (i <= 0)
		return (put_error(s), clear_data(box, 1), ft_exit(0), NULL);
	box->map = malloc(sizeof(char *) * (i + 1));
	if (!box->map)
		return (put_error(s), clear_data(box, 1), ft_exit(0), NULL);
	i = 0;
	box->map[i] = get_next_line(box->fd);
	if (!box->map[i])
		return (put_error(s), clear_data(box, 1), ft_exit(0), NULL);
	while (box->map[i])
	{
		i++;
		box->map[i] = get_next_line(box->fd);
	}
	if (i < 3)
		return (put_error(s), clear_data(box, 1), ft_exit(0), NULL);
	check_all(box, i);
	return (box->map);
}

void	check_map(t_data *box)
{
	int	fd;

	fd = open(box->path, O_RDONLY);
	box->fd = fd;
	if (fd == -1)
		return (free(box), ft_exit(0));
	get_map(box);
}
