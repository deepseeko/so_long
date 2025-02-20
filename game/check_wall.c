/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:13:06 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 19:53:19 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	check_top_wall(t_data *box)
{
	int	i;

	i = 0;
	while (box->map[0][i])
	{
		if (box->map[0][i] != '1')
			return (clear_data(box, 1), ft_exit(0));
		i++;
	}
}

void	check_bottom_wall(t_data *box)
{
	int	i;
	int	j;

	i = 0;
	j = box->size_map[0];
	while (box->map[j][i])
	{
		if (box->map[j][i] != '1')
			return (clear_data(box, 1), ft_exit(0));
		i++;
	}
}

void	check_side_walls(t_data *box)
{
	int	j;

	j = box->size_map[0] - 1;
	while (j >= 0)
	{
		if (box->map[j][0] != '1' || box->map[j][box->size_map[1] - 1] != '1')
			return (clear_data(box, 1), ft_exit(0));
		j--;
	}
}

void	check_wall(t_data *box)
{
	check_top_wall(box);
	check_bottom_wall(box);
	check_side_walls(box);
}
