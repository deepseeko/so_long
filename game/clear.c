/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:11:00 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/18 11:19:46 by ybouanan         ###   ########.fr       */
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

void free_copy_map(a_data *box)
{
    int i;

    i = 0;
    while (i <= box->size_map[0])
    {
        free(box->copy_map[i]);
        i++;
    }
    free(box->copy_map);
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
        free(data);
    }
}

void free_data_mlx(a_data *box)
{
    free_2darr(box->map);
    free_copy_map(box);
    if (box->mlx_data)
    {
        if (box->mlx_data->mlx)
            mlx_destroy_display(mlx_data->mlx);
        free(box->mlx_data);
    }
    free(box);
}

void clear_data(a_data *box , int flag)
{
    if (flag == 1) //3andi path , map
        return(free_2darr(box->map), free(box), ft_exit(0));
    if (flag == 2) //3andi path , map , copy_map
        return(free_2darr(box->map), free_copy_map(box), free(box), ft_exit(0));
    if (flag == 3) // 3andi path , map , copy_map , mlx_data
        return(free_data_mlx(box), ft_exit(0));
}
