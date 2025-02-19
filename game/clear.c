/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:11:00 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/19 20:50:44 by ybouanan         ###   ########.fr       */
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

void free_coin_images(a_data *box)
{
    if (box->coin_frames[0])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[0]);
    if (box->coin_frames[1])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[1]);
    if (box->coin_frames[2])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[2]);
    if (box->coin_frames[3])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[3]);
    if (box->coin_frames[4])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[4]);
    if (box->coin_frames[5])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[5]);
    if (box->coin_frames[6])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[6]);
    if (box->coin_frames[7])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[7]);
    if (box->coin_frames[8])
        mlx_destroy_image(box->mlx_data->mlx, box->coin_frames[8]);
}

void clear_data(a_data *box, int flag)
{
    if (flag != 1 && box->mlx_data)
    {
        if (box->mlx_data->win)
            mlx_destroy_window(box->mlx_data->mlx, box->mlx_data->win);
        if (box->wall)
            mlx_destroy_image(box->mlx_data->mlx, box->wall);
        if (box->exit)
            mlx_destroy_image(box->mlx_data->mlx, box->exit);
        free_coin_images(box);
        if (box->player)
            mlx_destroy_image(box->mlx_data->mlx, box->player);
        if (box->bg)
            mlx_destroy_image(box->mlx_data->mlx, box->bg);
        if (box->number_of_enemy != 0 && box->enemy)
            mlx_destroy_image(box->mlx_data->mlx, box->enemy);
        mlx_destroy_display(box->mlx_data->mlx);
        free(box->mlx_data->mlx);
        free(box->mlx_data);
    }
    if (flag >= 1)
        free_2darr(box->map);
    if (flag >= 2)
        free_copy_map(box);
    free(box);
    ft_exit(0);
}
