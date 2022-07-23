/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:41:14 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:41 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_env(t_env *env)
{
	int	i;

	if (env->philos)
	{
		i = 0;
		while (i < env->amount)
		{
			pthread_mutex_destroy(&env->philos[i].mutex);
			pthread_mutex_destroy(&env->philos[i].eat_m);
			pthread_mutex_destroy(&env->philos[i].l_fork->fork_m);
			free(env->philos[i++].l_fork);
		}
		free(env->philos);
	}
	pthread_mutex_destroy(&env->write_m);
	pthread_mutex_destroy(&env->died_m);
	return (1);
}

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}

static int	init_mutexes(t_env *env)
{
	int	i;

	pthread_mutex_init(&env->write_m, NULL);
	pthread_mutex_init(&env->died_m, NULL);
	pthread_mutex_lock(&env->died_m);
	i = 0;
	while (i < env->amount)
	{
		pthread_mutex_init(&env->philos[i].mutex, NULL);
		pthread_mutex_init(&env->philos[i].eat_m, NULL);
		pthread_mutex_init(&env->philos[i].l_fork->fork_m, NULL);
		pthread_mutex_lock(&env->philos[i].eat_m);
		i++;
	}
	return (0);
}

static void	init_philos(t_env *env)
{
	t_fork	*fork;
	int		i;

	fork = malloc(sizeof(t_fork));
	env->philos[0].is_eating = 0;
	env->philos[0].id = 0;
	env->philos[0].l_fork = fork;
	env->philos[0].eat_count = 0;
	env->philos[0].env = env;
	i = 1;
	while (i < env->amount)
	{
		fork = malloc(sizeof(t_fork));
		env->philos[i].is_eating = 0;
		env->philos[i].id = i;
		env->philos[i].l_fork = fork;
		env->philos[i - 1].r_fork = fork;
		env->philos[i].eat_count = 0;
		env->philos[i].env = env;
		i++;
	}
	env->philos[i - 1].r_fork = env->philos[0].l_fork;
}

int	init(t_env *env, int argc, char const **argv)
{
	env->amount = ft_atoi(argv[1]);
	env->to_die = ft_atoi(argv[2]);
	env->to_eat = ft_atoi(argv[3]);
	env->to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->to_end_count = ft_atoi(argv[5]);
	else
		env->to_end_count = 0;
	env->philos = NULL;
	env->philos = (t_philo *)malloc(sizeof(*(env->philos)) * env->amount);
	if (!(env->philos))
		return (1);
	init_philos(env);
	return (init_mutexes(env));
}
