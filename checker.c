/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:30:37 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/11 16:06:28 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_finish(t_list **list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock((*list)->print);
	while (i < (*list)->num_philo)
	{
		if (list[i]->check >= list[i]->rep)
			count++;
		i++;
	}
	pthread_mutex_unlock((*list)->print);
	if (count == (*list)->num_philo)
	{
		pthread_mutex_lock((*list)->print);
		printf("finish\n");
		return (0);
	}
	return (1);
}

unsigned long	ft_gettimeofday(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	fake_usleep(unsigned long new_time, unsigned long time_sleeping)
{
	while (ft_gettimeofday() - new_time < time_sleeping)
		usleep(10);
}

int	check_die(unsigned long eating, t_list *list)
{
	if (list->t_die <= eating)
	{
		pthread_mutex_lock(list->print);
		printf("time %lu philo %lu died\n", list->t_die, list->id + 1);
		return (0);
	}
	return (1);
}

void	print_msg(char *str, t_list *list)
{
	pthread_mutex_lock(list->print);
	printf("time %lu\t%lu \t %s\n", ft_gettimeofday() - list->t_create,
		list->id + 1, str);
	pthread_mutex_unlock(list->print);
}
