/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:16 by werrahma          #+#    #+#             */
/*   Updated: 2023/04/09 16:30:52 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft(void *lo)
{
	int i = 0;
	t_list *list;
	list = (t_list*)lo;
	static int count;
	pthread_mutex_lock(list->print);
	list->t_create = ft_gettimeofday();
	pthread_mutex_unlock(list->print);
	while(1)
	{
		pthread_mutex_lock(list->left);
		print_msg("Has Taken a fork", list);
		pthread_mutex_lock(list->right);
		print_msg("Has Taken a fork", list);
		list->check++;
		// printf("%lu\n", check);
		print_msg("is Eating", list);
		pthread_mutex_lock(list->protect);
		list->eating = ft_gettimeofday();
		pthread_mutex_unlock(list->protect);
		fake_usleep(ft_gettimeofday(), list->t_eat);
		// usleep(list->t_eat * 1000);
		pthread_mutex_unlock(list->left);
		pthread_mutex_unlock(list->right);
		print_msg("is Sleeping", list);
		fake_usleep(ft_gettimeofday(), list->t_sleep);
		// usleep(list->t_sleep * 1000);
		print_msg("is thinking", list);
	}
	return(0);
}

int main(int ac, char **av)
{
    t_list **list;
	int i = 0;
	unsigned long check = 0;
	list = malloc(sizeof(t_list*)*ft_atoi(av[1]));
	hold_arg(av, list);
	(*list)->eating = 0;
	int philo;
	pthread_mutex_t *print;
	pthread_mutex_t *protect;
	print = malloc(sizeof(pthread_mutex_t));
	protect = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print, NULL);
	pthread_mutex_init(protect, NULL);
	philo = ft_atoi(av[1]);
    int g= 0;
	while(i < (*list)->fork)
    {
		list[i]->left = malloc(sizeof (pthread_mutex_t));
		list[i]->philo = malloc(sizeof(pthread_t));
		list[i]->print = print;
		list[i]->protect = protect;
		list[i]->check = 0;
		list[i]->eating = 0;
		list[i]->eating = ft_gettimeofday();
        pthread_mutex_init(list[i]->left, NULL);
		i++;
    }
	i = 0;
	while(i < (*list)->fork )
	{
		list[i]->right = list[(1 + i) % philo]->left;
		i++;
	}
    i = 0;
    if(!(*list)->left)
        return(0);
	while(i < (*list)->fork)
	{
		(*(list + i))->id = i;
		i++;
	}
	i = 0;
	while(i < philo)
	{
		pthread_create((list[i]->philo), NULL, &ft, list[i]);
		usleep(100);
		i++;
	}
	i = 0;
	usleep(100);
	while (1)
	{
		i = 0;
		if (ac == 6)
			check_finish(list);
		while(i < philo)
		{
			pthread_mutex_lock(protect);
			if(!check_die((ft_gettimeofday() - list[i]->eating), (*list)->t_die, i, list[i]))
				return (0);
			pthread_mutex_unlock(protect);
			i++;
		}
		usleep(20);
	}
	i = 0;
	while(i < philo)
		pthread_join(*list[i++]->philo, NULL);
}

