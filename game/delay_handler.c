/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delay_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:20:01 by ybouanan          #+#    #+#             */
/*   Updated: 2025/02/20 16:20:15 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int timer_handler(void *param)
{
	static int cout;
    static int delay_enemy;

    a_data *box = (a_data *)param;
	if (cout % 5700 == 0)
	{
	    update_coin_frame(box);
	 	cout = 0;
	}
    if (delay_enemy % 50000 == 0)
    {
        update_enemy_position(box);
        delay_enemy = 0;
    }
    cout++;
    delay_enemy++;
    return (0);
}
