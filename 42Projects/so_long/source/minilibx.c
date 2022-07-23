/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:24 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 10:44:53 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close_window(void)
{
	exit(0);
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		move_person(vars, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	animation(t_vars *vars)
{
	int	w;
	int	l;

	w = 0;
	if ((double)(clock()) / CLOCKS_PER_SEC - vars->time >= (double)1 / 10)
	{
		vars->frame++;
		vars->time = (double)(clock()) / CLOCKS_PER_SEC;
	}
	if (vars->frame > 2)
		vars->frame = 0;
	while (vars->var_map[w])
	{
		l = 0;
		while (vars->var_map[w][l])
		{
			if (vars->var_map[w][l] == 'V' && vars->frame > 1)
				image_print('V', vars, l, w);
			else if (vars->var_map[w][l] == 'V' && vars->frame <= 1)
				image_print('X', vars, l, w);
			l++;
		}
		w++;
	}
	return (0);
}

void	work_minilib(t_map *lst)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, lst->width * 64, \
	lst->height * 75, "so_long");
	image_position(lst, &vars);
	mlx_hook(vars.win, 2, 0, ft_close, &vars);
	mlx_hook(vars.win, 17, 1L << 2, ft_close_window, &vars);
	mlx_loop_hook(vars.mlx, animation, &vars);
	mlx_loop(vars.mlx);
}
