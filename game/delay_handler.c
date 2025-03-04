/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:20:01 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/28 14:18:44 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	timer_handler(void *param)
{
	static int	cout;
	static int	delay_enemy;
	t_data		*box;

	box = (t_data *)param;
	if (cout % 6701 == 0)
	{
		update_coin_frame(box);
		cout = 0;
	}
	if (delay_enemy % 40007 == 0)
	{
		update_enemy_position(box);
		delay_enemy = 0;
	}
	cout++;
	delay_enemy++;
	return (0);
}
