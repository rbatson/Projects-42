/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:27 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 10:44:49 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_stdout(t_vars *vars, char s)
{
	if (s != '1')
	{
		vars->count++;
		printf("Step: %d\n", vars->count);
	}
}

void	move_jhonny_2(t_vars *vars, char s)
{
	if (s == 'C')
	{
		vars->sum_goals--;
		if (vars->sum_goals == 0)
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, \
				vars->img_amber_broken, &vars->img_width, &vars->img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
				vars->exit_x * 64, vars->exit_y * 64);
		}
	}
}

void	move_jhonny_1(t_vars *vars, char s, int x, int y)
{
	if (s == '0' || s == 'C' || s == 'V')
	{
		if (vars->var_map[y][x] == 'V')
		{
			printf("<<<YOU LOSE>>>\n");
			exit(1);
		}
		put_stdout(vars, s);
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_jhonny, \
		&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img, x * 64, y * 64);
		vars->var_map[y][x] = 'P';
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_space, \
		&vars->img_width, &vars->img_height);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
		vars->person_x * 64, vars->person_y * 64);
		move_jhonny_2(vars, s);
		vars->var_map[vars->person_y][vars->person_x] = '0';
		vars->person_x = x;
		vars->person_y = y;
	}
}

void	move_jhonny(t_vars *vars, char s, int x, int y)
{
	static char	*step;

	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_cube, \
		&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
	64, vars->height * 66);
	move_jhonny_1(vars, s, x, y);
	step = ft_itoa(vars->count);
	mlx_string_put(vars->mlx, vars->win, 80, vars->height * 68, \
				0x00FFFFFF, step);
	free(step);
}

void	move_person(t_vars *vars, int keycode)
{
	if (keycode == 123)
		move(vars, 123);
	else if (keycode == 124)
		move(vars, 124);
	else if (keycode == 125)
		move(vars, 125);
	else if (keycode == 126)
		move(vars, 126);
}	
