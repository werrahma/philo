/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:30:37 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/09 16:30:43 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_arg(char **av, t_list **list)
{
	int i;

	i = 0;
	while(i < ft_atoi(av[1]))
	{
		list[i] = malloc(sizeof(t_list));
		list[i]->fork = ft_atoi(av[1]);
		list[i]->t_die = ft_atoi(av[2]);
		list[i]->t_eat = ft_atoi(av[3]);
		list[i]->t_sleep = ft_atoi(av[4]);
		list[i]->rep = ft_atoi(av[5]);
		i++;
	}
}

void	check_finish(t_list **list)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(i < (*list)->fork)
	{
		if (list[i]->check >= list[i]->rep)
			count++;
		i++;
	}
	if (count == (*list)->fork)
	{
		printf("finish\n");
		exit(0);
	}
}
unsigned long	ft_gettimeofday(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	// printf("hi%lu\n", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	fake_usleep(unsigned long new_time, unsigned long time_sleeping)
{
	while(ft_gettimeofday() - new_time <  time_sleeping)
		usleep(10);
}
int	check_die(unsigned long	eating, unsigned long dying, int philo, t_list *list)
{
	if(dying <= eating)
	{
		pthread_mutex_lock(list->print);
		printf("time %lu philo %d died\n", dying, philo +  1);
		return(0);
	}
	return (1);
}

void print_msg(char *str, t_list *list)
{
	pthread_mutex_lock(list->print);
	printf("time %lu\t%lu \t %s\n", ft_gettimeofday() - list->t_create, list->id + 1, str);
	pthread_mutex_unlock(list->print);
	
}