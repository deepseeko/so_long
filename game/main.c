/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:29:14 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/17 19:41:22 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"
#include <mlx.h>

int main(int ac, char **av)
{
	a_data *box;
	void *mlx;
	void *win;
	int wigth;
	int height;

	if (ac != 2)
		ft_exit(0);
	box = init_data(av);
	wigth = box->size_map[1] * width_pixel;
	height = box->size_map[0] * height_pixel;
	mlx = mlx_init();
	if(!mlx)
		return (clear_data(box, 2), ft_exit(0), 0);
	win = mlx_new_window(mlx, wigth, height, "so_long");
	if (!win)
		return (clear_data(box, 2), ft_exit(0), 0);
	mlx_loop(mlx);
	(void)box;
	return (0);
}
