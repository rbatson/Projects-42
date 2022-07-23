/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_additional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:15 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 09:50:13 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_1(t_vars *vars, int move, int x, int y)
{
	if (move == 125)
	{
		x = vars->person_x;
		y = vars->person_y + 1;
		move_jhonny(vars, vars->var_map[y][x], x, y);
	}
	else if (move == 126)
	{
		x = vars->person_x;
		y = vars->person_y - 1;
		move_jhonny(vars, vars->var_map[y][x], x, y);
	}
	if (vars->sum_goals == 0 && x == vars->exit_x && vars->exit_y == y)
	{
		printf("<<<YOU WIN>>>\n");
		exit(0);
	}
}

void	move(t_vars *vars, int move)
{
	int	x;
	int	y;

	x = vars->person_x;
	y = vars->person_y;
	if (move == 123)
	{
		x = vars->person_x - 1;
		y = vars->person_y;
		move_jhonny(vars, vars->var_map[y][x], x, y);
	}
	else if (move == 124)
	{
		x = vars->person_x + 1;
		y = vars->person_y;
		move_jhonny(vars, vars->var_map[y][x], x, y);
	}
	move_1(vars, move, x, y);
}
