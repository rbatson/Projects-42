/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:25 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:37 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->env->forks_s);
	display_message(philo, TYPE_FORK);
	sem_wait(philo->env->forks_s);
	display_message(philo, TYPE_FORK);
}

void	eat(t_philo *philo)
{
	sem_wait(philo->sem);
	philo->is_eating = 1;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->env->to_die;
	display_message(philo, TYPE_EAT);
	usleep(philo->env->to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	sem_post(philo->sem);
	sem_post(philo->eat_s);
}

void	clean_forks(t_philo *philo)
{
	display_message(philo, TYPE_SLEEP);
	sem_post(philo->env->forks_s);
	sem_post(philo->env->forks_s);
	usleep(philo->env->to_sleep * 1000);
}

static char	*get_message(int type)
{
	if (type == TYPE_EAT)
		return (" is eating\n");
	else if (type == TYPE_SLEEP)
		return (" is sleeping\n");
	else if (type == TYPE_FORK)
		return (" has taken a fork\n");
	else if (type == TYPE_THINK)
		return (" is thinking\n");
	else if (type == TYPE_OVER)
		return ("All philosophers ate required number "
			"of times. Simulation is stopped\n");
	return (" died\n");
}

void	display_message(t_philo *philo, int type)
{
	sem_wait(philo->env->write_s);
	sem_wait(philo->env->died_write_s);
	ft_putnbr_fd(get_time() - philo->env->start, 1);
	write(1, " ", 1);
	if (type != TYPE_OVER)
		ft_putnbr_fd(philo->id + 1, 1);
	write(1, get_message(type), ft_strlen(get_message(type)));
	if (type < TYPE_DIED)
		sem_post(philo->env->died_write_s);
	sem_post(philo->env->write_s);
}
