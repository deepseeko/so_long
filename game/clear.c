/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:11:00 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/17 10:01:20 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"


void ft_exit(int flag)
{
    if (flag == 0)
        ft_putstr_fd("Error\n", 2);
    exit(0);
}

void free_2darr(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void free_2dintarr(int **arr, int size)
{
    int i = 0;
    if (arr)
    {
        while (i < size)
        {
            free(arr[i]);
            i++;
        }
        free(arr);
    }
}

void free_data(a_data *data)
{
    if (data)
    {
        free(data->path);
        free_2darr(data->map);
        free_2darr(data->copy_map);
        free_2dintarr(data->map_copy, data->size_map[0]);
        free_2dintarr(data->index_collect, data->number_of_collect);
        free_2dintarr(data->index_enemy, data->number_of_enemy);
        free(data);
    }
}
void clear_data(a_data *box , int flag)
{
    if (flag == 1) //3andi path , map
        return(free_2darr(box->map), free(box), ft_exit(1));
    if (flag == 2) //3andi path , map , copy_map
        return(free_2darr(box->map), free_2darr(box->copy_map), free(box), ft_exit(0));
}
