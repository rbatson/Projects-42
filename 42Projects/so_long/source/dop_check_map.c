/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:08 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 10:44:54 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_parametrs(t_map *lst)
{
	lst->sum_enemy = 0;
	lst->sum_barrier = 0;
	lst->sum_exit = 0;
	lst->sum_goal = 0;
	lst->sum_player = 0;
}

void	check_map_parametrs(t_map *lst)
{
	init_parametrs(lst);
	check_first_and_last_line(lst, 0);
	check_first_and_last_line(lst, lst->height - 1);
	check_other_wall(lst);
	check_all_other(lst, 1, 1);
}
