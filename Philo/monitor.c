/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:38:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/17 00:11:43 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_monitor(t_list **list, int ac)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		pthread_mutex_lock((*list)->protect);
		if (ac == 6)
		{
			if (!check_finish(list))
				return (0);
		}
		while (i < (*list)->num_philo)
		{
			if (!check_die((ft_gettimeofday() - list[i]->eating), list[i]))
				return (0);
			i++;
		}
		pthread_mutex_unlock((*list)->protect);
		usleep(20);
	}
	return (1);
}

int	handling_errors(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '+')
			j++;
		while (av[i][j])
		{
			if (ft_atoi(av[i]) == 0 || ft_atoi(av[i]) == -1)
				return (0);
			if (av[i][j] == '-' || av[i][j] == '+')
				return (0);
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	if (ac == 5 || ac == 6)
		return (1);
	return (0);
}

void	init_all(t_list **list)
{
	int				i;
	pthread_mutex_t	*print;
	pthread_mutex_t	*protect;

	print = malloc(sizeof(pthread_mutex_t));
	protect = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print, NULL);
	pthread_mutex_init(protect, NULL);
	i = 0;
	while (i < (*list)->num_philo)
	{
		list[i]->left = malloc(sizeof (pthread_mutex_t));
		list[i]->philo = malloc(sizeof(pthread_t));
		list[i]->print = print;
		list[i]->protect = protect;
		list[i]->check = 0;
		list[i]->eating = 0;
		list[i]->eating = ft_gettimeofday();
		list[i]->t_start = ft_gettimeofday();
		pthread_mutex_init(list[i]->left, NULL);
		i++;
	}
}

void	hold_arg(char **av, t_list **list)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		list[i] = malloc(sizeof(t_list));
		list[i]->num_philo = ft_atoi(av[1]);
		list[i]->t_die = ft_atoi(av[2]);
		list[i]->t_eat = ft_atoi(av[3]);
		list[i]->t_sleep = ft_atoi(av[4]);
		list[i]->rep = ft_atoi(av[5]);
		i++;
	}
}
