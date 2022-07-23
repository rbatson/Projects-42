/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_minilibix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:12 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 10:41:12 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	image_print_1(char a, t_vars *vars, int i, int k)
{
	if (a == 'C')
	{
		vars->sum_goals++;
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_collectible, \
			&vars->img_width, &vars->img_height);
	}
	else if (a == 'P')
	{
		vars->person_x = i;
		vars->person_y = k;
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_jhonny, \
			&vars->img_width, &vars->img_height);
	}
	else if (a == 'E')
	{
		vars->exit_x = i;
		vars->exit_y = k;
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_amber_normal, \
			&vars->img_width, &vars->img_height);
	}
}

void	image_print(char a, t_vars *vars, int i, int k)
{
	mlx_string_put(vars->mlx, vars->win, 10, \
					vars->height * 68, 0x00FFFFFF, "Step =");
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_space, \
					&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i * 64, k * 64);
	if (a == '1')
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_barrier, \
			&vars->img_width, &vars->img_height);
	else if (a == 'V')
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_enemy1, \
			&vars->img_width, &vars->img_height);
	else if (a == 'X')
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_enemy2, \
			&vars->img_width, &vars->img_height);
	image_print_1(a, vars, i, k);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i * 64, k * 64);
}

char	*check_image(char *image)
{
	if (open(image, O_RDONLY) < 0)
		error_output("File can not open");
	return (image);
}

void	init_image(t_vars *vars, t_map *lst)
{
	vars->height = lst->height;
	vars->count = 0;
	vars->sum_goals = 0;
	vars->var_map = lst->map;
	vars->img_width = 64;
	vars->img_height = 64;
	vars->img_cube = check_image("image/black.XPM");
	vars->img_enemy1 = check_image("image/hammer1.XPM");
	vars->img_enemy2 = check_image("image/hammer2.XPM");
	vars->img_jhonny = check_image("image/jhonnydepp.XPM");
	vars->img_barrier = check_image("image/wall.XPM");
	vars->img_space = check_image("image/courtfloor.XPM");
	vars->img_collectible = check_image("image/evidence.XPM");
	vars->img_amber_normal = check_image("image/ambernormal.XPM");
	vars->img_amber_broken = check_image("image/amberbroken.XPM");
}

void	image_position(t_map *lst, t_vars *vars)
{
	int	i;
	int	k;

	i = 0;
	init_image(vars, lst);
	while (vars->var_map[i])
	{
		k = 0;
		while (vars->var_map[i][k])
		{
			image_print(vars->var_map[i][k], vars, k, i);
			k++;
		}
		i++;
	}
}
