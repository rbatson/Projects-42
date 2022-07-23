/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:34 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:42 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor_count(void *state_v)
{
	t_env	*env;
	int		i;
	int		total;

	env = (t_env *)state_v;
	total = 0;
	while (total < env->to_end_count)
	{
		i = 0;
		while (i < env->amount)
			pthread_mutex_lock(&env->philos[i++].eat_m);
		total++;
	}
	display_message(&env->philos[0], TYPE_OVER);
	pthread_mutex_unlock(&env->died_m);
	return ((void *)0);
}

static void	*monitor(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo *)philo_v;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && get_time() > philo->limit)
		{
			display_message(philo, TYPE_DIED);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->env->died_m);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

static void	*routine(void *philo_v)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)philo_v;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->env->to_die;
	if (pthread_create(&tid, NULL, &monitor, philo_v) != 0)
		return ((void *)1);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		clean_forks(philo);
		display_message(philo, TYPE_THINK);
	}
	return ((void *)0);
}

static int	start_threads(t_env *env)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	env->start = get_time();
	if (env->to_end_count > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void *)env) != 0)
			return (1);
		pthread_detach(tid);
	}
	i = 0;
	while (i < env->amount)
	{
		philo = (void *)(&env->philos[i]);
		if (pthread_create(&tid, NULL, &routine, philo) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	return (0);
}

int	main(int argc, char const **argv)
{
	t_env	env;

	if (argc < 5 || argc > 6)
		return (exit_error("bad arguments\n"));
	if (init(&env, argc, argv))
		return (clear_env(&env) && exit_error("init error\n"));
	if (start_threads(&env))
		return (clear_env(&env) && exit_error("start threads error\n"));
	pthread_mutex_lock(&env.died_m);
	pthread_mutex_unlock(&env.died_m);
	clear_env(&env);
	return (0);
}
