/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:04 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 10:40:43 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_first_and_last_line(t_map *lst, int i)
{
	int	k;

	k = 0;
	while (lst->map[i][k])
	{
		if (lst->map[i][k] != '1')
			error_output("This is not a wall\n");
		k++;
	}
}

void	check_other_wall(t_map *lst)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i != lst->height - 1)
	{
		if (lst->map[i][k] != '1' || lst->map[i][lst->width - 1] != '1')
			error_output("This is not a wall\n");
		i++;
	}
}

void	allowed_symbols(char c, t_map *lst)
{
	if (c == 'V')
		lst->sum_enemy++;
	if (c == '1')
		lst->sum_barrier++;
	if (c == 'C')
		lst->sum_goal++;
	if (c == 'P')
	{
		lst->sum_player++;
		if (lst->sum_player > 1)
			error_output("Player more than 1\n");
	}
	if (c == 'E')
	{
		lst->sum_exit++;
		if (lst->sum_exit > 1)
			error_output("Exit more than 1\n");
	}
	if (!(c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E' || c == 'V'))
	{
		error_output("Invalid character\n");
		exit(1);
	}
}

void	check_all_other(t_map *lst, int i, int k)
{
	while (i != lst->height - 1)
	{
		while (k != lst->width - 1)
		{
			allowed_symbols(lst->map[i][k], lst);
			k++;
		}
		k = 0;
		i++;
	}
	if (lst->sum_exit == 0 || lst->sum_player == 0 \
	|| lst->sum_goal == 0)
		error_output("Absent P or E or G\n");
}
