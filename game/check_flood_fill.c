/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:21:43 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/17 11:12:19 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"


void copy_map(a_data *box)
{
	int i;
	int j;

	i = 0;
	box->copy_map = malloc(sizeof(char *) * (box->size_map[0] + 1));
	if (!box->copy_map)
		return (clear_data(box, 2), ft_exit(0));
	while (i < box->size_map[0] + 1)
	{
		box->copy_map[i] = ft_strdup(box->map[i]);
		i++;
	}
}

get_index_player(a_data *box)
{
	int j;
	int i;

	while(box->copy_map[i])
	{
		j = 0;
		while(box->copy_map[i][j])
		{
			if (box->copy_map[i][j] == 'P')
			{
				box->index_player[0] = i;
				box->index_player[1] = j;
			}
			j++;
		}
		i++;
	}
}
void check_flood_fill(a_data *box)
{
	copy_map(box);
	get_index_player(box);
	flood_fill(box, box->index_player , box->size_map[0], box->size_map[1]);
}
