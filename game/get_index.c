/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:31:25 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 19:53:35 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	get_index_player(t_data *box)
{
	int	j;
	int	i;

	i = 0;
	while (i < box->size_map[0])
	{
		j = 0;
		while (j < box->size_map[1])
		{
			if (box->copy_map[i][j] == 'P')
			{
				box->index_player[0] = i;
				box->index_player[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_index_enemy(t_data *box)
{
	int	j;
	int	i;

	i = 0;
	while (i < box->size_map[0])
	{
		j = 0;
		while (j < box->size_map[1])
		{
			if (box->copy_map[i][j] == 'M')
			{
				box->index_enemy[0] = i;
				box->index_enemy[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
